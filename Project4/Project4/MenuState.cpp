#include "MenuState.h"
#include <SFML/Window/Keyboard.hpp>
#include <stdexcept>

MenuState::MenuState(sf::RenderWindow& win) {
    window = &win;

    if (!font.openFromFile("CHILLER.TTF")) {
        throw std::runtime_error("Failed to load CHILLER.TTF");
    }
    /* sf::Text没有默认构造函数，无法声明为成员变量
      所以全在render实现了*/
}

void MenuState::processEvents() {
    while (auto event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }
    }
    helpPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I);
    startPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
}

void MenuState::update(float dt) {
    // 无动态内容暂不需实现
}

void MenuState::render() {
    sf::Text titleText(font);
    sf::Text startText(font);
    sf::Text helpText(font);

    titleText.setString("DEBUG ADVENTURE");
    titleText.setCharacterSize(120);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition({ 10.f, 150.f });
    titleText.setStyle(sf::Text::Bold);

    startText.setString("Press Enter to start");
    startText.setCharacterSize(60);
    startText.setFillColor(sf::Color::White);
    startText.setPosition({ 220.f, 350.f });

    helpText.setString("i : help");
    helpText.setCharacterSize(40);
    helpText.setFillColor(sf::Color::White);
    helpText.setPosition({ 700.f, 5.f });

    window->clear(sf::Color::Black);
    window->draw(titleText);
    window->draw(startText);
    window->draw(helpText);

    window->display();
}

bool MenuState::isStartPressed() const {
    return startPressed;
}
bool MenuState::isHelpPressed() const {
    return helpPressed;
}
