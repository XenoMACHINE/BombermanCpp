#include <iostream>

int WIDTH = 8;
int HEIGHT = 6;
int DELAY = 6;
int RADIUS = 5;
int BOMBS = 10;

int nbPlayers = 0;

bool nextInputMustBe(std::string input){
    std::string message;
    std::getline(std::cin, message);
    if (message == input){
        return true;
    }
    return false;
}

std::string input(){
    std::string message;
    std::getline(std::cin, message);
    return message;
}

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
    std::cout << message << std::endl;
}

void println(std::string message, int number){
    std::cout << message << number << std::endl;
}

void sendSettings(){
    println("START settings");
    println("NB_BOMBS ",BOMBS);
    println("BOMB_DURATION ",DELAY);
    println("BOMB_RADIUS ",RADIUS);
    println("STOP settings");
}

void sendGrid(){
    //TEST
    println("########");
    println("#__1_3_#");
    println("#___o__#");
    println("#o_____#");
    println("#___2__#");
    println("#4_____#");
    println("########");
}

std::string intStr(int i){
    return std::to_string(i);
}

int main() {

    nextInputMustBe("START PLAYERS");
    nbPlayers = std::stoi(input());
    nextInputMustBe("STOP PLAYERS");

    sendSettings();

    int turn = 1;
    while (true){

        for(int i=1; i<nbPlayers+1;i++){
            std::cout << "START turn " << turn << " " << i << std::endl;
            if(turn == 5){
                println("WINNER ", 3);
            } else{
                std::cout << WIDTH << " " << HEIGHT << std::endl;
                sendGrid();
            }
            std::cout << "STOP turn " << turn << " " << i << std::endl;

            std::string expectInput = "START actions " + intStr(turn) + " " + intStr(i);
            if (nextInputMustBe(expectInput)){
                std::string action = input();
                //TODO exec actionsto
                expectInput = "STOP actions " + intStr(turn) + " " + intStr(i);
                nextInputMustBe(expectInput);
            }
        }

        if (turn == 5){
            break;
        }

        turn++;
    }

    return 0;
}