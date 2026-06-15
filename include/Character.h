#pragma once

#include "GameObject.h"

class Character : public GameObject
{
public:

    void move(float dx, float dy);

    void applyGravity(float deltaTime);

protected:

    sf::Vector2f velocity;

    float gravity = 1800.f;

    bool onGround = false;
};