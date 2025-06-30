#pragma once
#include <SFML/Graphics.hpp>

class Start {
public:
    Start();
    void render() const;
    bool checkEnterPressed() const;
    void update(float dt);
    

private:
    sf::RenderWindow window;
    sf::Font font;
    bool running;
    bool enterPressed;
    void processEvents();
    void render();

};