#include "MenuState.h"
#include <SFML/Window/Keyboard.hpp>
#include <stdexcept>

MenuState::MenuState(sf::RenderWindow& win) {
    window = &win;

    if (!titleFont.openFromFile("CHILLER.TTF")) {
        throw std::runtime_error("Failed to load CHILLER.TTF");
    }
    if (!startFont.openFromFile("CHILLER.TTF")) {
        throw std::runtime_error("Failed to load CHILLER.TTF");
    }
    /* sf::Textû��Ĭ�Ϲ��캯�����޷�����Ϊ��Ա����
      ����ȫ��renderʵ����*/
}

void MenuState::processEvents() {
    while (auto event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }
    }

    startPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
}

void MenuState::update(float dt) {
    // �޶�̬�����ݲ���ʵ��
}

void MenuState::render() {
    sf::Text titleText(titleFont);
    sf::Text startText(startFont);
    titleText.setString("DEBUG ADVENTURE");
    titleText.setCharacterSize(120);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition({ 10.f, 150.f });
    titleText.setStyle(sf::Text::Bold);

    startText.setString("Press Enter to start");
    startText.setCharacterSize(60);
    startText.setFillColor(sf::Color::White);
    startText.setPosition({ 220.f, 350.f });
    window->clear(sf::Color::Black);
    window->draw(titleText);
    window->draw(startText);
    window->display();
}

bool MenuState::isStartPressed() const {
    return startPressed;
}
