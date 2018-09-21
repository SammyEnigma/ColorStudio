#include "ColorWheelCoordinateConverter.h"

#include <QtMath>

ColorWheelCoordinateConverter::ColorWheelCoordinateConverter() :
    m_wheelRadius(1.0),
    m_wheelCenterX(0.0),
    m_wheelCenterY(0.0)
{
}

void ColorWheelCoordinateConverter::setWheelRadius(double wheelRadius)
{
    m_wheelRadius = wheelRadius;
}

void ColorWheelCoordinateConverter::setWheelCenterX(double wheelCenterX)
{
    m_wheelCenterX = wheelCenterX;
}

void ColorWheelCoordinateConverter::setWheelCenterY(double wheelCenterY)
{
    m_wheelCenterY = wheelCenterY;
}

void ColorWheelCoordinateConverter::xyToAr(double x, double y, double* angle, double* radius)
{
    double dx = x - m_wheelCenterX;
    double dy = y - m_wheelCenterY;

    double r = sqrt(dx * dx + dy * dy);

    double a = acos(dx / r);
    if (dy < 0.0)
        a = 3.14 * 2 - a;

    if (radius != nullptr)
        *radius = r;

    if (angle != nullptr)
        *angle = a;
}

void ColorWheelCoordinateConverter::arToXY(double angle, double radius, double* x, double* y)
{
    if (x != nullptr)
        *x = m_wheelCenterX + radius * cos(angle);

    if (y != nullptr)
        *y = m_wheelCenterY + radius * sin(angle);
}
