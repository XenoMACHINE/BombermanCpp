//
// Created by Alexandre Ménielle on 12/07/2018.
//

#include "Bomb.h"

Bomb::Bomb(int x, int y, int timer) : x(x), y(y), timer(timer){}

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

void Bomb::decrement() {
    if (this->timer > 0){
        this->timer--;
    }
}

int Bomb::getTimer() const {
    return timer;
}

void Bomb::setTimer(int timer) {
    Bomb::timer = timer;
}
