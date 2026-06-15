#include "Platform.h"

Platform::Platform(
    float x,
    float y,
    float width,
    float height)
{
    position = {x,y};

    shape.setPosition(position);

    shape.setSize({width,height});

    shape.setFillColor(sf::Color(90,60,40));
}

void Platform::update(float)
{
}

void Platform::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::FloatRect Platform::getBounds() const
{
    return shape.getGlobalBounds();
}