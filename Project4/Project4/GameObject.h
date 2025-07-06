#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject {
public:
    GameObject();
    virtual ~GameObject() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;

    virtual sf::FloatRect getBounds() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual sf::Vector2f getSize() const = 0;
    virtual bool isActive() const = 0;
    virtual void setActive(bool active) = 0;

    virtual void move(const sf::Vector2f& offset) = 0;
    virtual void setPosition(const sf::Vector2f& pos) = 0;

    // 通用属性
    sf::Vector2f position;
    bool state;
    float positionX;
    float positionY;

protected:
    sf::RectangleShape shape;  // ✅ 改为 RectangleShape
};
