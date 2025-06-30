#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Obstacle.h"
#include "Config.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdexcept>


class Ground {
public:
    explicit Ground(float groundY);
    void update(float dt);
    void render(sf::RenderWindow& window) const;
private:
    std::vector<sf::RectangleShape> segments;
    float speed;
    float segmentWidth;
    float totalTime;
    float y;
};