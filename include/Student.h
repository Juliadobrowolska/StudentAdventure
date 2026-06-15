#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Student : public Character {
public:
    Student();
    
    // Nadpisane metody
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;

    // Sterowanie i fizyka
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f pos);
    float getVelocityY() const;
    void setVelocityY(float vel);
    void jump();
    void setGrounded(bool grounded);
    void setCrouching(bool crouch);
    bool getIsCrouching() const;

    // Logika gry
    void die();
    bool isAlive() const;
    void reset();
    void addECTS(int amount);
    int getECTS() const;
    void addCoffee();
    void takeDamage();

private:
    // Składowe graficzne
    sf::RectangleShape body;
    sf::CircleShape head;
    sf::RectangleShape backpack;
    
    // Składowe fizyki i stanu
    float velocityY;
    bool isGrounded;
    const float gravity = 2500.f;
    bool alive;
    int ectsPoints;
    bool crouching;
    int coffeeCount;
};