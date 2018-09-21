#ifndef COLORWHEELVIEWMODEL_H
#define COLORWHEELVIEWMODEL_H

#include <QColor>
#include <QObject>
#include <QSharedPointer>

class Color;
class ColorPresenter;
class Constraints;
class Swatches;

class ColorWheelViewModel : public QObject
{
    Q_OBJECT

public:
    ColorWheelViewModel(QObject* parent = nullptr);
    virtual ~ColorWheelViewModel() override = default;

    int countOfColors() const;
    QPoint colorPos(int colorIndex) const;
    QColor qtColor(int colorIndex) const;
    bool isSelected(int colorIndex) const;

    void selectColor(int colorIndex);

    void setSwatches(const QSharedPointer<Swatches>& swatches);

    void moveSelectedColorTo(QColor color);

    void setColorWheelSize(int centerX, int centerY, double radius);

    void setConstraints(const QSharedPointer<Constraints>& constraints);

signals:
    void colorAdded(QColor color);
    void resetted();
    void selectedColorIndexChanged(int index);

    void ithColorWasChangedTo(int colorNumber, QColor oldColor, QColor newColor);

    void updated();

private:
    QSharedPointer<Swatches> m_swatches;
    QSharedPointer<ColorPresenter> m_colorPresenter;
    QSharedPointer<Color> m_selectedColor;
    QSharedPointer<Constraints> m_constraints;
};

#endif // COLORWHEELVIEWMODEL_H
