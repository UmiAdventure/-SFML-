#include "Player.h"
Player::Player(float groundY) : groundY(groundY) {
    shape.setSize(sf::Vector2f(40.f, 40.f));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100.f, groundY - shape.getSize().y));

    //velocity = sf::Vector2f(150.f, 0.f); // 预留横向速度
    gravity = 1800.f;
}
void Player::update(float dt) {
    using Key = sf::Keyboard::Key;
    // Space 跳跃
    if (sf::Keyboard::isKeyPressed(Key::Space) &&
        shape.getPosition().y >= groundY - shape.getSize().y - 0.1f) {
        velocity.y = -800.f;
    }
    // 重力
    velocity.y += gravity * dt;
    shape.move(velocity * dt);
    // 与地面碰撞
    if (shape.getPosition().y >= groundY - shape.getSize().y) {
        shape.setPosition(sf::Vector2f(shape.getPosition().x, groundY - shape.getSize().y));
        velocity.y = 0.f;
    }
}
void Player::render(sf::RenderWindow& window) const {
    window.draw(shape);
}