#include "Color.h"
#include "ColorPresenter.h"
#include "ColorWheelViewModel.h"
#include "Constraints.h"
#include "Swatches.h"

#include <QColor>

ColorWheelViewModel::ColorWheelViewModel(QObject *parent) :
    QObject(parent),
    m_colorPresenter(new ColorPresenter())
{
}

int ColorWheelViewModel::countOfColors() const
{
    if (m_swatches == nullptr)
        return 0;

    return m_swatches->colors().size();
}

QPoint ColorWheelViewModel::colorPos(int colorIndex) const
{
    if (m_swatches == nullptr)
        return QPoint();

    if (colorIndex < 0 || colorIndex >= countOfColors())
        return QPoint();

    m_colorPresenter->setColor(m_swatches->colors().at(colorIndex));
    return m_colorPresenter->pos();
}

QColor ColorWheelViewModel::qtColor(int colorIndex) const
{
    if (m_swatches == nullptr)
        return QColor();

    if (colorIndex < 0 || colorIndex >= countOfColors())
        return QColor();

    m_colorPresenter->setColor(m_swatches->colors().at(colorIndex));
    return m_colorPresenter->qtColor();
}

bool ColorWheelViewModel::isSelected(int colorIndex) const
{
    if (m_swatches == nullptr)
        return false;

    if (colorIndex < 0 || colorIndex >= countOfColors())
        return false;

    return m_swatches->colors().at(colorIndex) == m_selectedColor;
}

void ColorWheelViewModel::moveSelectedColorTo(QColor color)
{
    m_selectedColor->setHue(color.hueF() * Color::maxHue());
    m_selectedColor->setSaturation(color.saturationF() * Color::maxSaturation());
    m_selectedColor->setBrightness(color.valueF() * Color::maxBrightness());

    m_constraints->setSelectedColor(m_selectedColor);
    m_constraints->updateAll();

    emit updated();
}

void ColorWheelViewModel::setColorWheelSize(int centerX, int centerY, double radius)
{
    m_colorPresenter->setWheelCenter(QPoint(centerX, centerY));
    m_colorPresenter->setWheelRadius(radius);
}

void ColorWheelViewModel::setConstraints(const QSharedPointer<Constraints>& constraints)
{
    m_constraints = constraints;
}

void ColorWheelViewModel::setSwatches(const QSharedPointer<Swatches>& swatches)
{
    m_swatches = swatches;
}

void ColorWheelViewModel::selectColor(int colorIndex)
{
    if (m_swatches == nullptr)
        return;

    if (colorIndex < 0 || colorIndex >= countOfColors())
        return;

    m_selectedColor = m_swatches->colors().at(colorIndex);

    emit selectedColorIndexChanged(colorIndex);
}
