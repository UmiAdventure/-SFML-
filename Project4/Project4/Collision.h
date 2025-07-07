#pragma once
#include <SFML/Graphics/Rect.hpp>
#include "Player.h"
#include "Obstacle.h"

namespace Collision
{
    // ── 通用 AABB 判交（适配 SFML‑3 的 position + size） ──────────
    inline bool intersects(const sf::FloatRect& a, const sf::FloatRect& b)
    {
        const float ax1 = a.position.x;
        const float ay1 = a.position.y;
        const float ax2 = ax1 + a.size.x;
        const float ay2 = ay1 + a.size.y;

        const float bx1 = b.position.x;
        const float by1 = b.position.y;
        const float bx2 = bx1 + b.size.x;
        const float by2 = by1 + b.size.y;

        return ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1;
    }

    // 玩家 ↔ 障碍物
    inline bool checkPlayerObstacleCollision(const Player& p, const Obstacle& o)
    {
        return intersects(p.getBounds(), o.getBounds());
    }
}
