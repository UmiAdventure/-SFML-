#include "PauseState.h"
#include <stdexcept>
#include <stdio.h>

PauseState::PauseState(sf::RenderWindow& win, std::function<void()> resumeCallback)
    : window(win), onResume(std::move(resumeCallback))
{
    if (!font.openFromFile("CHILLER.TTF")) {
        throw std::runtime_error("Failed to load font");
    }
}
void PauseState::processEvents() {
    const auto onClosed = [this](const sf::Event::Closed&) {
        window.close();
        };

    const auto onKeyPressed = [this](const sf::Event::KeyPressed& keyPressed) {
        if (keyPressed.code == sf::Keyboard::Key::P) {
            printf("P IS PRESSED\n");
            shouldPop = true;
        }
        };

    window.handleEvents(onClosed, onKeyPressed);
}
void PauseState::update(float) {
    // 暂停时不更新游戏逻辑
}

void PauseState::render() {
    
    sf::Text titleText(font);
    sf::Text startText(font);

    titleText.setString("PAUSED");
    titleText.setCharacterSize(100);
    titleText.setFillColor(sf::Color::Yellow);
    titleText.setPosition({ 250.f, 150.f });

    startText.setString("Press P to Resume");
    startText.setCharacterSize(50);
    startText.setFillColor(sf::Color::White);
    startText.setPosition({ 250.f, 300.f });

    window.clear(sf::Color::Black); 
    window.draw(titleText);
    window.draw(startText);
    window.display();
}
