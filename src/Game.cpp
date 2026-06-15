#include "../include/Game.h"
#include <iostream>
#include <optional>

Game::Game() 
    : window(sf::VideoMode({800, 600}), "Student Adventure")
{
    currentState = GameState::Menu;
    window.setFramerateLimit(60);

    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    scoreText = std::make_unique<sf::Text>(font, "ECTS: 0  Stress: 0", 24);
    scoreText->setFillColor(sf::Color::White);
    scoreText->setPosition({10.f, 10.f});

    gameOverText = std::make_unique<sf::Text>(font, "ZLAPANY! Nacisnij R aby zrestartowac", 30);
    gameOverText->setFillColor(sf::Color::Red);
    gameOverText->setPosition({120.f, 250.f});

    menuText = std::make_unique<sf::Text>(font, "Nacisnij ENTER aby zaczac", 40);
    menuText->setFillColor(sf::Color::Yellow);
    menuText->setPosition({180.f, 250.f});

    pauseText = std::make_unique<sf::Text>(font, "PAUZA", 50);
    pauseText->setFillColor(sf::Color::White);
    pauseText->setPosition({320.f, 250.f});

    player = std::make_unique<Student>();
    player->reset(); // WYMUSZAMY RESET GRACZA NA STARCIE

    platforms.push_back(std::make_unique<Platform>(100.f, 500.f, 600.f, 20.f));
    coffees.push_back(std::make_unique<Coffee>(300.f, 450.f));
    lecturers.push_back(std::make_unique<Lecturer>(600.f, 400.f)); 
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update(clock.restart().asSeconds());
        render();
    }
}

void Game::processEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) window.close();

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scan::Escape) {
                if (currentState == GameState::Playing) currentState = GameState::Paused;
                else if (currentState == GameState::Paused) currentState = GameState::Playing;
            }
            if (keyPressed->scancode == sf::Keyboard::Scan::Enter) {
                if (currentState == GameState::Menu) {
                    player->reset();
                    currentState = GameState::Playing;
                }
            }
        }
    }
}

void Game::update(float deltaTime) {
    if (currentState != GameState::Playing) return;

    if (!player->isAlive()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
            player->reset();
        }
        return; 
    }

    player->update(deltaTime);
    for (auto& lecturer : lecturers) lecturer->update(deltaTime);
    handleCollisions();

    scoreText->setString("ECTS: " + std::to_string(player->getECTS()) + "  Stress: " + std::to_string(player->getStress()));
}

void Game::handleCollisions() {
    for (auto it = coffees.begin(); it != coffees.end();) {
        if (player->getBounds().findIntersection((*it)->getBounds()).has_value()) {
            player->activateCoffeeBoost();
            it = coffees.erase(it);
        } else { ++it; }
    }

    for (auto& lecturer : lecturers) {
        if (player->getBounds().findIntersection(lecturer->getBounds()).has_value()) {
            if (!player->getIsCrouching()) {
                player->die();
            }
        }
    }
}

void Game::render() {
    window.clear(sf::Color(30, 30, 30));

    if (currentState == GameState::Menu) {
        window.draw(*menuText);
    } else {
        for (auto& platform : platforms) platform->draw(window);
        for (auto& coffee : coffees) coffee->draw(window);
        for (auto& lecturer : lecturers) lecturer->draw(window);
        player->draw(window);
        window.draw(*scoreText);

        if (currentState == GameState::Paused) {
            window.draw(*pauseText);
        }
        
        // Wyświetl "Złapany" TYLKO jeśli jesteśmy w grze I gracz naprawdę nie żyje
        if (currentState == GameState::Playing && !player->isAlive()) {
            window.draw(*gameOverText);
        }
    }

    window.display();
}