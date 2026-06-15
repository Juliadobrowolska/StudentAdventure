#pragma once

#include "GameObject.h"

class Platform : public GameObject
{
public:

    Platform(float x,float y,float width,float height);

    void update(float deltaTime) override;

    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const override;

private:

    sf::RectangleShape shape;
};