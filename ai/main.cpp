#include <iostream>
#include <vector>
#include <stdlib.h>
#include "player/Player.h"
#include "player/Astar.h"


using namespace std;

Player player = Player(0);
int idPlayer = 0;
int width = 0;
int height = 0;
std::vector<std::string> grid;
int radius = 4;


void println(std::string message){
    std::cout << message << std::endl;
}

void println(std::string message, int number){
    std::cout << message << number << std::endl;
}

void sendGrid(){
    for (int i = 0; i < height; i++) {
        println(grid.at(i));
    }
}

std::string input(){
    std::string message;
    std::getline(std::cin, message);
    return message;
}

bool nextInputMustBe(std::string input){
    std::string message;
    std::getline(std::cin, message);
    if (message == input){
        return true;
    }
    return false;
}

std::string intStr(int i){
    return std::to_string(i);
}


string IaAlgorithm(int height, int width)
{
    vector<vector<int>> map(width, vector<int>(height, 0));
    vector<vector<int>> map_decision(width, vector<int>(height, 0));


    //Setting map
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            map[i][j] = 0;
            map_decision[i][j] = 0;
        }
    }

    int xPlayer;
    int yPlayer;

    int indexH = 0;
    for (auto line : grid)
    {
        int index = 0;

        for (char& c : line)
        {
            if (indexH < height && index < width)
            {
                switch (c)
                {
                    case '_': //Empty
                        if (map[indexH][index] != 1)
                            map[indexH][index] = 0;
                        if (map_decision[indexH][index] != 1)
                            map_decision[indexH][index] = 0;
                        break;
                    case '#': //Wall
                        map[indexH][index] = 1;
                        map_decision[indexH][index] = 1;
                        break;
                    case 'o': //Bomb

                        map[indexH][index] = 1;
                        map_decision[indexH][index] = 1;

                        for (int h = 1; h <= radius; h++)
                        {
                            if (indexH + h < height)
                                map_decision[indexH + h][index] = 1;
                            if (index + h < width)
                                map_decision[indexH][index + h] = 1;
                            if (indexH - h > 0)
                                map_decision[indexH - h][index] = 1;
                            if (index + h > 0)
                                map_decision[indexH][index - h] = 1;
                        }
                        break;
                    default: //Player
                        map[indexH][index] = 2;
                        map_decision[indexH][index] = 2;
                        xPlayer = indexH;
                        yPlayer = index;
                        break;
                }
            }
            index += 1;
        }
        indexH += 1;
    }

    //Pass map to Astar Object
    Astar astar(height, width, xPlayer, yPlayer);
    astar.map = map;

    astar.searchDestination(map_decision);

    string resultPath = astar.findPath(astar.xDest, astar.yDest);

    //0 Bas; 1Droite; 2Haut; 3Gauche

    return resultPath;

}


int main() {

    std::string message;

    if(nextInputMustBe("START player")) {
        std::getline(std::cin, message);
        idPlayer = std::stoi(message);
        nextInputMustBe("STOP player");
    }

    player = Player(idPlayer);

    if(nextInputMustBe("START settings")) {
        std::string inputSetting;
        do {
            std::getline(std::cin, inputSetting);
            //TODO use settings
        } while(inputSetting != "STOP settings");
    }

    int turn = 1;

    while (true){
        std::string message;

        std::string expectedInput = "START turn " + intStr(turn);
        if(nextInputMustBe(expectedInput)) {
            //TODO set grid ect
            std::cin >> message;
            width = std::stoi(message);
            std::cin >> message;
            height = std::stoi(message);

            std::string stopTurnInput = "STOP turn " + intStr(turn);
            grid.clear();
            while (true){
                std::string inputGrid = input();
                if(inputGrid == stopTurnInput)
                    break;
                if(inputGrid.size() == width){
                    grid.push_back(inputGrid);
                }
            }
        }

        player.startAction(turn);

        string resDecision = IaAlgorithm(height, width);

        for (auto c : resDecision)
        {
            if (c == '0')
                player.goDown();
            if (c == '1')
                player.goRight();
            if (c == '2')
                player.goUp();
            if (c == '3')
                player.goLeft();
        }

        if (turn % 2 == 0)
            player.randomAction(1);

        /*
        player.randomAction(1);
        if(turn % 2 == 0){
            player.sendBomb();
            player.randomAction(2);
        }
        */

        player.stopAction(turn);
        turn += 1;
    }

}

