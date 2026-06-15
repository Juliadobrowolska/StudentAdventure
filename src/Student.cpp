#include "Student.h"

Student::Student()
{
    body.setSize({50.f, 70.f});
    body.setFillColor(sf::Color(120,120,255));

    head.setRadius(20.f);
    head.setFillColor(sf::Color(255,220,177));

    backpack.setSize({18.f,40.f});
    backpack.setFillColor(sf::Color(70,70,70));

    position = {100.f,550.f};
}

void Student::update(float deltaTime)
{
    velocity.x = 0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        velocity.x = -moveSpeed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        velocity.x = moveSpeed;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && onGround)
    {
        velocity.y = jumpForce;
        onGround = false;
    }

    if(coffeeBoost)
    {
        coffeeTimer -= deltaTime;

        moveSpeed = 450.f;

        if(coffeeTimer <= 0.f)
        {
            coffeeBoost = false;
            moveSpeed = 300.f;
        }
    }

    applyGravity(deltaTime);

    position += velocity * deltaTime;

    if(position.y > 550.f)
    {
        position.y = 550.f;
        velocity.y = 0.f;
        onGround = true;
    }
}

void Student::draw(sf::RenderWindow& window)
{
    body.setPosition(position);

    head.setPosition({
        position.x + 5.f,
        position.y - 30.f
    });

    backpack.setPosition({
        position.x - 10.f,
        position.y + 15.f
    });

    window.draw(backpack);
    window.draw(body);
    window.draw(head);
}

sf::FloatRect Student::getBounds() const
{
    return body.getGlobalBounds();
}

void Student::addECTS(int amount)
{
    ectsPoints += amount;
}

void Student::addStress(int amount)
{
    stressLevel += amount;
}

void Student::activateCoffeeBoost()
{
    coffeeBoost = true;
    coffeeTimer = 5.f;
}

int Student::getECTS() const
{
    return ectsPoints;
}

int Student::getStress() const
{
    return stressLevel;
}