#include "Player.h"
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

const int BOMB_CODE = 97;
const int WEAK_WALL_CODE = 19;
const int WALL_CODE = 99;
const int NO_WAY_CODE = 98;

const char LEFT = 'L';
const char RIGHT = 'R';
const char TOP = 'U';
const char BOTTOM = 'D';

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

Player::Player(int id) {
    this->id = id;
}

int getRandom(int min, int max){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    auto random_integer = uni(rng);
    return random_integer;
}

void Player::startAction(const int& turn) const {
    std::cout << "START action " << turn << std::endl;
}

void Player::stopAction(const int& turn) const {
    std::cout << "STOP action " << turn << std::endl;
}


void Player::doNothing() const {
    std::cout << "NOACTION" << std::endl;
}

void Player::sendBomb() {
    std::cout << "B" << std::endl;
}

void Player::goUp()  {
    std::cout << "U" << std::endl;
}

void Player::goDown()  {
    std::cout << "D" << std::endl;
}

void Player::goLeft()  {
    std::cout << "L" << std::endl;
}

void Player::goRight() {
    std::cout << "R" << std::endl;
}

void Player::randomAction(int maxActions) {
    int nbActions = getRandom(1,maxActions);
    for (int i=0; i<nbActions; i++){
        switch (getRandom(0,5)){
            case 0:
                doNothing();
                break;
            case 1:
                goUp();
                break;
            case 2:
                goDown();
                break;
            case 3:
                goRight();
                break;
            case 4:
                goLeft();
                break;
            case 5:
                sendBomb();
                break;
        }
    }
    std::cout << "R" << std::endl;
}

void expectMessage(const std::string& message) {
    std::string input;
    std::getline(std::cin, input);

    if (input != message) {
        std::cout << "Expected input was '" + message + "', '" + input + "' received";
        throw std::exception();
    }
}

void Player::initPlayer(int id) {
    expectMessage("START player");
    this->id = id;
    expectMessage("STOP player");
}

void Player::initSettings() {
    expectMessage("START settings");

    std::string inputSetting;
    do {
        std::getline(std::cin, inputSetting);
        // TODO : use setting
    } while(inputSetting != "STOP settings");
}