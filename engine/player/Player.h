//
// Created by Alexandre Ménielle on 12/07/2018.
//

#ifndef BOMBERMANCPP_PLAYER_H
#define BOMBERMANCPP_PLAYER_H


class Player {
private:
    int id;
    int x;
    int y;
    bool bomber = false;
    bool alive = true;
public:
    bool isAlive() const;

    void setAlive(bool alive);

public:
    bool isBomber() const;

    void setBomber(bool bomber);

public:
    Player(int id);

    Player(int id, int maxX, int maxY);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getId() const;

    void setId(int id);
};


#endif //BOMBERMANCPP_PLAYER_H
