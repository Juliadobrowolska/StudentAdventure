#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Student.h"
#include "GameObject.h"
#include "Platform.h"
#include "Coffee.h"
#include "ECTS.h"
#include "Lecturer.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void handleCollisions();
    void spawnChunk(float startX);

    sf::RenderWindow window;
    std::unique_ptr<Student> player;
    std::vector<std::unique_ptr<GameObject>> gameObjects;

    int score;
    float distanceTraveled;
    bool isPaused;
};