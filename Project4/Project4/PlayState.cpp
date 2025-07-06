#include "PlayState.h"
#include"Player.h"
#include <stdexcept>


PlayState::PlayState() :
    window(sf::VideoMode(sf::Vector2u(800u, 600u), 32), "Debug Adventure"),
    player(100.0f, 300.0f),
    ground(200.f),
    //obstacle(200.f),
    state(State::Playing),
    spawnTimer(0.f),
    playerState(Player::PlayerState::GROUNDED),
    nextSpawnTime(generateRandomTime()) {  // 初始化随机生成时间
    window.setFramerateLimit(60);
    if (!backgroundTexture.loadFromFile("background.png")) {
        throw std::runtime_error("Failed to load background.png");
    }
    //backgroundSprite.setTexture(backgroundTexture);
}

// 生成1-3秒之间的随机时间
float PlayState::generateRandomTime() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 3.0);
    printf("%.5f\n", dis(gen));
    return dis(gen);
}

void PlayState::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        const float dt = clock.restart().asSeconds();
        if (state == State::Playing) update(dt);
        render();
    }
}

void PlayState::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) window.close();
    }
}


void PlayState::update(float dt) {
    //player.update(dt);
    player.update(dt, ground, playerState);
    playerState = player.getState();
    ground.update(dt);

    // 更新所有障碍物
    for (auto& obs : obstacles) {
        obs.update(dt, ground);
    }

    // 移除移出屏幕的障碍物
    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(),
        [](const Obstacle& obs) { return obs.isOffScreen(); }),
        obstacles.end());/**/

    // 更新生成计时器
    spawnTimer += dt;
    if (spawnTimer >= nextSpawnTime) {
        spawnTimer = 0.f;
        nextSpawnTime = generateRandomTime();
        // 创建新障碍物并添加到容器
        obstacles.emplace_back(200.f);  // 假设200.f是移动速度
    }
}

void PlayState::render() {
    window.clear();
    window.draw(sf::Sprite(backgroundTexture));   // ✅ 临时精灵绘背景
    ground.render(window);
    player.render(window);
    for (const auto& obs : obstacles) obs.render(window);
    window.display();
}