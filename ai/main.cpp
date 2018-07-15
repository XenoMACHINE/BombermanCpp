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


int number_Bombs;
int duration_Bombs;
int radius_Bombs = 2;


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

int MyCharToInt(char nbChar)
{
    switch (nbChar)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}

string IaAlgorithm(int height, int width)
{
    vector<vector<int>> map(width, vector<int>(height, 0));
    vector<vector<int>> map_decision(width, vector<int>(height, 0));

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

                        for (int h = 1; h <= radius_Bombs; h++)
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
                        if (MyCharToInt(c) == idPlayer)
                        {
                            map[indexH][index] = 2;
                            map_decision[indexH][index] = 2;
                            xPlayer = indexH;
                            yPlayer = index;
                        }
                        else
                        {
                            map[indexH][index] = 1;
                            map_decision[indexH][index] = 1;
                        }
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
            if (inputSetting.substr(0, inputSetting.find(" ")) == "NB_BOMBS")
            {
                string nbStr = inputSetting.substr(1, inputSetting.find(" "));
                number_Bombs = stoi(nbStr);
            }
            if (inputSetting.substr(0, inputSetting.find(" ")) == "BOMB_DURATION")
            {
                string nbStr = inputSetting.substr(1, inputSetting.find(" "));
                duration_Bombs = stoi(nbStr);
            }
            if (inputSetting.substr(0, inputSetting.find(" ")) == "BOMB_RADIUS")
            {
                string nbStr = inputSetting.substr(1, inputSetting.find(" "));
                radius_Bombs = stoi(nbStr);
            }
        } while(inputSetting != "STOP settings");
    }

    int turn = 1;

    while (true){
        std::string message;

        std::string expectedInput = "START turn " + intStr(turn);
        if(nextInputMustBe(expectedInput)) {
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

        /*grid.push_back("####################");
        grid.push_back("#__________________#");
        grid.push_back("#___o______________#");
        grid.push_back("#__________________#");
        grid.push_back("#_____________o____#");
        grid.push_back("#__________________#");
        grid.push_back("#__________________#");
        grid.push_back("#_________________o#");
        grid.push_back("#______o___________#");
        grid.push_back("#__________________#");
        grid.push_back("#____2_____________#");
        grid.push_back("#_____________o____#");
        grid.push_back("#__________________#");
        grid.push_back("#______________o___#");
        grid.push_back("#1_________________#");
        grid.push_back("#__________________#");
        grid.push_back("#___o______________#");
        grid.push_back("#__________________#");
        grid.push_back("#__________________#");
        grid.push_back("####################");
        width = 20;
        height = 20;*/

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

        if (turn % 2 == 0) {
            player.randomAction(1);
        }

        if(turn % 3 == 0){
            player.sendBomb();
        }

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

