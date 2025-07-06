#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class GameState {
public:
    virtual ~GameState() = default;

    virtual void processEvents() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;

    // 传入窗口引用，状态持有指向它的引用，不自己管理窗口生命周期
    void setWindow(sf::RenderWindow& win) { window = &win; }

protected:
    sf::RenderWindow* window = nullptr;
};
