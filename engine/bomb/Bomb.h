//
// Created by Alexandre Ménielle on 12/07/2018.
//

#ifndef BOMBERMANCPP_BOMB_H
#define BOMBERMANCPP_BOMB_H


class Bomb {
private:
    int x;
    int y;
public:
    Bomb(int x, int y);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
};


#endif //BOMBERMANCPP_BOMB_H
