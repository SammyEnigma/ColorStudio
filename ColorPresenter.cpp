#include "Color.h"
#include "ColorPresenter.h"

int ColorPresenter::x() const
{
    return qRound(m_wheelCenter.x() + radius() * cos(angle()));
}

int ColorPresenter::y() const
{
    return qRound(m_wheelCenter.y() + radius() * sin(angle()));
}

QPoint ColorPresenter::pos() const
{
    return QPoint(x(), y());
}

QColor ColorPresenter::qtColor() const
{
    return QColor::fromHsvF(m_color->hue() / Color::maxHue(),
                            m_color->saturation() / Color::maxSaturation(),
                            m_color->brightness() / Color::maxBrightness());
}

void ColorPresenter::setColor(const QSharedPointer<Color>& color)
{
    m_color = color;
}

double ColorPresenter::angle() const
{
    return m_color->hue() / 180.0 * 3.14;
}

double ColorPresenter::radius() const
{
    return m_color->saturation() * m_wheelRadius;
}

void ColorPresenter::setWheelCenter(const QPoint& wheelCenter)
{
    m_wheelCenter = wheelCenter;
}

void ColorPresenter::setWheelRadius(double wheelRadius)
{
    m_wheelRadius = wheelRadius;
}
