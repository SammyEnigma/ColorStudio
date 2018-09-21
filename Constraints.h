#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include <QList>
#include <QSharedPointer>

class Color;
class Constraint;

class Constraints
{
public:
    Constraints();

    QList<QSharedPointer<Constraint>> constraints() const;

    void addConstraint(QSharedPointer<Constraint> constraint);

    void removeConstraint(QSharedPointer<Constraint> constraint);

    void updateAll() const;

    void setSelectedColor(const QSharedPointer<Color>& selectedColor);

private:
    QList<QSharedPointer<Constraint>> m_constraints;
};

#endif // CONSTRAINTS_H
