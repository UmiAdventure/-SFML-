//#include "PlayState.h"
//#include <algorithm>
//#include <stdexcept>
//#include <SFML/Window/Keyboard.hpp>
//
//PlayState::PlayState(sf::RenderWindow& win)
//    : player(100.f, 300.f), ground(200.f),
//    playerState(Player::PlayerState::GROUNDED),
//    spawnTimer(0.f),
//    nextSpawnTime(generateRandomTime())
//{
//    window = &win;
//    if (!backgroundTexture.loadFromFile("background.png")) {
//        throw std::runtime_error("Failed to load background.png");
//    }
//    window->setFramerateLimit(60);
//}
//
//float PlayState::generateRandomTime() {
//    static std::random_device rd;
//    static std::mt19937 gen(rd());
//    std::uniform_real_distribution<> dis(0.5f, 3.0f);
//    return dis(gen);
//}
//
//void PlayState::processEvents() {
//    while (auto event = window->pollEvent()) {
//        if (event->is<sf::Event::Closed>()) {
//            window->close();
//        }
//    }
//}
//
//void PlayState::update(float dt) {
//    player.update(dt, ground, playerState);
//    playerState = player.getState();
//    ground.update(dt);
//
//    for (auto& obs : obstacles) {
//        obs.update(dt, ground);
//    }
//
//    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(),
//        [](const Obstacle& obs) { return obs.isOffScreen(); }),
//        obstacles.end());
//
//    spawnTimer += dt;
//    if (spawnTimer >= nextSpawnTime) {
//        spawnTimer = 0.f;
//        nextSpawnTime = generateRandomTime();
//        obstacles.emplace_back(200.f);
//    }
//}
//
//void PlayState::render() {
//    window->clear();
//    window->draw(sf::Sprite(backgroundTexture));
//    ground.render(*window);
//    player.render(*window);
//    for (const auto& obs : obstacles) {
//        obs.render(*window);
//    }
//    window->display();
//}
#include "PlayState.h"
#include <algorithm>
#include <stdexcept>
#include <SFML/Window/Keyboard.hpp>

PlayState::PlayState(sf::RenderWindow& win, std::function<void()> pauseCallback)
    : player(100.f, 300.f),
    ground(200.f),
    playerState(Player::PlayerState::GROUNDED),
    spawnTimer(0.f),
    nextSpawnTime(generateRandomTime()),
    onPause(std::move(pauseCallback))
{
    window = &win;
    if (!backgroundTexture.loadFromFile("background.png")) {
        throw std::runtime_error("Failed to load background.png");
    }
    window->setFramerateLimit(60);
}

float PlayState::generateRandomTime() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.5f, 3.0f);
    return dis(gen);
}

//void PlayState::processEvents() {
//    while (auto event = window->pollEvent()) {
//        if (event->is<sf::Event::Closed>()) {
//            window->close();
//        }
//        else if (event->is<sf::Event::KeyPressed>()) {
//            auto key = event->get<sf::Event::KeyPressed>().code;
//            if (key == sf::Keyboard::Key::P && onPause) {
//                onPause();  // 切换到 PauseState
//            }
//        }
//    }
//}
void PlayState::processEvents() {
    while (auto event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }
        else if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
            if (keyEvent->code == sf::Keyboard::Key::P && onPause) {
                onPause();  // 切换到 PauseState
            }
        }
    }
}
void PlayState::update(float dt) {
    player.update(dt, ground, playerState);
    playerState = player.getState();
    ground.update(dt);

    for (auto& obs : obstacles) {
        obs.update(dt, ground);
    }

    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(),
        [](const Obstacle& obs) { return obs.isOffScreen(); }),
        obstacles.end());

    spawnTimer += dt;
    if (spawnTimer >= nextSpawnTime) {
        spawnTimer = 0.f;
        nextSpawnTime = generateRandomTime();
        obstacles.emplace_back(200.f);  // 添加障碍物
    }
}

void PlayState::render() {
    window->clear();
    window->draw(sf::Sprite(backgroundTexture));  // 背景
    ground.render(*window);
    player.render(*window);
    for (const auto& obs : obstacles) {
        obs.render(*window);
    }
    window->display();
}
