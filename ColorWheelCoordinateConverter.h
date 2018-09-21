#ifndef COLORWHEELCOORDINATECONVERTER_H
#define COLORWHEELCOORDINATECONVERTER_H

class ColorWheelCoordinateConverter
{
public:
    ColorWheelCoordinateConverter();

    void setWheelRadius(double wheelRadius);

    void setWheelCenterX(double wheelCenterX);
    void setWheelCenterY(double wheelCenterY);

    void xyToAr(double x, double y, double* angle = nullptr, double* radius = nullptr);
    void arToXY(double angle, double radius, double* x = nullptr, double* y = nullptr);

private:
    double m_wheelRadius;
    double m_wheelCenterX;
    double m_wheelCenterY;
};

#endif // COLORWHEELCOORDINATECONVERTER_H
