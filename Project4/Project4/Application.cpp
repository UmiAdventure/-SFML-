#include "Application.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "HelpState.h" // 新增帮助界面

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

        // ✅ PauseState 请求返回
        if (auto pause = dynamic_cast<PauseState*>(state)) {
            if (pause->shouldPop) {
                popState();
                continue;
            }
        }

        // ✅ HelpState 请求返回
        if (auto help = dynamic_cast<HelpState*>(state)) {
            if (help->shouldReturn) {
                popState();
                continue;
            }
        }

        // ✅ MenuState 处理开始游戏 / 进入帮助
        if (auto menu = dynamic_cast<MenuState*>(state)) {
            if (menu->isStartPressed()) {
                popState();  // 关闭菜单

                auto play = std::make_unique<PlayState>(window, [this]() {
                    // 触发暂停时，压入 PauseState
                    this->pushState(std::make_unique<PauseState>(
                        window,
                        [this]() {
                            if (auto* top = dynamic_cast<PauseState*>(this->currentState())) {
                                top->shouldPop = true;
                            }
                        }
                    ));
                    });

                pushState(std::move(play));
                continue;
            }

            if (menu->isHelpPressed()) {
                pushState(std::make_unique<HelpState>(window));
                continue;
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
