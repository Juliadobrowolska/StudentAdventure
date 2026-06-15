#pragma once

#include <SFML/Graphics.hpp>

// #include <memory> is already included below? Keep only once.
#include <memory>
#include <vector>

#include "GameObject.h"
#include "Student.h"
#include "Enemy.h"
#include "Collectible.h"
#include "Platform.h"
#include "Coffee.h"
#include "Lecturer.h"

class Game
{
public:

    Game();

    void run();

private:

    void processEvents();

    void update(float deltaTime);

    void render();

    void handleCollisions();

private:

    sf::RenderWindow window;

    sf::Clock clock;

    sf::Font font;

    sf::Text scoreText;

    std::unique_ptr<Student> player;

    std::vector<std::unique_ptr<Platform>> platforms;
    std::vector<std::unique_ptr<Coffee>> coffees;
    std::vector<std::unique_ptr<Lecturer>> lecturers;
};