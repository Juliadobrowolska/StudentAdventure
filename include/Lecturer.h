#pragma once

#include "Enemy.h"

class Lecturer : public Enemy
{
public:

    Lecturer(float x, float y);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const override;

    void attack() override;

private:

    sf::RectangleShape body;

    sf::CircleShape head;

    float speed = 120.f;
};