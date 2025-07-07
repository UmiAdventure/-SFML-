#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <functional>

class PauseState : public GameState {
public:
    PauseState(sf::RenderWindow& win, std::function<void()> resumeCallback);
    bool shouldPop = false;

    void processEvents() override;
    void update(float dt) override;
    void render() override;

private:
    sf::RenderWindow& window;
    std::function<void()> onResume;

    sf::Font font;
};
