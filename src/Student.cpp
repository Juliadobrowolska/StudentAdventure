#include "Student.h"

Student::Student()
{
    body.setSize({50.f, 70.f});
    body.setFillColor(sf::Color(120, 120, 255));

    head.setRadius(20.f);
    head.setFillColor(sf::Color(255, 220, 177));

    backpack.setSize({18.f, 40.f});
    backpack.setFillColor(sf::Color(70, 70, 70));

    position = {100.f, 550.f};
    alive = true;
    isCrouching = false;
}

void Student::update(float deltaTime)
{
    if (!alive) return; // Jeśli nie żyje, nie reaguje na klawisze

    velocity.x = 0.f;

    // 1. OBSŁUGA KUCANIA (Klawisz S)
    float currentSpeed = moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        if (!isCrouching && onGround)
        {
            isCrouching = true;
            body.setSize({50.f, 35.f}); // Zmniejszamy ciało o połowę
            position.y += 35.f;         // Obniżamy pozycję, żeby postać nie lewitowała
        }
        currentSpeed = moveSpeed * 0.5f; // Kucanie spowalnia postać
    }
    else
    {
        if (isCrouching)
        {
            isCrouching = false;
            body.setSize({50.f, 70.f}); // Powrót do normalnego rozmiaru
            position.y -= 35.f;         // Podnosimy pozycję do góry
        }
    }

    // 2. RUCH POZIOMY
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        velocity.x = -currentSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        velocity.x = currentSpeed;

    // 3. SKOK (Nie można skakać, kucając)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && onGround && !isCrouching)
    {
        velocity.y = jumpForce;
        onGround = false;
    }

    // 4. BOOST KAWOWY
    if (coffeeBoost)
    {
        coffeeTimer -= deltaTime;
        moveSpeed = 450.f;

        if (coffeeTimer <= 0.f)
        {
            coffeeBoost = false;
            moveSpeed = 300.f;
        }
    }

    applyGravity(deltaTime);

    position += velocity * deltaTime;

    // 5. KOLIZJA Z PODŁOGĄ
    float groundLevel = isCrouching ? 585.f : 550.f; // Dopasowanie poziomu do wysokości kształtu
    if (position.y > groundLevel)
    {
        position.y = groundLevel;
        velocity.y = 0.f;
        onGround = true;
    }
}

void Student::draw(sf::RenderWindow& window)
{
    if (!alive) return; // Nie rysuj, jeśli postać umarła

    body.setPosition(position);

    // Dynamiczne dopasowanie pozycji głowy i plecaka przy kucaniu
    if (isCrouching)
    {
        head.setPosition({ position.x + 5.f, position.y - 30.f });
        backpack.setPosition({ position.x - 10.f, position.y + 5.f });
    }
    else
    {
        head.setPosition({ position.x + 5.f, position.y - 30.f });
        backpack.setPosition({ position.x - 10.f, position.y + 15.f });
    }

    window.draw(backpack);
    window.draw(body);
    window.draw(head);
}

sf::FloatRect Student::getBounds() const
{
    return body.getGlobalBounds();
}

void Student::addECTS(int amount)
{
    ectsPoints += amount;
}

void Student::addStress(int amount)
{
    stressLevel += amount;
}

void Student::activateCoffeeBoost()
{
    coffeeBoost = true;
    coffeeTimer = 5.f;
}

int Student::getECTS() const
{
    return ectsPoints;
}

int Student::getStress() const
{
    return stressLevel;
}

// IMPLEMENTACJA NOWYCH METOD
bool Student::getIsCrouching() const
{
    return isCrouching;
}

void Student::die()
{
    alive = false;
}

bool Student::isAlive() const
{
    return alive;
}

void Student::reset()
{
    alive = true;
    isCrouching = false;
    body.setSize({50.f, 70.f});
    position = {100.f, 550.f};
    velocity = {0.f, 0.f};
    ectsPoints = 0;
    stressLevel = 0;
}