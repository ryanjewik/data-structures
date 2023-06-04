#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player{
    public:
    Player(int lives);
    virtual ~Player();
    int getName();
    int getLives();
    int getPowerLevel();
    int getCoins();
    int getTotalTurns();
    void addTurn();
    int getWinCount();
    void setTotalTurns();
    void setCoins(int c);
    void setLives(int c);
    void setPowerLevel(int c);
    void setWinCount(int w);


    private:
    //std::string name;
    int m_lives;
    int m_powerLevel;
    int m_coins;
    int m_totalTurns = 0;
    int m_winCount;


};
#endif