#include "../include/Student.h"

Student::Student() : velocityY(0.f), isGrounded(false), alive(true), 
                     ectsPoints(0), crouching(false), coffeeCount(0) {
    // 1. Korpus
    body.setSize({40.f, 60.f});
    body.setFillColor(sf::Color::Yellow);
    body.setOrigin({20.f, 30.f});
    body.setPosition({100.f, 400.f});
    
    // 2. Głowa
    head.setRadius(20.f);
    head.setFillColor(sf::Color::White);
    head.setOrigin({20.f, 20.f});
    
    // 3. Plecak
    backpack.setSize({20.f, 30.f});
    backpack.setFillColor(sf::Color::Blue);
    backpack.setOrigin({10.f, 15.f});
}

void Student::update(float deltaTime) {
    if (!alive) return;

    if (!isGrounded) {
        velocityY += gravity * deltaTime;
    }
    
    body.move({0.f, velocityY * deltaTime});

    // Synchronizacja pozycji
    head.setPosition({body.getPosition().x, body.getPosition().y - 45.f});
    backpack.setPosition({body.getPosition().x, body.getPosition().y + 5.f});
}

void Student::draw(sf::RenderWindow& window) {
    window.draw(body);
    window.draw(head);
    window.draw(backpack);
}

sf::FloatRect Student::getBounds() const {
    return body.getGlobalBounds();
}

sf::Vector2f Student::getPosition() const {
    return body.getPosition();
}

void Student::setPosition(sf::Vector2f pos) {
    body.setPosition(pos);
}

float Student::getVelocityY() const {
    return velocityY;
}

void Student::setVelocityY(float vel) {
    velocityY = vel;
}

void Student::jump() {
    if (isGrounded) {
        velocityY = -800.f;
        isGrounded = false;
    }
}

void Student::setGrounded(bool grounded) {
    isGrounded = grounded;
    if (isGrounded) velocityY = 0;
}

void Student::setCrouching(bool crouch) { crouching = crouch; }
bool Student::getIsCrouching() const { return crouching; }

void Student::die() { alive = false; }
bool Student::isAlive() const { return alive; }
void Student::reset() { 
    alive = true; 
    body.setPosition({100.f, 400.f}); 
    velocityY = 0; 
    ectsPoints = 0; 
}
void Student::addECTS(int amount) { ectsPoints += amount; }
int Student::getECTS() const { return ectsPoints; }
void Student::addCoffee() { coffeeCount++; }
void Student::takeDamage() { die(); }