//#include "Obstacle.h"
//#include <stdexcept>
//
//Obstacle::Obstacle(float groundY) : groundY(groundY) {  // Ĭ�������ƶ�
//    shape.setSize(sf::Vector2f(40.f, 40.f));
//    shape.setFillColor(sf::Color::Green);  // ��ɫ�ϰ���
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
//    float groundLevel = terrainHeight - shape.getSize().y;  // �����Y����
//    //ǿ�Ƹ������
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
//    // ��ȡ�ϰ���λ�úͳߴ�
//    const sf::Vector2f pos = getPosition();
//    const sf::Vector2f size = shape.getSize();
//
//    // ���ϰ�����ȫ�뿪��Ļ���ʱ����true
//    return (pos.x + size.x) < 0;
//}


#include "Obstacle.h"
#include <cmath>

Obstacle::Obstacle(float groundY)
    : groundY(groundY), speed(200.f) {
    shape.setSize({ 40.f, 40.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 800.f, groundY - shape.getSize().y });

    // ��ʼ�� GameObject ��ͨ��״̬
    state = true;
    position = shape.getPosition();
    positionX = position.x;
    positionY = position.y;
}

void Obstacle::update(float dt) {
    // ��ʵ�֣��������ӿڼ���
}

void Obstacle::update(float dt, const Ground& ground) {
    shape.move({ -speed * dt, 0.f });
    float xPos = shape.getPosition().x;

    // ������θ߶Ȳ������ƶ�
    float terrainHeight = ground.getY() - 50.0f * std::sin(xPos * 0.01f + ground.getTotalTime() * 2.0f);
    float groundLevel = terrainHeight - shape.getSize().y;
    shape.setPosition({ xPos, groundLevel });

    // ���� GameObject ͨ������
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
