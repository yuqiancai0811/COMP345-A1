#include "GameEngine2.h"


GameEngine2::GameEngine2() {
    currentState = "START";
    printWelcomeMessage();
}

void GameEngine2::handleStartup() {
    // Start阶段
    std::cout << "Game is starting, loading the map...\n";

    // 地图加载阶段
    while (currentState == "START") {
        std::cout << "Please enter the name of the map you want to load: ";
        std::string mapName;
        std::cin >> mapName;

        selectedMap = selectedMap -> loadMapFromFile(mapName);
        bool result =  (selectedMap == nullptr); // 使用你的 loadMap() 函数判断是否成功
        if (!result) {
            std::cout << "Map " << mapName << " loaded successfully!\n";
            currentState = "MAP_LOADED";
        } else {
            std::cout << "Failed to load the map. Please try again.\n";
        }
    }

    // 地图验证阶段
    while (currentState == "MAP_LOADED") {
        std::cout << "Validating the map...\n";
        
        
        bool mapValidated = selectedMap->validate(); 
        
        if (mapValidated) {
            std::cout << "Map validated successfully!\n";
            currentState = "ADD_Player";
        } else {
            std::cout << "Map validation failed. Please load a valid map.\n";
            currentState = "START"; // 回到地图加载阶段
        }
    }

    // 玩家添加阶段
    while (currentState == "ADD_Player") {
        std::cout << "Please add players (type 'addplayer') or 'play' to start the game: ";
        std::string playerCommand;
        std::cin >> playerCommand;

        if (playerCommand == "addplayer") {
            std::cout << "Please Enter player name: ";
            std::string playerName;
            std::cin >> playerName;
            Player* newPlayer = &Player(playerName);
            playerList.push_back(newPlayer);
            // Need check player name?????????????????????????????????????

            std::cout << "Player added.\n";
        } else if (playerCommand == "play") {
            std::cout << "All players added. Starting the game...\n";
            currentState = "PLAY";
        } else {
            std::cout << "Invalid command. Please add players or type 'play' to start.\n";
        }
    }

    // 游戏进入Play阶段
    if (currentState == "PLAY") {
        std::cout << "The game is now in Play mode!\n";
        promptNextAction(); // 提示下一步操作
    }
}

void GameEngine2::handleUserCommand(const std::string& command) {
    if (command == "startup") {
        currentState = "START";
        handleStartup();
    } else {
        std::cout << "Invalid command. Please type 'startup' to start the game.\n";
    }
}

void GameEngine2::printWelcomeMessage() const {
    std::cout << "Welcome to the Warzone game!\n";
    std::cout << "Type 'start' to start the game.\n";
}

void GameEngine2::promptNextAction() const {
    // 在Play阶段下的操作
    std::cout << "Issue orders by typing 'issueorder'.\n";
}

