//
// Created by Alexandre Ménielle on 12/07/2018.
//

#include <cstdlib>
#include "Player.h"

Player::Player(int id) {
    this->id = id;
}

Player::Player(int id, int maxX, int maxY) {
    this->id = id;
    this->x = rand() % maxX + 1;
    this->y = rand() % maxY + 1;
}

int Player::getX() const {
    return x;
}

int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}

void Player::setX(int x) {
    Player::x = x;
}

int Player::getY() const {
    return y;
}

void Player::setY(int y) {
    Player::y = y;
}

bool Player::isBomber() const {
    return bomber;
}

void Player::setBomber(bool bomber) {
    Player::bomber = bomber;
}

bool Player::isAlive() const {
    return alive;
}

void Player::setAlive(bool alive) {
    Player::alive = alive;
}
