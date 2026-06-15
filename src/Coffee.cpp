#include "../include/Coffee.h"

// Implementacja konstruktora inicjalizująca geometrię obiektu
Coffee::Coffee(float x, float y) {
    position = {x, y};
    shape.setSize({30.f, 30.f});
    shape.setFillColor(sf::Color(165, 42, 42)); // Kodowanie koloru kawy
    shape.setPosition(position);
}

void Coffee::update(float deltaTime) {
    // Obiekt Coffee jest statyczny; brak logiki aktualizacji
}

void Coffee::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Coffee::getBounds() const {
    return shape.getGlobalBounds();
}