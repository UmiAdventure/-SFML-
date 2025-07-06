#include "Player.h"
#include <stdexcept>
#include <SFML/Window/Keyboard.hpp>
#include"Ground.h"
Ground ground(200.f);

Player::Player(float startX, float startY)
    : velocity(0.f, 0.f),
    gravity(GRAVITY),
    jumpImpulse(JUMP_IMPULSE)
{
    if (!texture.loadFromFile("player.png"))
        throw std::runtime_error("Failed to load player.png");

    shape.setSize({ 50.f, 50.f });
    shape.setOrigin(shape.getSize() / 2.f);
    shape.setTexture(&texture);                 // 贴纹理到矩形
    shape.setPosition({ startX, startY });
}
void Player::update(float dt, const Ground& ground, PlayerState state) {
    this->state = state;
    float xPos = shape.getPosition().x;
    float terrainHeight = ground.getY() - 50.0f * std::sin(xPos * 0.01f + ground.getTotalTime() * 2.0f);
    float groundLevel = terrainHeight - shape.getSize().y;  // 地面的Y坐标
    using Key = sf::Keyboard::Key;
    // Space 跳跃
    if (sf::Keyboard::isKeyPressed(Key::Space) && state == PlayerState::GROUNDED) {
        velocity.y = jumpStrength;
        this->state = PlayerState::JUMPING;
    }
    // 重力
    if (state == PlayerState::JUMPING) {
        velocity.y += gravity * dt;
        shape.move(sf::Vector2f(0, velocity.y * dt));  // 只在Y轴移动

        // 碰撞检测：如果落到地面
        if (shape.getPosition().y >= groundLevel) {
            shape.setPosition(sf::Vector2f(xPos, groundLevel));
            velocity.y = 0;
            this->state = PlayerState::GROUNDED;
        }
    }
    else {
        // 在地面时，强制跟随地形
        shape.setPosition(sf::Vector2f(xPos, groundLevel));
    }
}



Player::PlayerState Player::getState() const {
    return state;
}
void Player::render(sf::RenderWindow& win) const {
    win.draw(shape);
}


