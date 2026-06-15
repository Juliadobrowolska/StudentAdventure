#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Student.h"
#include "Platform.h"
#include "Coffee.h"
#include "Lecturer.h"

enum class GameState { Menu, Playing, Paused };

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void handleCollisions();

    GameState currentState;

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Font font;

    std::unique_ptr<sf::Text> scoreText;
    std::unique_ptr<sf::Text> gameOverText;
    std::unique_ptr<sf::Text> menuText;
    std::unique_ptr<sf::Text> pauseText;

    std::unique_ptr<Student> player;
    std::vector<std::unique_ptr<Platform>> platforms;
    std::vector<std::unique_ptr<Coffee>> coffees;
    std::vector<std::unique_ptr<Lecturer>> lecturers;
};