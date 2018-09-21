#include "Color.h"
#include "Constraint.h"
#include "Constraints.h"
#include "LockColorConstraint.h"
#include "RelationshipConstraint.h"

Constraints::Constraints()
{

}

QList<QSharedPointer<Constraint>> Constraints::constraints() const
{
    return m_constraints;
}

void Constraints::addConstraint(QSharedPointer<Constraint> constraint)
{
    m_constraints.append(constraint);
}

void Constraints::removeConstraint(QSharedPointer<Constraint> constraint)
{
    m_constraints.removeAll(constraint);
}

void Constraints::updateAll() const
{
    for (QSharedPointer<Constraint> constraint : m_constraints)
    {
        QSharedPointer<LockColorConstraint> lockColorConstraint =
                constraint.dynamicCast<LockColorConstraint>();
        if (lockColorConstraint != nullptr)
            continue;
        constraint->update();
    }

    for (QSharedPointer<Constraint> constraint : m_constraints)
    {
        QSharedPointer<LockColorConstraint> lockColorConstraint =
                constraint.dynamicCast<LockColorConstraint>();
        if (lockColorConstraint != nullptr)
            constraint->update();
    }

//    for (QSharedPointer<Constraint> constraint : m_constraints)
//        constraint->update();
}

void Constraints::setSelectedColor(const QSharedPointer<Color>& selectedColor)
{
    for (QSharedPointer<Constraint> constraint : m_constraints)
    {
        QSharedPointer<RelationshipConstraint> relashionshipConstraint =
                constraint.dynamicCast<RelationshipConstraint>();
        if (relashionshipConstraint != nullptr)
            relashionshipConstraint->setBaseColor(selectedColor);
    }
}
