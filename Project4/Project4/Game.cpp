#include "Game.h"

Game::Game() :
    window(sf::VideoMode(sf::Vector2u(800u, 600u), 32), "Debug Adventure"),
    player(200.f),
    ground(200.f),
    //obstacle(200.f),
    state(State::Playing),
    spawnTimer(0.f),
    nextSpawnTime(generateRandomTime()) {  // 初始化随机生成时间
    window.setFramerateLimit(60);
}

// 生成1-3秒之间的随机时间
float Game::generateRandomTime() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 3.0);
    printf("%.5f\n", dis(gen));
    return dis(gen);
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        const float dt = clock.restart().asSeconds();
        if (state == State::Playing) update(dt);
        render();
    }
}

void Game::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) window.close();
    }
}

//void Game::update(float dt) {
//    player.update(dt);
//    ground.update(dt);
//    obstacle.update(dt);
//
//    // 更新计时器
//    spawnTimer += dt;
//    if (spawnTimer >= nextSpawnTime) {
//        spawnTimer = 0.f;
//        nextSpawnTime = generateRandomTime();  // 生成下一个随机时间
//        shouldRenderObstacle = true;  // 标记障碍物应该渲染
//    }
//    else {
//        shouldRenderObstacle = false;  // 不在显示时间内，不渲染
//    }
//}
//
//void Game::render() {
//    window.clear(sf::Color(135, 206, 235));
//    ground.render(window);
//    player.render(window);
//    obstacle.render(window);
//
//    // 仅在随机时间间隔内渲染障碍物
//    if (shouldRenderObstacle) {
//        printf("1\n");
//        obstacle.render(window);
//    }
//
//    window.display();
//}

void Game::update(float dt) {
    player.update(dt);
    ground.update(dt);

    // 更新所有障碍物
    for (auto& obs : obstacles) {
        obs.update(dt);
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

void Game::render() {
    window.clear(sf::Color(135, 206, 235));
    ground.render(window);
    player.render(window);

    // 渲染所有障碍物
    for (const auto& obs : obstacles) {
        obs.render(window);
    }

    window.display();
}