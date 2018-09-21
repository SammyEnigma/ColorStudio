#include "Color.h"
#include "SaturationRelationshipConstraint.h"

class SaturationRelationshipConstraintPrivate
{
public:
    QList<double> savedSaturationValues;
};

SaturationRelationshipConstraint::SaturationRelationshipConstraint() :
    m_d(new SaturationRelationshipConstraintPrivate())
{
}

QList<QSharedPointer<Color>> SaturationRelationshipConstraint::colors() const
{
    return m_colors;
}

void SaturationRelationshipConstraint::addColor(QSharedPointer<Color> color)
{
    if (!m_colors.contains(color))
    {
        m_colors.append(color);
        m_d->savedSaturationValues.append(color->saturation());
    }
}

void SaturationRelationshipConstraint::removeColor(QSharedPointer<Color> color)
{
    m_colors.removeAll(color);
}

void SaturationRelationshipConstraint::update() const
{
    int baseColorIndex = m_colors.indexOf(baseColor());

    if (baseColorIndex == -1)
        return;

    double baseColorSavedSaturation = m_d->savedSaturationValues.at(baseColorIndex);

    for (int colorIndex = 0; colorIndex < m_colors.size(); ++ colorIndex)
    {
        if (colorIndex == baseColorIndex)
            continue;

        QSharedPointer<Color> color = m_colors.at(colorIndex);
        double savedSaturation = m_d->savedSaturationValues.at(colorIndex);

        color->setSaturation(baseColor()->saturation() + savedSaturation - baseColorSavedSaturation);
    }

    m_d->savedSaturationValues.clear();
    for (QSharedPointer<Color> color : m_colors)
        m_d->savedSaturationValues.append(color->saturation());
}
