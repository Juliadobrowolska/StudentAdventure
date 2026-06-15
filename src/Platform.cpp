#include "../include/Platform.h"

// Constructor implementation with 4 parameters
Platform::Platform(float x, float y, float width, float height) {
    position = {x, y};
    shape.setSize({width, height});
    shape.setFillColor(sf::Color(139, 69, 19)); // Brown color for platform
    shape.setPosition(position);
}

void Platform::update(float deltaTime) {
    // Platform is static, no update logic required
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

// Returns the global bounding box for collision detection
sf::FloatRect Platform::getBounds() const {
    return shape.getGlobalBounds();
}