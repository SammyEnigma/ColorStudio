#include "Swatches.h"

Swatches::Swatches()
{

}

void Swatches::addColor(QSharedPointer<Color> color)
{
    m_colors.append(color);
}

QList<QSharedPointer<Color> > Swatches::colors() const
{
    return m_colors;
}

void Swatches::removeColor(QSharedPointer<Color> color)
{
    m_colors.removeAll(color);
}
