#pragma once

#include "Collectible.h"

class ECTS : public Collectible
{
public:

    ECTS(float x, float y);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const override;

    void collect() override;

private:

    sf::CircleShape coin;

    float animationTimer = 0.f;
};