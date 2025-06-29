#include "Game.h"

Game::Game() :
    window(sf::VideoMode(sf::Vector2u(800u, 600u), 32), "Debug Adventure"),
    player(200.f),
    ground(200.f),
    //obstacle(200.f),
    state(State::Playing),
    spawnTimer(0.f),
    nextSpawnTime(generateRandomTime()) {  // ��ʼ���������ʱ��
    window.setFramerateLimit(60);
}

// ����1-3��֮������ʱ��
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
//    // ���¼�ʱ��
//    spawnTimer += dt;
//    if (spawnTimer >= nextSpawnTime) {
//        spawnTimer = 0.f;
//        nextSpawnTime = generateRandomTime();  // ������һ�����ʱ��
//        shouldRenderObstacle = true;  // ����ϰ���Ӧ����Ⱦ
//    }
//    else {
//        shouldRenderObstacle = false;  // ������ʾʱ���ڣ�����Ⱦ
//    }
//}
//
//void Game::render() {
//    window.clear(sf::Color(135, 206, 235));
//    ground.render(window);
//    player.render(window);
//    obstacle.render(window);
//
//    // �������ʱ��������Ⱦ�ϰ���
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

    // ���������ϰ���
    for (auto& obs : obstacles) {
        obs.update(dt);
    }

    // �Ƴ��Ƴ���Ļ���ϰ���
    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(),
        [](const Obstacle& obs) { return obs.isOffScreen(); }),
        obstacles.end());/**/

    // �������ɼ�ʱ��
    spawnTimer += dt;
    if (spawnTimer >= nextSpawnTime) {
        spawnTimer = 0.f;
        nextSpawnTime = generateRandomTime();
        // �������ϰ��ﲢ��ӵ�����
        obstacles.emplace_back(200.f);  // ����200.f���ƶ��ٶ�
    }
}

void Game::render() {
    window.clear(sf::Color(135, 206, 235));
    ground.render(window);
    player.render(window);

    // ��Ⱦ�����ϰ���
    for (const auto& obs : obstacles) {
        obs.render(window);
    }

    window.display();
}