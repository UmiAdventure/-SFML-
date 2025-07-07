#pragma once

#include "GameState.h"
#include "Player.h"
#include "Ground.h"
#include "Obstacle.h"
#include "Config.h"
#include <vector>
#include <random>
#include <functional>

class PlayState : public GameState {
public:
    PlayState(sf::RenderWindow& win, std::function<void()> pauseCallback);

    void processEvents() override;
    void update(float dt) override;
    void render() override;

private:
    Player player;
    Ground ground;
    Player::PlayerState playerState;
    std::vector<Obstacle> obstacles;
    float spawnTimer;
    float nextSpawnTime;
    sf::Texture backgroundTexture;

    std::function<void()> onPause;

    float generateRandomTime();
};
