#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ground.h"
class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    Player          player;
    Ground          ground;
    enum class State { Playing };
    State state;
};