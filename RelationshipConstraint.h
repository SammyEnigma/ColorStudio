#ifndef RELATIONSHIPCONSTRAINT_H
#define RELATIONSHIPCONSTRAINT_H

#include "Constraint.h"

#include <QSharedPointer>

class Color;

class RelationshipConstraint : public Constraint
{
public:
    QSharedPointer<Color> baseColor() const;
    void setBaseColor(const QSharedPointer<Color>& baseColor);

private:
    QSharedPointer<Color> m_baseColor;
};

#endif // RELATIONSHIPCONSTRAINT_H
