#include "Start.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

int main() {
    // 1. ���ܿ�ʼ����
    Start start;
    start.update(1.f);

    // 2. �ٴ�������Ϸ���ڲ�������Ϸ
    //sf::RenderWindow gameWindow(sf::VideoMode({ 800, 600 }, 32), "Debug Adventure");
    //Game game;         // ���� Game ���캯�����մ�������
    //game.run();

    return 0;
}


//#include "Game.h"
//#include <stdexcept>
//#include <SFML/Graphics.hpp>
//#include "Start.h"
//
//int main() {
//    Game game;
//    game.run();
//    return 0;
//}