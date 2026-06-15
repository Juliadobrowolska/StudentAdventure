#include "Character.h"

void Character::move(float dx, float dy)
{
    position.x += dx;
    position.y += dy;
}

void Character::applyGravity(float deltaTime)
{
    velocity.y += gravity * deltaTime;
}