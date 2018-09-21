#ifndef SWATCHES_H
#define SWATCHES_H

#include <QList>
#include <QSharedPointer>

class Color;

class Swatches
{
public:
    Swatches();

    void addColor(QSharedPointer<Color> color);
    QList<QSharedPointer<Color>> colors() const;
    void removeColor(QSharedPointer<Color> color);

private:
    QList<QSharedPointer<Color>> m_colors;
};

#endif // SWATCHES_H
