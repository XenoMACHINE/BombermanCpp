#include <iostream>

void initSettings(){
    std::cout << "START settings" << std::endl;
    std::cout << "NB_BOMBS " << "5" << std::endl;
    std::cout << "BOMB_DURATION " << "5" << std::endl;
    std::cout << "BOMB_RADIUS " << "2" << std::endl;
    std::cout << "STOP settings" << std::endl;
}

void initPlayers(){
    std::cout << "START players" << std::endl;
    std::cout << "STOP players" << std::endl;
}

int main() {
    initSettings();
    initPlayers();
    return 0;
}