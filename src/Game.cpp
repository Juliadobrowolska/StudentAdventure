#include "../include/Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode({800, 600}), "Academic Survival") {
    player = std::make_unique<Student>();
    // Startowa platforma
    gameObjects.push_back(std::make_unique<Platform>(200.f, 500.f, 400.f, 20.f));
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        
        handleInput();
        update(deltaTime);
        render();
    }
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }

    // Sterowanie w czasie rzeczywistym
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        player->move({-300.f * 0.016f, 0.f}); // Upewnij się, że masz metodę move w Student
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        player->move({300.f * 0.016f, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        player->jump();
    }
}

void Game::update(float deltaTime) {
    player->update(deltaTime);
    
    // Prosta logika kolizji: Jeśli postać dotyka platformy -> zatrzymaj
    bool onGround = false;
    for (auto& obj : gameObjects) {
        if (player->getBounds().intersects(obj->getBounds())) {
            // "Wypchnięcie" na górę platformy, jeśli postać spada
            if (player->getVelocityY() > 0) {
                player->setPosition({player->getPosition().x, obj->getBounds().top - 30.f});
                player->setGrounded(true);
                onGround = true;
            }
        }
    }
    if (!onGround) player->setGrounded(false);

    // Generowanie nowych platform (nieskończony bieg)
    if (player->getPosition().x > lastPlatformX - 400.f) {
        spawnChunk(lastPlatformX + 400.f);
    }
}

void Game::spawnChunk(float startX) {
    lastPlatformX = startX;
    // Platforma
    gameObjects.push_back(std::make_unique<Platform>(startX, 450.f, 200.f, 20.f));
    // Wykładowca na platformie
    gameObjects.push_back(std::make_unique<Lecturer>(startX + 100.f, 450.f));
}

void Game::render() {
    window.clear();
    for (auto& obj : gameObjects) obj->draw(window);
    player->draw(window);
    window.display();
}