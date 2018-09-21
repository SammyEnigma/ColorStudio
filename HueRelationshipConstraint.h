#ifndef HUERELATIONCONSTRAINT_H
#define HUERELATIONCONSTRAINT_H

#include "RelationshipConstraint.h"

#include <QList>

class HueRelationshipConstraintPrivate;

class HueRelationshipConstraint : public RelationshipConstraint
{
public:
    HueRelationshipConstraint();

    QList<QSharedPointer<Color>> colors() const;
    void addColor(QSharedPointer<Color> color);
    void removeColor(QSharedPointer<Color> color);

    virtual void update() const override;

private:
    QList<QSharedPointer<Color>> m_colors;
    QSharedPointer<HueRelationshipConstraintPrivate> m_d;
};

#endif // HUERELATIONCONSTRAINT_H
