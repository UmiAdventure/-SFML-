#pragma once
#include <SFML/Graphics.hpp>
class Player {
public:
    explicit Player(float groundY);
    void update(float dt);
    void render(sf::RenderWindow& window) const;
private:
    sf::RectangleShape shape;
    sf::Vector2f       velocity;
    float              gravity;
    float              groundY;
};