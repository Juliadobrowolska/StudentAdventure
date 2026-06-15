#pragma once
#include <SFML/Graphics.hpp>

// Base class for all objects in the game to allow polymorphic storage
class GameObject {
public:
    // Virtual destructor to ensure correct cleanup of derived classes
    virtual ~GameObject() = default;

    // Pure virtual method for updating object logic
    virtual void update(float deltaTime) = 0;

    // Pure virtual method for rendering the object
    virtual void draw(sf::RenderWindow& window) = 0;

    // Pure virtual method to get the collision boundary
    virtual sf::FloatRect getBounds() const = 0;

protected:
    // Position of the object in the game world
    sf::Vector2f position{0.f, 0.f};
};