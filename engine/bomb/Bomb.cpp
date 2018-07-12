//
// Created by Alexandre Ménielle on 12/07/2018.
//

#include "Bomb.h"

Bomb::Bomb(int x, int y) : x(x), y(y) {}

int Bomb::getX() const {
    return x;
}

void Bomb::setX(int x) {
    Bomb::x = x;
}

int Bomb::getY() const {
    return y;
}

void Bomb::setY(int y) {
    Bomb::y = y;
}
