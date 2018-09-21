#include "Color.h"
#include "HueRelationshipConstraint.h"

class HueRelationshipConstraintPrivate
{
public:
    QList<double> savedHueValues;
};

HueRelationshipConstraint::HueRelationshipConstraint() :
    m_d(new HueRelationshipConstraintPrivate())
{
}

QList<QSharedPointer<Color>> HueRelationshipConstraint::colors() const
{
    return m_colors;
}

void HueRelationshipConstraint::addColor(QSharedPointer<Color> color)
{
    if (!m_colors.contains(color))
    {
        m_colors.append(color);
        m_d->savedHueValues.append(color->hue());
    }
}

void HueRelationshipConstraint::removeColor(QSharedPointer<Color> color)
{
    m_colors.removeAll(color);
}

void HueRelationshipConstraint::update() const
{
    int baseColorIndex = m_colors.indexOf(baseColor());

    if (baseColorIndex == -1)
        return;

    double baseColorSavedHue = m_d->savedHueValues.at(baseColorIndex);

    for (int colorIndex = 0; colorIndex < m_colors.size(); ++ colorIndex)
    {
        if (colorIndex == baseColorIndex)
            continue;

        QSharedPointer<Color> color = m_colors.at(colorIndex);
        double savedHue = m_d->savedHueValues.at(colorIndex);

        double newHue = baseColor()->hue() + savedHue - baseColorSavedHue;
        if (newHue < 0.0)
            newHue += 360.0;
        else if (newHue > 360.0)
            newHue -= 360.0;

        color->setHue(newHue);
    }

    m_d->savedHueValues.clear();
    for (QSharedPointer<Color> color : m_colors)
        m_d->savedHueValues.append(color->hue());
}
