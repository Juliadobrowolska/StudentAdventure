#pragma once
#include <SFML/Graphics.hpp>

class Projectile {
public:
    Projectile(float x, float y) {
        shape.setRadius(8.f);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition({x, y});
    }
    void update(float deltaTime) { shape.move({-400.f * deltaTime, 0.f}); } // Leci w lewo
    void draw(sf::RenderWindow& window) { window.draw(shape); }
    sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }
    bool isOffScreen() const { return shape.getPosition().x < -50.f; }

private:
    sf::CircleShape shape;
};