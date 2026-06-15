#pragma once
#include "GameObject.h"

class Platform : public GameObject {
public:
    // Constructor initializes platform position and dimensions
    Platform(float x, float y, float width, float height);
    
    // Required overrides from GameObject
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;

private:
    sf::RectangleShape shape;
};