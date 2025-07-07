#include "Application.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"

#include <memory>

Application::Application()
    : window(sf::VideoMode(sf::Vector2u(800u, 600u), 32), "Debug Adventure")
{
    window.setFramerateLimit(60);

    // 初始状态为菜单
    pushState(std::make_unique<MenuState>(window));
}

void Application::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        if (stateStack.empty())
            return;

        auto* state = currentState();

        state->processEvents();
        float dt = clock.restart().asSeconds();
        state->update(dt);
        state->render();

        // ✅ 检查当前状态是否是 PauseState，是否请求 pop
        if (auto pause = dynamic_cast<PauseState*>(state)) {
            if (pause->shouldPop) {
                popState();  // 安全地在主循环中 pop
                continue;    // 避免下面对已销毁状态的处理
            }
        }

        // ✅ 处理菜单状态：点击开始则进入 PlayState，并能触发 PauseState
        if (auto menu = dynamic_cast<MenuState*>(state)) {
            if (menu->isStartPressed()) {
                popState();  // 弹出菜单

                auto play = std::make_unique<PlayState>(window, [this]() {
                    // 当 PlayState 请求暂停，压入 PauseState
                    this->pushState(std::make_unique<PauseState>(
                        window,
                        [this]() {
                            // ✅ 不立即 pop，而是设置标志，在下一帧处理
                            if (auto* top = dynamic_cast<PauseState*>(this->currentState())) {
                                top->shouldPop = true;
                            }
                        }
                    ));
                    });

                pushState(std::move(play));
                continue;  // 避免继续处理旧状态
            }
        }
    }
}

void Application::pushState(std::unique_ptr<GameState> state) {
    stateStack.push(std::move(state));
}

void Application::popState() {
    if (!stateStack.empty()) {
        stateStack.pop();
    }
}

GameState* Application::currentState() {
    if (stateStack.empty()) return nullptr;
    return stateStack.top().get();
}
