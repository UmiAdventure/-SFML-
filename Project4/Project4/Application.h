//#pragma once

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Application {
public:
    Application();
    void run();

    void pushState(std::unique_ptr<GameState> state);
    void popState();

private:
    sf::RenderWindow window;
    std::stack<std::unique_ptr<GameState>> stateStack;

    GameState* currentState(); // 获取当前状态指针
};
