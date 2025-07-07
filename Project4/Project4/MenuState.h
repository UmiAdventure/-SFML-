#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>

class MenuState : public GameState {
public:
    MenuState(sf::RenderWindow& window);
    void processEvents() override;
    void update(float dt) override;
    void render() override;
    bool isHelpPressed() const;
    bool isStartPressed() const;

private:
    sf::Font font;
    bool startPressed = false;
    bool helpPressed = false;
};
