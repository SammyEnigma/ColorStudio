#include "Color.h"
#include "LockColorConstraint.h"

LockColorConstraint::LockColorConstraint() :
    m_isHueLocked(true),
    m_isSaturationLocked(true),
    m_isBrightnessLocked(true)
{
}

QSharedPointer<Color> LockColorConstraint::color() const
{
    return m_color;
}

void LockColorConstraint::setColor(const QSharedPointer<Color>& color)
{
    m_color = color;

    m_savedColor = QSharedPointer<Color>::create(*m_color);
}

bool LockColorConstraint::isHueLocked() const
{
    return m_isHueLocked;
}

void LockColorConstraint::setIsHueLocked(bool isHueLocked)
{
    m_isHueLocked = isHueLocked;
}

bool LockColorConstraint::isSaturationLocked() const
{
    return m_isSaturationLocked;
}

void LockColorConstraint::setIsSaturationLocked(bool isSaturationLocked)
{
    m_isSaturationLocked = isSaturationLocked;
}

bool LockColorConstraint::isBrightnessLocked() const
{
    return m_isBrightnessLocked;
}

void LockColorConstraint::setIsBrightnessLocked(bool isBrightnessLocked)
{
    m_isBrightnessLocked = isBrightnessLocked;
}

void LockColorConstraint::update() const
{
    if (m_color == nullptr || m_savedColor == nullptr)
        return;

    if (m_isHueLocked)
        m_color->setHue(m_savedColor->hue());
    if (m_isSaturationLocked)
        m_color->setSaturation(m_savedColor->saturation());
    if (m_isBrightnessLocked)
        m_color->setBrightness(m_savedColor->brightness());
}
