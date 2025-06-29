#include "Obstacle.h"

Obstacle::Obstacle(float groundY) : groundY(groundY) {  // 默认向左移动
    shape.setSize(sf::Vector2f(40.f, 40.f));
    shape.setFillColor(sf::Color::Green);  // 绿色障碍物
    shape.setPosition(sf::Vector2f(800.f, groundY - shape.getSize().y));
    velocity.x = 200.f;
}

void Obstacle::update(float dt) {
    shape.move(sf::Vector2f(-200.f * dt, 0.f));
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
bool Obstacle::isOffScreen() const {
    // 获取障碍物位置和尺寸
    const sf::Vector2f pos = getPosition();
    const sf::Vector2f size = shape.getSize();

    // 当障碍物完全离开屏幕左侧时返回true
    return (pos.x + size.x) < 0;
}