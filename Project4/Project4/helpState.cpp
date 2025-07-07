#include "HelpState.h"
#include <stdexcept>

HelpState::HelpState(sf::RenderWindow& win) : window(win) {
    if (!titleFont.openFromFile("arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    if (!font.openFromFile("CHILLER.TTF")) {
        throw std::runtime_error("Failed to load font");
    }
}

void HelpState::processEvents() {
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B)) {
        shouldReturn = true;
    }
}

void HelpState::update(float) {
    // No dynamic update
}

void HelpState::render() {
    window.clear(sf::Color::Black);

    std::vector<std::string> lines = {
    "========== HOW TO PLAY ==========",
    "",
    "Press [Enter] to start the game.",
    "Press [P] to pause or resume.",
    "Press [Space] to jump over obstacles.",
    "",
    "Avoid obstacles! Hitting one loses 1 life.",
    "Lose all lives, game over.",
    "",
    "Press [B] to return to menu."
    };


    float y = 40.f;
    for (const auto& line : lines) {
        sf::Text text(font);
        text.setString(line);
        text.setCharacterSize(45);
        text.setFillColor(sf::Color::White);
        text.setPosition({ 110.f, y });
        window.draw(text);
        y += 55.f;
    }

    window.display();
}
