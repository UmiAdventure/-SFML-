#pragma once
#include <SFML/Graphics.hpp>
#include <random>  // ����ͷ�ļ�
#include <vector>
#include "Player.h"
#include "Ground.h"
#include "Obstacle.h"
class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(float dt);
    void render();
    void spawnObstacle();
    float generateRandomTime();

    sf::RenderWindow window;
    Player          player;
    Ground          ground;
    //Obstacle        obstacle;
    std::vector<Obstacle> obstacles;  // �������ϰ���
    float spawnTimer;           // ��ʱ��
    float nextSpawnTime;        // ��һ����ʾ�����ʱ��
    
    enum class State { Playing };
    State state;
};