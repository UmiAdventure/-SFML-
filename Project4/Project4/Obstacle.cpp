#include "Obstacle.h"

Obstacle::Obstacle(float groundY) : groundY(groundY) {  // Ĭ�������ƶ�
    shape.setSize(sf::Vector2f(40.f, 40.f));
    shape.setFillColor(sf::Color::Green);  // ��ɫ�ϰ���
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
    // ��ȡ�ϰ���λ�úͳߴ�
    const sf::Vector2f pos = getPosition();
    const sf::Vector2f size = shape.getSize();

    // ���ϰ�����ȫ�뿪��Ļ���ʱ����true
    return (pos.x + size.x) < 0;
}