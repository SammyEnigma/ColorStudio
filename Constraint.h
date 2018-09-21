#ifndef CONSTRAINT_H
#define CONSTRAINT_H

class Constraint
{
public:
    virtual ~Constraint() = default;
    virtual void update() const = 0;
};

#endif // CONSTRAINT_H
