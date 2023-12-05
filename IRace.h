#pragma once

class IRace
{
public:
    IRace(int HitPoints, int AttackPoints, int DefensePoints) : m_HitPointsMod(HitPoints),
    m_AttackPointsMod(AttackPoints), m_DefensePointsMod(DefensePoints) {} //Race template constructor to initialize modifiers for Hit, Attack, and Defense with use defined specified race classes
    //Getters for HitPoint, AttackPoint, and DefensePoint
    virtual int GetHitPointsMod() { return m_HitPointsMod; }
    virtual int GetAttackPointsMod() { return m_AttackPointsMod; }
    virtual int GetDefensePointsMod() { return m_DefensePointsMod; }

    ~IRace() {}
protected:
    int m_HitPointsMod;
    int m_AttackPointsMod;
    int m_DefensePointsMod;
};