#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H


#include <string>

class Player {

private:
    int id;

    void initPlayer(int id);
    void initSettings();

public:
    Player(int id);
    void sendBomb();
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void randomAction(int maxActions);
    void randomMov(int maxActions);
    void doNothing() const;
    void startAction(const int& turn) const;
    void stopAction(const int& turn) const;
};


#endif
