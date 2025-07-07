#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>

class MenuState : public GameState {
public:
    MenuState(sf::RenderWindow& window);
    void processEvents() override;
    void update(float dt) override;
    void render() override;

    bool isStartPressed() const;

private:
    sf::Font startFont;
    sf::Font titleFont;

    bool startPressed = false;
};
