#pragma once

#include "Character.h"

class Student : public Character
{
public:
    Student();

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;

    void addECTS(int amount);
    void addStress(int amount);
    void activateCoffeeBoost();

    int getECTS() const;
    int getStress() const;

    // NOWE METODY
    bool getIsCrouching() const; // Pozwoli pociskom sprawdzić, czy Mario kuca
    void die();                  // Wywoływane przy śmierci
    bool isAlive() const;        // Czy gracz żyje
    void reset();                // Reset stanu gracza po restarcie gry

private:
    sf::RectangleShape body;
    sf::CircleShape head;
    sf::RectangleShape backpack;

    float moveSpeed = 300.f;
    float jumpForce = -700.f;

    int ectsPoints = 0;
    int stressLevel = 0;

    bool coffeeBoost = false;
    float coffeeTimer = 0.f;

    // NOWE ZMIENNE
    bool isCrouching = false;
    bool alive = true;
};