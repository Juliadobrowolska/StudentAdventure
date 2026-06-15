#include "Lecturer.h"

Lecturer::Lecturer(float x, float y)
{
    position = {x,y};

    startX = x;

    body.setSize({50.f,80.f});
    body.setFillColor(sf::Color(120,20,20));

    head.setRadius(20.f);
    head.setFillColor(sf::Color(255,220,177));
}

void Lecturer::update(float deltaTime)
{
    if(movingRight)
    {
        position.x += speed * deltaTime;

        if(position.x > startX + patrolDistance)
            movingRight = false;
    }
    else
    {
        position.x -= speed * deltaTime;

        if(position.x < startX - patrolDistance)
            movingRight = true;
    }
}

void Lecturer::draw(sf::RenderWindow& window)
{
    body.setPosition(position);

    head.setPosition({
        position.x + 5.f,
        position.y - 30.f
    });

    window.draw(body);
    window.draw(head);
}

sf::FloatRect Lecturer::getBounds() const
{
    return body.getGlobalBounds();
}

void Lecturer::attack()
{
}