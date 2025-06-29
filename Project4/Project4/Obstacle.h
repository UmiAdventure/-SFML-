#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
public:
    explicit Obstacle(float groundY);
    Obstacle() : Obstacle(500.f) {}
    void update(float dt);
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;  // 获取碰撞边界
    sf::Vector2f getPosition() const;  // 返回位置
    sf::Vector2f getSize() const;      // 返回大小
    bool isOffScreen() const;
private:
    sf::RectangleShape shape;
    sf::Vector2f       velocity;
    float              groundY;
    float              speed;
};