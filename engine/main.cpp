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

void println(std::string message){
    std::cout << message << "\n";
}

int main() {
    std::string message;
    std::string mode = "wait";
    int nbPlayers = 0;

    while (true){
        std::getline(std::cin, message);

        //println(message);
        if(message == "START PLAYERS") {
            mode = "player";
        }
        else if(message == "STOP PLAYERS") {
            mode = "wait";
        }
        else if(mode == "player") {
            nbPlayers = std::stoi(message);
            for (int i = 0; i < nbPlayers; i++) {
                std::cout << "init player " << i << "\n";
            }
        }

        //println("mode " + mode);
    }

    return 0;
}