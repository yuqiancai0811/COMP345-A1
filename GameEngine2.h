#ifndef GAMEENGINE2_H
#define GAMEENGINE2_H

#include <string>
#include <iostream>
#include "Map.h"
#include "Cards.h"
#include "Orders.h"
#include "Player.h"
#include <vector>

class GameEngine2 {
    
    private:
    std::string currentState;
    Map* selectedMap;
    std::vector<Player*>playerList;


public:
    GameEngine2(); // 构造函数，初始化为 "START"
    ~GameEngine2();
    void handleStartup(); // 处理游戏启动流程
    void handleUserCommand(const std::string& command); // 处理用户输入的初始命令
    void printWelcomeMessage() const; // 打印欢迎消息
    void promptNextAction() const; // 提示下一步操作





};

#endif 