#pragma once
#include "GameObject.h"

class Coffee : public GameObject {
public:
    // Constructor sets the position
    Coffee(float x, float y);

    // Overridden virtual methods
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;

private:
    sf::RectangleShape shape;
};