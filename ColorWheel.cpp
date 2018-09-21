#include "ColorWheel.h"
#include "ColorWheelBackgroundImage.h"
#include "ColorWheelCoordinateConverter.h"
#include "ColorWheelViewModel.h"

#include <QDebug>
#include <QPaintEvent>
#include <QPainter>

ColorWheel::ColorWheel(QWidget* parent) :
    QWidget(parent),
    m_isLeftMouseButtonPressed(false),
    m_padding(24),
    m_coordinateConverter(new ColorWheelCoordinateConverter())
{
}

void ColorWheel::setViewModel(const QSharedPointer<ColorWheelViewModel>& viewModel)
{
    if (!m_viewModel.isNull())
        m_viewModel->disconnect();

    m_viewModel = viewModel;

    if (viewModel.isNull())
        return;

    connect(m_viewModel.data(), &ColorWheelViewModel::updated,
            this, [=]{ this->repaint(); });
}

void ColorWheel::paintEvent(QPaintEvent* event)
{
    event->accept();

    if (m_viewModel.isNull())
        return;

    m_viewModel->setColorWheelSize(wheelCenterX(), wheelCenterY(), wheelRadius());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Fill dark background
    painter.fillRect(rect(), QColor(30, 30, 30));

    // Draw color wheel
    painter.drawImage(wheelCenterX() - wheelRadius(), wheelCenterY() - wheelRadius(),
                      ColorWheelBackgroundImage::make(wheelRadius() * 2.0));

    // Draw colors
    for (int colorIndex = 0; colorIndex < m_viewModel->countOfColors(); ++ colorIndex)
    {
        QColor color = m_viewModel->qtColor(colorIndex);
        QPoint pos = m_viewModel->colorPos(colorIndex);

        // calculate parameters
        qreal hue, saturation, value;
        color.getHsvF(&hue, &saturation, &value);

        // draw feather
        QPainterPath featherPath;
        featherPath.moveTo(wheelCenterX(), wheelCenterY());

        qreal angle = hue * 3.14 * 2;
        qreal radius = saturation * wheelRadius();

        qreal featherAngleDelta = 1000.0 / radius / 180.0 * 3.14;

        featherPath.lineTo(wheelCenterX() + radius * cos(angle - featherAngleDelta),
                           wheelCenterY() + radius * sin(angle - featherAngleDelta));
        featherPath.lineTo(wheelCenterX() + radius * cos(angle + featherAngleDelta),
                           wheelCenterY() + radius * sin(angle + featherAngleDelta));
        featherPath.closeSubpath();

        painter.setPen(featherColor());
        painter.setBrush(featherColor());
        painter.fillPath(featherPath, featherColor());
        painter.drawEllipse(pos.x() - colorCircleRadius() * 1.5,
                            pos.y() - colorCircleRadius() * 1.5,
                            colorCircleDiameter() * 1.5, colorCircleDiameter() * 1.5);
        if (m_viewModel->isSelected(colorIndex))
        {
            QPen pen;
            pen.setColor(color.darker());
            pen.setWidth(2);
            painter.setPen(pen);
            painter.drawEllipse(pos.x() - colorCircleRadius() * 1.5,
                                pos.y() - colorCircleRadius() * 1.5,
                                colorCircleDiameter() * 1.5, colorCircleDiameter() * 1.5);
        }

        // draw color circle
        painter.setPen(color);
        painter.setBrush(color);
        painter.drawEllipse(pos, colorCircleRadius(), colorCircleRadius());
    }
}

void ColorWheel::mousePressEvent(QMouseEvent* event)
{
    event->accept();

    if (m_viewModel.isNull())
        return;

    int index = colorIndexUnder(event->pos().x(), event->pos().y());
    if (index >= 0)
    {
        m_isLeftMouseButtonPressed = true;
        m_viewModel->selectColor(index);
    }
}

void ColorWheel::mouseReleaseEvent(QMouseEvent* event)
{
    if (m_isLeftMouseButtonPressed)
    {
        event->accept();
        m_isLeftMouseButtonPressed = false;
        return;
    }

    QWidget::mouseReleaseEvent(event);
}

void ColorWheel::mouseMoveEvent(QMouseEvent* event)
{
    if (m_isLeftMouseButtonPressed)
    {
        event->accept();
        QColor colorUnderMouse = wheelColorFor(event->x(), event->y());
        if (colorUnderMouse.isValid())
            m_viewModel->moveSelectedColorTo(colorUnderMouse);
        return;
    }

    QWidget::mouseMoveEvent(event);
}

qreal ColorWheel::wheelCenterX() const
{
    return width() / 2.0;
}

qreal ColorWheel::wheelCenterY() const
{
    return height() / 2.0;
}

qreal ColorWheel::wheelRadius() const
{
    return qMin(width(), height()) / 2.0 - padding();
}

qreal ColorWheel::padding() const
{
    return m_padding;
}

qreal ColorWheel::colorCircleDiameter() const
{
    return 24;
}

int ColorWheel::colorCircleRadius() const
{
    return colorCircleDiameter() / 2.0;
}

QColor ColorWheel::featherColor() const
{
    return QColor(255, 255, 255, 128);
}

int ColorWheel::colorIndexUnder(qreal x, qreal y)
{
    if (m_viewModel.isNull())
        return -1;

    for (int colorIndex = 0; colorIndex < m_viewModel->countOfColors(); ++ colorIndex)
    {
        QPoint pos = m_viewModel->colorPos(colorIndex);

        qreal dx = x - pos.x();
        qreal dy = y - pos.y();

        if (sqrt(dx * dx + dy * dy) < colorCircleRadius())
            return colorIndex;
    }

    return -1;
}

QColor ColorWheel::wheelColorFor(qreal x, qreal y)
{
    m_coordinateConverter->setWheelCenterX(wheelCenterX());
    m_coordinateConverter->setWheelCenterY(wheelCenterY());
    m_coordinateConverter->setWheelRadius(wheelRadius());

    qreal radius, angle;
    m_coordinateConverter->xyToAr(x, y, &angle, &radius);

    if (radius > wheelRadius())
        return QColor();

    qreal hue = angle / 3.14 / 2;
    if (hue < 0.0)
        hue = 0.0;
    else if (hue > 1.0)
        hue = 1.0;

    qreal saturation = radius / wheelRadius();
    if (saturation < 0.0)
        saturation = 0.0;
    else if (saturation > 1.0)
        saturation = 1.0;

    return QColor::fromHsvF(hue, saturation, 1.0);
}
