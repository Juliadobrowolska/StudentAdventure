#pragma once

#include "Character.h"

class Enemy : public Character
{
public:

    virtual void attack() = 0;

protected:

    bool movingRight = true;

    float patrolDistance = 200.f;

    float startX = 0.f;
};