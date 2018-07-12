//
// Created by Alexandre Ménielle on 12/07/2018.
//

#ifndef BOMBERMANCPP_BOMB_H
#define BOMBERMANCPP_BOMB_H


class Bomb {
private:
    int x;
    int y;
    int timer = 0;
public:
    int getTimer() const;

    void setTimer(int timer);

public:
    Bomb(int x, int y, int timer);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    void decrement();
};


#endif //BOMBERMANCPP_BOMB_H
