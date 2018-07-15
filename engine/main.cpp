#include <iostream>
#include <vector>
#include <random>
#include "player/Player.h"
#include "bomb/Bomb.h"

int WIDTH = 10;
int HEIGHT = 10;
int DELAY = 2;
int RADIUS = 3;
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
        if(player.isAlive()){
            int playerNumber = player.getId();
            //if (player.isBomber())
            //    playerNumber += 4;
            addElement(player.getX(), player.getY(), intStr(playerNumber));
        }
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

bool isPlayerAlive(int id){
    for (Player player : players){
        if(player.getId() == id){
            return player.isAlive();
        }
    }
    return false;
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
        if(bomb.getTimer() == 1){
            addElement(bomb.getX(), bomb.getY(), "o");
        }
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

int getPlayerIndex(int x, int y){
    std::string str(1,grid.at(y)[x]);
    return getPlayerIndex(std::stoi(str));
}


void clearExplosedBombs(){
    std::vector<Bomb> newBombs;
    for (int i = 0; i < bombs.size(); i++) {
        if(bombs.at(i).getTimer() > 0){
            newBombs.push_back(bombs.at(i));
        }
    }
    bombs.clear();
    bombs = newBombs;
}

void plantBomb(Player player){
    if (bombs.size() >= BOMBS){
        return;
    }
    int x = player.getX(), y =player.getY();
    switch (player.getLastMovement()){
        case 'U':
            if(grid.at(y-1)[x] == '_')
                bombs.push_back(Bomb(x,y-1,DELAY));
            break;
        case 'D':
            if(grid.at(y+1)[x] == '_')
                bombs.push_back(Bomb(x,y+1,DELAY));
            break;
        case 'L':
            if(grid.at(y)[x-1] == '_')
                bombs.push_back(Bomb(x-1,y,DELAY));
            break;
        case 'R':
            if(grid.at(y)[x+1] == '_')
                bombs.push_back(Bomb(x+1,y,DELAY));
            break;
        default:
            if(grid.at(y+1)[x] == '_')
                bombs.push_back(Bomb(x,y+1,DELAY));

    }
}

void updateBombs(){
    for(int i=0; i<bombs.size(); i++) {
        bombs.at(i).decrement();
        Bomb bomb = bombs.at(i);
        if (bomb.getTimer() == 0) {
            //Axes X
            int yBomb = bomb.getY();
            for (int x = bomb.getX() - RADIUS; x < bomb.getX() + RADIUS; x++) {
                if(yBomb < grid.size() && x < grid.at(yBomb).size()){
                    if (grid.at(yBomb)[x] != '_' && grid.at(yBomb)[x] != 'o' && grid.at(yBomb)[x] != '#'){
                        int index = getPlayerIndex(x,yBomb);
                        players.at(index).setAlive(false);
                    }
                }
            }

            //Axes Y
            int xBomb = bomb.getX();
            for (int y = bomb.getY() - RADIUS; y < bomb.getY() + RADIUS; y++) {
                if(y < grid.size() && xBomb < grid.at(yBomb).size()) {
                    if (grid.at(y)[xBomb] != '_' && grid.at(y)[xBomb] != 'o' && grid.at(y)[xBomb] != '#'){
                        int index = getPlayerIndex(xBomb,y);
                        players.at(index).setAlive(false);
                    }
                }
            }
        }
    }
    clearExplosedBombs();
}

void execActions(std::string action, int playerId){
    int index = getPlayerIndex(playerId);
    int x = players.at(index).getX();
    int y = players.at(index).getY();

    if (action == "NOACTION" || players.at(index).isAlive() == false){
        return;
    }
    if (action == "U"){
        if(grid.at(y-1)[x] == '_'){
            players.at(index).setY(y-1);
            players.at(index).setLastMovement('U');
        }
    }
    if (action == "D"){
        if(grid.at(y+1)[x] == '_'){
            players.at(index).setY(y+1);
            players.at(index).setLastMovement('D');
        }
    }
    if (action == "L"){
        if(grid.at(x-1)[x] == '_'){
            players.at(index).setY(x-1);
            players.at(index).setLastMovement('L');
        }
    }
    if (action == "R"){
        if(grid.at(x+1)[x] == '_'){
            players.at(index).setY(x+1);
            players.at(index).setLastMovement('R');
        }
    }
    if (action == "B"){
        plantBomb(players.at(index));
        players.at(index).setBomber(true);
    }
    if (action[0] == 'B' && action.length() > 1){
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
        if(xBomb > 0 && yBomb > 0 && bombs.size() < BOMBS && grid.at(yBomb)[xBomb] == '_'){
            bombs.push_back(Bomb(xBomb,yBomb,DELAY));
            players.at(index).setBomber(true);
        }
    }

    refreshGrid();
}

int nbPlayersAlive(){
    int count = 0;
    for (Player player : players){
        if (player.isAlive())
            count++;
    }
    return count;
}

int main() {

    //TESTS perso
    /*nbPlayers = 4;
    initGrid();
    initPlayers();
    addPlayerToGrid();
    sendGrid();
    bool b = true;

    while (true){
        reinitBombers();
        execActions("U",2);
        if(b){
            execActions("B",2);
            b = false;
        }
        updateBombs();
        refreshGrid();
        sendGrid();
    }*/

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
        updateBombs();
        //for(int i=1; i<nbPlayers+1;i++){
        for(Player player : players){
            int i = player.getId();
            //if (!players.at(getPlayerIndex(i)).isAlive()){ continue; }  //bloquer ici ?
            std::cout << "START turn " << turn << " " << player.getId() << std::endl;
            if(nbPlayersAlive() <= 1 && players.at(getPlayerIndex(i)).isAlive()){
                println("WINNER ", i);
            } else{
                std::cout << WIDTH << " " << HEIGHT << std::endl;
                refreshGrid();
                sendGrid();
            }
            std::cout << "STOP turn " << turn << " " << i << std::endl;

            std::string expectInput = "START actions " + intStr(turn) + " " + intStr(i);
            if (nextInputMustBe(expectInput)){
                expectInput = "STOP actions " + intStr(turn) + " " + intStr(i);
                while (true){
                    std::string action = input();
                    if(action == expectInput)
                        break;
                    //if(isPlayerAlive(i)){
                        execActions(action, i);
                    //}
                }
            }
        }

        if(nbPlayersAlive() <= 1){
            break;
        }

        turn++;
    }

    return 0;
}