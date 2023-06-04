#ifndef LEVEL_H
#define LEVEL_H
#include <fstream>
#include <iostream>
#include "Player.h"

class Level
{
    public:
    Level(int dimensions, int pCoins, int pNothing, int pGoombas,
    int pKoopas, int pMushrooms, int currentLevel, int totalLevels, std::string fileName, Player* pp1);
    virtual ~Level();
    int getDimensions();
    void landEnemy();
    void landNothing();
    void landMushroom();
    void landCoin();
    void landPipe();
    void landBoss();
    void playerMove();
    void wrap();
    void printLevel();
    void landOn(char letter);
    int getCurrentLevel();
    bool getContinueLevel();
    void setContinueLevel();
    Player* pp1;
    int xReplace;
    int yReplace;
    bool lostGame;
    void setLostGame();

    private:
    int dimensions;
    int pCoins;
    int pNothing;
    int pGoombas;
    int pKoopas;
    int pMushrooms;
    int xLocation;
    int yLocation;
    int enemiesDefeated = 0;
    char** map;
    int currentLevel;
    bool continueLevel;
    std::string fileName;
    int totalLevels;
    std::ofstream oFile;
};
#endif