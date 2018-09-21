#ifndef SATURATIONRELATIONSHIPCONSTRAINT_H
#define SATURATIONRELATIONSHIPCONSTRAINT_H

#include "RelationshipConstraint.h"

#include <QList>

class SaturationRelationshipConstraintPrivate;

class SaturationRelationshipConstraint : public RelationshipConstraint
{
public:
    SaturationRelationshipConstraint();

    QList<QSharedPointer<Color>> colors() const;
    void addColor(QSharedPointer<Color> color);
    void removeColor(QSharedPointer<Color> color);

    virtual void update() const override;

private:
    QList<QSharedPointer<Color>> m_colors;
    QSharedPointer<SaturationRelationshipConstraintPrivate> m_d;
};

#endif // SATURATIONRELATIONSHIPCONSTRAINT_H
