#ifndef COLORWHEELCONTROLLER_H
#define COLORWHEELCONTROLLER_H

#include "Color.h"

#include <QObject>

class ColorWheelController : public QObject
{
    Q_OBJECT
public:
    explicit ColorWheelController(QObject *parent = nullptr);

signals:
    void clicked(Color color);
    void moved(Color color);

public slots:
};

#endif // COLORWHEELCONTROLLER_H
