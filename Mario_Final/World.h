#ifndef WORLD_H
#define WORLD_H
#include "Level.h"
#include "Player.h"

class World{
    public:
    World(std::string fileName, std::string outFile);
    virtual ~World();
    int getStageLevels();
    Level** stage;
    Player* p1;
    void printWorld();
    void readFile(std::string fileName);
    //int getCurrentLevel();
    int getTotalLevels();
    void setCurrentLevel(int c);
    int getCurrentLevel();
    //void gameOver();
    //bool getGameOver();

    private:
    int stageLevels;
    int dimensions;
    int lives;
    int pCoins;
    int pNothing;
    int pGoombas;
    int pKoopas;
    int pMushrooms;
    int m_currentLevel;
    bool gameContinue;
    
    //Level campaign[stageLevels];


};
#endif