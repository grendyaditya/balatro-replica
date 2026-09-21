#ifndef DAMAGE_RULE_H
#define DAMAGE_RULE_H

using namespace std;

class IDamageRule
{
public:
    virtual ~IDamageRule() = default;
    virtual int CalculateDamage(bool correct) = 0;
};

class SimpleDamageRule : public IDamageRule
{
public:
    int CalculateDamage(bool correct) override;
};

#endif