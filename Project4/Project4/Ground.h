#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Ground {
public:
    explicit Ground(float groundY);
    void update(float dt);
    void render(sf::RenderWindow& window) const;
private:
    std::vector<sf::RectangleShape> segments;
    float speed;
    float segmentWidth;
    float y;
};