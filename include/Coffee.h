#pragma once

#include "Collectible.h"

class Coffee : public Collectible
{
public:

    Coffee(float x,float y);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const override;

    void collect() override;

private:

    sf::CircleShape cup;

    float animationTime = 0.f;
};