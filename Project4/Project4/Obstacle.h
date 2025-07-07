#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ground.h"

class Obstacle : public GameObject {
public:
    explicit Obstacle(float groundY);
    Obstacle() : Obstacle(500.f) {}

    void update(float dt) override;                     // �����ƶ��߼����ɿգ�
    void update(float dt, const Ground& ground);        // ���ݵ��θ߶ȸ���λ��
    void render(sf::RenderWindow& window) const override;

    // ��ײ & ״̬�ӿ�
    sf::FloatRect getBounds() const override;
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const override;
    bool isActive() const override;
    void setActive(bool active) override;

    // �ƶ� & λ�ýӿ�
    void move(const sf::Vector2f& offset) override;
    void setPosition(const sf::Vector2f& pos) override;

    // �����ж�
    bool isOffScreen() const;

private:
    float groundY;
    float speed = 200.f;
};

