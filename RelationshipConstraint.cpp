#include "RelationshipConstraint.h"

QSharedPointer<Color> RelationshipConstraint::baseColor() const
{
    return m_baseColor;
}

void RelationshipConstraint::setBaseColor(const QSharedPointer<Color>& selectedColor)
{
    m_baseColor = selectedColor;
}
