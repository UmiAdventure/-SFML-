#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>

class HelpState : public GameState {
public:
    HelpState(sf::RenderWindow& win);
    void processEvents() override;
    void update(float dt) override;
    void render() override;

    bool shouldReturn = false;

private:
    sf::RenderWindow& window;
    sf::Font titleFont;
    sf::Font font;
};
