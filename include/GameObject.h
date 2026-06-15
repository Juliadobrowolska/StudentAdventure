#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:

    virtual ~GameObject() = default;

    virtual void update(float deltaTime) = 0;

    virtual void draw(sf::RenderWindow& window) = 0;

    virtual sf::FloatRect getBounds() const = 0;

protected:

    sf::Vector2f position;
};