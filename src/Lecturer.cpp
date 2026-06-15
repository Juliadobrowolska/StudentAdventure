#include "../include/Lecturer.h"
#include <cstdlib>

// Konstruktor - tutaj inicjalizujemy kształty i ich położenie
Lecturer::Lecturer(float x, float y) {
    // 1. Korpus (prostokąt)
    body.setSize({40.f, 60.f});
    body.setOrigin({20.f, 60.f}); 
    
    // 2. Głowa (koło)
    head.setRadius(15.f);
    head.setOrigin({15.f, 15.f});
    
    // Logika koloru i typu (losowe kolory lub czerwony dla strzelających)
    isShooter = (rand() % 2 == 0);
    
    if (isShooter) {
        body.setFillColor(sf::Color::Red);
        head.setFillColor(sf::Color::Red);
    } else {
        sf::Color randomColor(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
        body.setFillColor(randomColor);
        head.setFillColor(sf::Color::White);
    }
    
    // Ustawienie pozycji początkowej
    body.setPosition({x, y});
    head.setPosition({x, y - 60.f});
    attackTimer = 0.f;
}

// Metoda update - tutaj dbamy o to, by głowa trzymała się ciała
void Lecturer::update(float deltaTime) {
    if (isShooter) {
        attackTimer += deltaTime;
        if (attackTimer >= 2.0f) {
            // Tutaj w przyszłości dodasz logikę pocisków
            attackTimer = 0.f;
        }
    }
    // Synchronizacja pozycji głowy z ciałem
    head.setPosition({body.getPosition().x, body.getPosition().y - 60.f});
}

// Metoda draw - rysuje postać na ekranie
void Lecturer::draw(sf::RenderWindow& window) {
    window.draw(body);
    window.draw(head);
}

// Metoda getBounds - zwraca obszar kolizji korpusu
sf::FloatRect Lecturer::getBounds() const {
    return body.getGlobalBounds();
}