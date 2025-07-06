#pragma once
#include <SFML/Graphics.hpp>
#include"GameObject.h"

class PhysicsObject :public GameObject {
protected:
    sf::Vector2f     velocity;
    float            gravity;
    

public:
    
};