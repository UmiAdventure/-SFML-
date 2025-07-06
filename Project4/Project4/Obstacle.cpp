//#include "Obstacle.h"
//#include <stdexcept>
//
//Obstacle::Obstacle(float groundY) : groundY(groundY) {  // 默认向左移动
//    shape.setSize(sf::Vector2f(40.f, 40.f));
//    shape.setFillColor(sf::Color::Green);  // 绿色障碍物
//    shape.setPosition(sf::Vector2f(800.f, groundY - shape.getSize().y));
//    velocity.x = 200.f;
//}
//
//void Obstacle::update(float dt) {
//    
//}
//void Obstacle::update(float dt, const Ground& ground) {
//   shape.move(sf::Vector2f(-200.f * dt, 0.f));
//       float xPos = shape.getPosition().x;
//
//
//    float terrainHeight = ground.getY() - 50.0f * std::sin(xPos * 0.01f + ground.getTotalTime() * 2.0f);
//    float groundLevel = terrainHeight - shape.getSize().y;  // 地面的Y坐标
//    //强制跟随地形
//    shape.setPosition(sf::Vector2f(xPos, groundLevel));
//}
//
//void Obstacle::render(sf::RenderWindow& window) const {
//    window.draw(shape);
//}
//
//sf::FloatRect Obstacle::getBounds() const {
//    return shape.getGlobalBounds();
//}
//sf::Vector2f Obstacle::getPosition() const {
//    return shape.getPosition();
//}
//bool Obstacle::isOffScreen() const {
//    // 获取障碍物位置和尺寸
//    const sf::Vector2f pos = getPosition();
//    const sf::Vector2f size = shape.getSize();
//
//    // 当障碍物完全离开屏幕左侧时返回true
//    return (pos.x + size.x) < 0;
//}


#include "Obstacle.h"
#include <cmath>

Obstacle::Obstacle(float groundY)
    : groundY(groundY), speed(200.f) {
    shape.setSize({ 40.f, 40.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 800.f, groundY - shape.getSize().y });

    // 初始化 GameObject 的通用状态
    state = true;
    position = shape.getPosition();
    positionX = position.x;
    positionY = position.y;
}

void Obstacle::update(float dt) {
    // 空实现，仅保留接口兼容
}

void Obstacle::update(float dt, const Ground& ground) {
    shape.move({ -speed * dt, 0.f });
    float xPos = shape.getPosition().x;

    // 计算地形高度并贴地移动
    float terrainHeight = ground.getY() - 50.0f * std::sin(xPos * 0.01f + ground.getTotalTime() * 2.0f);
    float groundLevel = terrainHeight - shape.getSize().y;
    shape.setPosition({ xPos, groundLevel });

    // 更新 GameObject 通用属性
    position = shape.getPosition();
    positionX = position.x;
    positionY = position.y;
}

void Obstacle::render(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f Obstacle::getPosition() const {
    return shape.getPosition();
}

sf::Vector2f Obstacle::getSize() const {
    return shape.getSize();
}

bool Obstacle::isActive() const {
    return state;
}

void Obstacle::setActive(bool active) {
    state = active;
}

void Obstacle::move(const sf::Vector2f& offset) {
    shape.move(offset);
    position = shape.getPosition();
    positionX = position.x;
    positionY = position.y;
}

void Obstacle::setPosition(const sf::Vector2f& pos) {
    shape.setPosition(pos);
    position = pos;
    positionX = pos.x;
    positionY = pos.y;
}

bool Obstacle::isOffScreen() const {
    return (shape.getPosition().x + shape.getSize().x) < 0;
}
