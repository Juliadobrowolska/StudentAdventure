#include "Game.h"
#include <iostream>
#include <optional>

Game::Game() 
    : window(sf::VideoMode({800, 600}), "Student Adventure"),
      scoreText(font, "", 24)
{
    window.setFramerateLimit(60);

    // Ładowanie czcionki przed przekazaniem do obiektu sf::Text (wymóg SFML 3)
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    // Konfiguracja tekstu po załadowaniu czcionki
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({10.f, 10.f});

    // Inicjalizacja obiektu gracza i elementów gry
    player = std::make_unique<Student>();

    // Dodanie przykładowych obiektów (platformy, przedmioty, przeciwnicy)
    platforms.push_back(std::make_unique<Platform>(100.f, 500.f, 600.f, 20.f));
    coffees.push_back(std::make_unique<Coffee>(300.f, 450.f));
    lecturers.push_back(std::make_unique<Lecturer>(400.f, 400.f));
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
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::update(float deltaTime) {
    player->update(deltaTime);

    for (auto& lecturer : lecturers) {
        lecturer->update(deltaTime);
    }

    handleCollisions();

    // Aktualizacja licznika punktów
    scoreText.setString(
        "ECTS: " + std::to_string(player->getECTS())
        + "  Stress: " + std::to_string(player->getStress())
    );
}

void Game::handleCollisions() {
    // Obsługa kolizji z platformami (standard SFML 3: findIntersection)
    for (auto& platform : platforms) {
        if (player->getBounds().findIntersection(platform->getBounds()).has_value()) {
            // Platform collision handling can be added here if needed.
        }
    }

    // Obsługa kolizji z przedmiotami (kawa)
    for (auto it = coffees.begin(); it != coffees.end();) {
        if (player->getBounds().findIntersection((*it)->getBounds()).has_value()) {
            player->activateCoffeeBoost();
            it = coffees.erase(it);
        } else {
            ++it;
        }
    }

    // Obsługa kolizji z wykładowcami
    for (auto& lecturer : lecturers) {
        if (player->getBounds().findIntersection(lecturer->getBounds()).has_value()) {
            // Miejsce na implementację logiki przegranej lub resetu poziomu
        }
    }
}

void Game::render() {
    window.clear(sf::Color(30, 30, 30));

    for (auto& platform : platforms) {
        platform->draw(window);
    }

    for (auto& coffee : coffees) {
        coffee->draw(window);
    }

    for (auto& lecturer : lecturers) {
        lecturer->draw(window);
    }

    player->draw(window);
    window.draw(scoreText);

    window.display();
}