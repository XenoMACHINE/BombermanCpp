#include <iostream>
#include <vector>
#include <random>
#include "player/Player.h"
#include "bomb/Bomb.h"

int WIDTH = 20;
int HEIGHT = 20;
int DELAY = 6;
int RADIUS = 5;
int BOMBS = 10;

int nbPlayers = 0;
std::vector<std::string> grid;
std::vector<Player> players;
std::vector<Bomb> bombs;

int getRandom(int min, int max){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    auto random_integer = uni(rng);
    return random_integer;
}

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
    for (int i = 0; i < HEIGHT; i++) {
        println(grid.at(i));
    }
}

std::string intStr(int i){
    return std::to_string(i);
}

void addElement(int x, int y, std::string c){ //Add bomb/player
    std::string line = grid.at(y);
    std::string newLine;
    for (int i = 0; i < WIDTH; i++) {
        if(i != x){
            newLine += line[i];
        }else{
            newLine += c;
        }
    }
    grid.at(y) = newLine;
}

std::string getWallLine(){
    std::string line;
    for (int i = 0; i < WIDTH; i++) {
        line += "#";
    }
    return line;
}

std::string getLine(){
    std::string line = "#";
    for (int i = 1; i < WIDTH-1; i++) {
        line += "_";
    }
    return line + "#";
}


bool isPositionFree(int x, int y){
    if (grid.at(y)[x] == '_'){
        return true;
    }
    return false;
}

void initPlayers(){
    players.clear();
    for (int i = 0; i < nbPlayers; i++) {
        Player player = Player(i+1);
        do{
            int x = getRandom(1,WIDTH-1);
            int y = getRandom(1,HEIGHT-1);
            player.setX(x);
            player.setY(y);
        }while(isPositionFree(player.getX(),player.getY()) == false);
        players.push_back(player);
    }
}

void addPlayerToGrid(){
    for (Player player : players) {
        int playerNumber = player.getId();
        if (player.isBomber())
            playerNumber += 4;
        addElement(player.getX(), player.getY(), intStr(playerNumber));
    }
}

void initGrid(){
    std::string line;
    grid.clear();
    grid.push_back(getWallLine());
    for (int i = 1; i < HEIGHT-1; i++) {
        grid.push_back(getLine());
    }
    grid.push_back(getWallLine());
}


int getPlayerIndex(int id){
    for (int i = 0; i < players.size(); i++) {
        if (players.at(i).getId() == id){
            return i;
        }
    }
    return 0;
}

void addBombsToGrid(){
    for (Bomb bomb : bombs) {
        addElement(bomb.getX(), bomb.getY(), "o");
    }
}

void refreshGrid(){
    initGrid();
    addPlayerToGrid();
    addBombsToGrid();
}

void reinitBombers(){
    for (int i = 0; i < players.size(); i++) {
        players.at(i).setBomber(false);
    }
}

void execActions(std::string action, int playerId){
    int index = getPlayerIndex(playerId);
    int x = players.at(index).getY();
    int y = players.at(index).getY();

    if (action == "NOACTION"){
        return;
    }
    if (action == "U"){
        if(grid.at(y-1)[x] == '_'){
            players.at(index).setY(y-1);
        }else if (grid.at(y-1)[x] == 'o'){
            //TODO BOOM
        }
    }
    if (action == "D"){
        if(grid.at(y+1)[x] == '_'){
            players.at(index).setY(y+1);
        }else if (grid.at(y+1)[x] == 'o'){
            //TODO BOOM
        }
    }
    if (action == "L"){
        if(grid.at(x-1)[x] == '_'){
            players.at(index).setY(x-1);
        }else if (grid.at(y)[x-1] == 'o'){
            //TODO BOOM
        }
    }
    if (action == "R"){
        if(grid.at(x+1)[x] == '_'){
            players.at(index).setY(x+1);
        }else if (grid.at(y)[x+1] == 'o'){
            //TODO BOOM
        }
    }
    if (action[0] == 'B'){
        int xBomb = 0, yBomb = 0;
        std::string xStr, yStr;
        bool xFound = false;
        for (int i=1; i<action.length(); i++){
            if(action[i] != '-'){
                if (xFound){
                    yStr += action[i];
                }else{
                    xStr += action[i];
                }
            }else{
                xFound = true;
            }
        }
        xBomb = std::stoi(xStr);
        yBomb = std::stoi(yStr);
        if(xBomb > 0 && yBomb > 0){
            bombs.push_back(Bomb(xBomb,yBomb));
            players.at(index).setBomber(true);
        }
    }

    refreshGrid();
}

int main() {
    /*
    //TESTS perso
    nbPlayers = 4;
    initGrid();
    initPlayers();
    addPlayerToGrid();

    bool b = true;

    while (true){
        reinitBombers();
        println("player y : ", players.at(getPlayerIndex(2)).getY());
        sendGrid();
        execActions("U",2);
        if(b){
            execActions("B4-12",2);
            b = false;
        }
    }
    */

    nextInputMustBe("START PLAYERS");
    nbPlayers = std::stoi(input());
    nextInputMustBe("STOP PLAYERS");

    initGrid();
    initPlayers();
    addPlayerToGrid();

    sendSettings();

    int turn = 1;
    while (true){
        reinitBombers();
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
                execActions(action, i);
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