#include "ECTS.h"

#include <cmath>

ECTS::ECTS(float x,float y)
{
    position = {x,y};

    coin.setRadius(15.f);

    coin.setFillColor(sf::Color(255,220,0));
}

void ECTS::update(float deltaTime)
{
    animationTimer += deltaTime;

    position.y +=
        std::sin(animationTimer * 3.f)
        * 20.f
        * deltaTime;
}

void ECTS::draw(sf::RenderWindow& window)
{
    if(!collected)
    {
        coin.setPosition(position);

        window.draw(coin);
    }
}

sf::FloatRect ECTS::getBounds() const
{
    return coin.getGlobalBounds();
}

void ECTS::collect()
{
    collected = true;
}