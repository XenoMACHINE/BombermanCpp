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
        std::cin >> message;

        if(message == "START"){
            mode = "start";
        }else if(message == "STOP"){
            mode = "wait";
        }

        if (mode == "start"){
            if(message == "PLAYERS"){
                mode = "players";
            }
        }else{
            if(mode == "players"){
                nbPlayers = std::stoi(message);
                std::cout << "nbPlayers : " << nbPlayers << "\n";
            }
        }
        println("mode " + mode);

    }


    return 0;
}