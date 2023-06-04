#include "World.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

World::World(std::string fileName, std::string outFile){

    m_currentLevel = 0;
    readFile(fileName);
    this->lives = lives;
    std::cout << "lives: "<< lives << std::endl;
    p1 = new Player(lives); //player object
    std::cout << p1->getLives() << std::endl;
    this->stageLevels = stageLevels;
    std::cout << "stagelevels: " << stageLevels << std::endl;
    //will also create the levels
    stage = new Level*[stageLevels]; //creates the pointer
    srand(time(0));
    for (int i =0; i < stageLevels; ++i){
        stage[i] = new Level(dimensions, pCoins, pNothing, pGoombas, pKoopas ,pMushrooms, i +1, stageLevels, outFile, p1);
    }
    
}


//world destructor
World::~World(){
    for (int i = 0; i < stageLevels; ++i){
        delete stage[i];
    }
    delete stage;
    //delete player;
    std::cout<<"World destructor is called" << std::endl;
}



//prints the array of levels

void World::printWorld(){
    for (int i =0; i < stageLevels; ++i){
        stage[i]->printLevel();
        //stage[i]->
        std::cout<< '\n';
    }
}




//reads input file
void World::readFile(string fileName){
    ifstream inFile;
    inFile.open(fileName, ios::in);
    std::string sL;
    std::string sN;
    std::string sV;
    std::string spCoins;
    std::string spNothing;
    std::string spGoombas;
    std::string spKoopas;
    std::string spMushrooms;
    getline(inFile, sL);
    getline(inFile, sN);
    getline(inFile, sV);
    getline(inFile, spCoins);
    getline(inFile, spNothing);
    getline(inFile, spGoombas);
    getline(inFile, spKoopas);
    getline(inFile, spMushrooms);
    inFile.close();
    stageLevels = stoi(sL); // number of levels
    dimensions = stoi(sN); // dimension of the grid
    lives = stoi(sV); // number of initial lives
    pCoins = stoi(spCoins); // percentage of the positions in each level with coins
    pNothing = stoi(spNothing); // percentage of the positions in each level with nothing
    pGoombas = stoi(spGoombas); // percentage of the positions in each level with Goombas
    pKoopas = stoi(spKoopas); // percentage of the positions in each level with Koopas
    pMushrooms = stoi(spMushrooms); // percentage of positions in each level with Mushrooms
    if (pCoins + pNothing + pGoombas + pKoopas + pMushrooms != 100) {
        cout << "the values of the percentages does not add up to 100." << endl;
        exit (3);
    } 
}

//returns total levels
int World::getTotalLevels(){
    return stageLevels;
}


//adjusts current level the player is on
void World::setCurrentLevel(int c){
    m_currentLevel = c;
}
//returns the current level the player is on
int World::getCurrentLevel(){
    return m_currentLevel;
}




//main

int main(int argc, char** argv){
    std::string fileName = argv[1];
    std::string outFile = argv[2];
    World w1(fileName, outFile);


    //prints all of the worlds
    w1.printWorld();
    //std::cout << w1.p1->getLives() << std::endl;


    //takes us through the levels once pipe or boss is completed, ends game if no lives
  for (int i = 0; i < w1.getTotalLevels(); ++i){
    while (w1.stage[w1.getCurrentLevel()]->getContinueLevel() == true){//if the bool continueLevel is true
        if (w1.getCurrentLevel() <= w1.getTotalLevels()){ //if you are not on the last level
            if (w1.p1->getLives() > 0){
            w1.stage[w1.getCurrentLevel()]->playerMove();
        }
        else if (w1.p1->getLives() <= 0){//if the user is out of lives end the game
            std::cout<<"game over" << std::endl;
            w1.stage[i]->setContinueLevel();
            w1.stage[i]->setLostGame();
            
        }
        
    }
    }
    w1.setCurrentLevel(w1.getCurrentLevel() + 1);
  }
  
    
    return 0;
}