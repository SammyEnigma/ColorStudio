#ifndef LOCKCOLORCONSTRAINT_H
#define LOCKCOLORCONSTRAINT_H

#include "Constraint.h"

#include <QSharedPointer>

class Color;

class LockColorConstraint : public Constraint
{
public:
    LockColorConstraint();

    QSharedPointer<Color> color() const;
    void setColor(const QSharedPointer<Color>& color);

    bool isHueLocked() const;
    void setIsHueLocked(bool isHueLocked);

    bool isSaturationLocked() const;
    void setIsSaturationLocked(bool isSaturationLocked);

    bool isBrightnessLocked() const;
    void setIsBrightnessLocked(bool isBrightnessLocked);

    virtual void update() const override;

private:
    QSharedPointer<Color> m_color;

    QSharedPointer<Color> m_savedColor;

    bool m_isHueLocked;
    bool m_isSaturationLocked;
    bool m_isBrightnessLocked;
};

#endif // LOCKCOLORCONSTRAINT_H
