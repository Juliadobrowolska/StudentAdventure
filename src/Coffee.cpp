#include "Coffee.h"

#include <cmath>

Coffee::Coffee(float x,float y)
{
    position = {x,y};

    cup.setRadius(18.f);

    cup.setFillColor(sf::Color(120,70,20));
}

void Coffee::update(float deltaTime)
{
    animationTime += deltaTime;

    float scale =
        1.f + std::sin(animationTime * 5.f) * 0.1f;

    cup.setScale({scale,scale});
}

void Coffee::draw(sf::RenderWindow& window)
{
    if(!collected)
    {
        cup.setPosition(position);

        window.draw(cup);
    }
}

sf::FloatRect Coffee::getBounds() const
{
    return cup.getGlobalBounds();
}

void Coffee::collect()
{
    collected = true;
}