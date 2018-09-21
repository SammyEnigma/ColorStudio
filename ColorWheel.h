#ifndef COLORWHEEL_H
#define COLORWHEEL_H

#include "ColorWheelController.h"

#include <QWidget>

class ColorWheelCoordinateConverter;
class ColorWheelViewModel;

class ColorWheel : public QWidget
{
    Q_OBJECT
public:
    explicit ColorWheel(QWidget* parent = nullptr);
    virtual ~ColorWheel() override = default;

    void setViewModel(const QSharedPointer<ColorWheelViewModel>& viewModel);

signals:
    void clicked(Color color);
    void moved(Color color);

public slots:

protected:
    virtual void paintEvent(QPaintEvent* event) override;

    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;

private:
    qreal wheelCenterX() const;
    qreal wheelCenterY() const;
    qreal wheelRadius() const;
    qreal padding() const;
    qreal colorCircleDiameter() const;
    int colorCircleRadius() const;
    QColor featherColor() const;

    int colorIndexUnder(qreal x, qreal y);

    QColor wheelColorFor(qreal x, qreal y);

    QSharedPointer<ColorWheelViewModel> m_viewModel;

    bool m_isLeftMouseButtonPressed;

    qreal m_padding;

    QSharedPointer<ColorWheelCoordinateConverter> m_coordinateConverter;
};

#endif // COLORWHEEL_H
