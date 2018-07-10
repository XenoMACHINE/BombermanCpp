#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H


#include <string>

class Player {

private:
    int id;

    void initPlayer(int id);
    void initSettings();
    void startAction(const int& turn) const;
    void stopAction(const int& turn) const;

public:
    Player(int id);
    void play(const int& turn);
    void sendBomb();
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void doNothing() const;
};


#endif
