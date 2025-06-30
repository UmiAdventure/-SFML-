#pragma once
#include <SFML/Graphics.hpp>
#include <random>  // ����ͷ�ļ�
#include <vector>
#include "Player.h"
#include "Ground.h"
#include "Obstacle.h"
#include "Config.h"
#include "Ground.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdexcept>

class Game {
public:
    //explicit Game(sf::RenderWindow& win);  // ��������
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
    //O
// bstacle        obstacle;
    std::vector<Obstacle> obstacles;  // �������ϰ���
    float spawnTimer;           // ��ʱ��
    float nextSpawnTime;        // ��һ����ʾ�����ʱ��
    sf::Texture  backgroundTexture;
   // sf::Sprite   backgroundSprite;
    enum class State { Playing };
    State state;
};