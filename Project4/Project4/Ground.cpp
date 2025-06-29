#include "Ground.h"
Ground::Ground(float groundY) : speed(200.f), segmentWidth(200.f), y(groundY) {
    // ���� 4 �����εؿ�ƴ�� (800px ����)
    for (int i = 0; i < 4; ++i) {
        sf::RectangleShape seg;
        seg.setSize(sf::Vector2f(segmentWidth, 5.f));
        seg.setFillColor(sf::Color::Black);
        seg.setPosition(sf::Vector2f(i * segmentWidth, y));
        segments.push_back(seg);
    }
}
void Ground::update(float dt) {
    for (auto& seg : segments) {
        seg.move(sf::Vector2f(-speed * dt, 0.f));
        // �����������Ƶ����Ҳ�
        if (seg.getPosition().x + segmentWidth < 0.f) {
            float maxX = 0.f;
            for (auto& s : segments) {
                maxX = std::max(maxX, s.getPosition().x);
            }
            seg.setPosition(sf::Vector2f(maxX + segmentWidth, y));
        }
    }
}
void Ground::render(sf::RenderWindow& window) const {
    for (const auto& seg : segments) window.draw(seg);
}