#include "ColorWheelBackgroundImage.h"

QImage ColorWheelBackgroundImage::make(qreal sideSize)
{
    qreal wheelRadius = sideSize / 2.0;
    QImage bgImg(sideSize, sideSize, QImage::Format_ARGB32);

    for (int x = - wheelRadius; x < wheelRadius; ++ x)
    {
        for (int y = - wheelRadius; y < wheelRadius; ++ y)
        {
            qreal radius = sqrt(x * x + y * y);

            qreal pixelX = wheelRadius + x;
            qreal pixelY = wheelRadius + y;

            if (radius > wheelRadius)// || radius < wheelRadius - 10)
            {
                bgImg.setPixelColor(pixelX, pixelY, QColor(30, 30, 30));
                continue;
            }

            qreal angle = acos(x / radius);
            if (y < 0.0)
                angle = 3.14 * 2 - angle;

            qreal hue = angle / 3.14 / 2;
            if (hue < 0.0)
                hue = 0.0;
            else if (hue > 1.0)
                hue = 1.0;

            qreal saturation = radius / wheelRadius;
            if (saturation < 0.0)
                saturation = 0.0;
            else if (saturation > 1.0)
                saturation = 1.0;

            QColor color = QColor::fromHsvF(hue, saturation, 1.0);

            bgImg.setPixelColor(pixelX, pixelY, color);
        }
    }

    return bgImg;
}
