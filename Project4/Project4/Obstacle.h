#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ground.h"

class Obstacle : public GameObject {
public:
    explicit Obstacle(float groundY);
    Obstacle() : Obstacle(500.f) {}

    void update(float dt) override;                     // 基础移动逻辑（可空）
    void update(float dt, const Ground& ground);        // 根据地形高度更新位置
    void render(sf::RenderWindow& window) const override;

    // 碰撞 & 状态接口
    sf::FloatRect getBounds() const override;
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const override;
    bool isActive() const override;
    void setActive(bool active) override;

    // 移动 & 位置接口
    void move(const sf::Vector2f& offset) override;
    void setPosition(const sf::Vector2f& pos) override;

    // 辅助判断
    bool isOffScreen() const;

private:
    float groundY;
    float speed = 200.f;
};

