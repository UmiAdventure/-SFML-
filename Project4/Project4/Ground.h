#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdexcept>


class Ground {
public:
    explicit Ground(float groundY);
    void update(float dt);
    void render(sf::RenderWindow& window) const;
    // ��ȡָ��xλ�õĵ��θ߶�
    float getHeightAt(float x) const {
        return y - 50.0f * std::sin(x * 0.01f + totalTime * 2.0f);
    }
    // ��ȡ��ʱ�䣨�����ⲿ���㣩
    float getTotalTime() const { return totalTime; }
    // ��ȡ��׼Y����
    float getY() const { return y; }
    float getX() const { return xPos; }
private:
    std::vector<sf::RectangleShape> segments;
    float speed;
    float segmentHeight;
    float totalTime;
    float y;
    float xPos;
};