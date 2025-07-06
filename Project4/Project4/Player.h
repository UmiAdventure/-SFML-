#pragma once
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Ground.h"
#include "Obstacle.h"
#include <vector>
#include <stdexcept>


class Player
{
public:
    enum class PlayerState {
        GROUNDED,
        JUMPING
    };
    Player(float startX, float startY);   // 位置由 Game 注入
    void  update(float dt);               // 每帧更新
    void  render(sf::RenderWindow& win) const;
    PlayerState getState() const;
    void update(float dt, const Ground& ground, PlayerState state);

    
private:
   
    sf::RectangleShape shape;     // ✅ 改回 Rectangle
    sf::Texture        texture;   // 贴 player.png
    sf::Vector2f       velocity;
    float              gravity;
    float              jumpImpulse;
    float              jumpStrength = -500.f;
    float              groundY;
    PlayerState state;
};


