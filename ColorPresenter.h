#ifndef COLORPRESENTER_H
#define COLORPRESENTER_H

#include <QColor>
#include <QPoint>
#include <QSharedPointer>

class Color;

class ColorPresenter
{
public:
    int x() const;
    int y() const;
    QPoint pos() const;
    QColor qtColor() const;

    void setColor(const QSharedPointer<Color>& qtColor);

    void setWheelRadius(double wheelRadius);
    void setWheelCenter(const QPoint& wheelCenter);

private:
    double angle() const;
    double radius() const;

    QSharedPointer<Color> m_color;

    double m_wheelRadius;
    QPoint m_wheelCenter;
};

#endif // COLORPRESENTER_H
