#pragma once
#include <SFML/Graphics.hpp>
#include <optional>

class GameState {
public:
    virtual ~GameState() = default;

    virtual void processEvents() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;

    // ���봰�����ã�״̬����ָ���������ã����Լ���������������
    void setWindow(sf::RenderWindow& win) { window = &win; }

protected:
    sf::RenderWindow* window = nullptr;
};
