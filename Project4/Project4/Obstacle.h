#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
public:
    explicit Obstacle(float groundY);
    Obstacle() : Obstacle(500.f) {}
    void update(float dt);
    void render(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;  // ��ȡ��ײ�߽�
    sf::Vector2f getPosition() const;  // ����λ��
    sf::Vector2f getSize() const;      // ���ش�С
    bool isOffScreen() const;
private:
    sf::RectangleShape shape;
    sf::Vector2f       velocity;
    float              groundY;
    float              speed;
};