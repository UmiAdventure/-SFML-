#include "Start.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

int main() {
    // 1. 先跑开始界面
    Start start;
    start.update(1.f);

    // 2. 再创建主游戏窗口并启动游戏
    //sf::RenderWindow gameWindow(sf::VideoMode({ 800, 600 }, 32), "Debug Adventure");
    //Game game;         // 改造 Game 构造函数接收窗口引用
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