#include "GameObject.h"

GameObject::GameObject()
    : position(0.f, 0.f), state(true), positionX(0.f), positionY(0.f) {
    // Ĭ����״���ã���ѡ��
    shape.setSize({ 50.f, 50.f });
    shape.setFillColor(sf::Color::Blue);
}
//void GameObject::render(sf::RenderWindow& window) {
//    window.draw(shape);
//}
