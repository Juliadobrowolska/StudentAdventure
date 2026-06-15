#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Lecturer : public GameObject {
public:
    Lecturer(float x, float y);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;

private:
    sf::RectangleShape body;
    sf::CircleShape head;
    bool isShooter;
    float attackTimer;
};