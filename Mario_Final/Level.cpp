#include "Level.h"
#include <iostream>
#include <string>
#include <fstream>


//creates an array for the player to traverse filled with characters corresponding to items
Level::Level(int dimensions, int pCoins, int pNothing, int pGoombas,
    int pKoopas, int pMushrooms, int currentLevel, int totalLevels, std::string outFile, Player* p1){
    fileName = outFile;
    lostGame = false;
    oFile.open(fileName, std::ios::out);
    oFile << "Level: " << currentLevel << std::endl;
    continueLevel = true;  
    pp1 = p1;
    this->currentLevel = currentLevel;
    this->totalLevels = totalLevels;


    //initializing variables
    this -> dimensions = dimensions;
    this -> xLocation = xLocation;
    this -> yLocation = yLocation;
    map = new char*[dimensions];
    for (int i = 0; i < dimensions; ++i){
        map[i] = new char[dimensions];
    }


    
    //populates grid to be each level
    
    int placeWhat;

    for (int i = 0; i < dimensions; ++i){ // places character based on what random  number is generated
        for (int j = 0; j < dimensions; ++j){
            placeWhat = (rand()%100);
            std::cout << placeWhat;

            if (placeWhat >= 0 && placeWhat < pCoins){
                map[i][j] = 'c';
                std::cout << "     placing coin" << std::endl;
            }
            else if (placeWhat >= pCoins && placeWhat <  pCoins + pNothing){
                map[i][j] = 'x';
                std::cout << "     placing nothing" << std::endl;

            }
            else if (placeWhat >= pCoins + pNothing && placeWhat <  pCoins + pNothing + pMushrooms){
               map[i][j] = 'm';
               std::cout << "     placing mushroom" << std::endl;

            }
            else if (placeWhat >= pCoins + pNothing + pMushrooms && placeWhat < pCoins + pNothing + pMushrooms + pGoombas){
               map[i][j] = 'g';
               std::cout << "     placing goomba" << std::endl;

            }
            else if (placeWhat >= pCoins + pNothing + pMushrooms + pGoombas  && placeWhat < pCoins + pNothing + pMushrooms + pGoombas + pKoopas){
               map[i][j] = 'k';
               std::cout << "     placing koopa" << std::endl;

            }
            else{
                std::cout << "failed" << std::endl;
            }
            

        }
    }

    //add warp pipe & boss

    //adds warp pipe checks for last level
    if (currentLevel != totalLevels){
    xLocation = (rand()%dimensions);
    yLocation = (rand()%dimensions);
    map[xLocation][yLocation] = 'w';
    }

    //adds boss if warp pipe is not there
    xLocation = (rand()%dimensions);
    yLocation = (rand()%dimensions);
    while (map[xLocation][yLocation] == 'w'){
        xLocation = (rand()%dimensions);
        yLocation = (rand()%dimensions);
    }
    map[xLocation][yLocation] = 'b';




    //add hero
    xLocation = (rand()%dimensions);
    yLocation = (rand()%dimensions);
    oFile << "Location: " << xLocation << " " << yLocation << std::endl;
    map[xLocation][yLocation] = 'h';
    xReplace = xLocation;
    yReplace = yLocation; //will be used to replace old location
    }



//level destructor
Level::~Level(){
    for (int i = 0; i < dimensions; ++i){
        delete map[i];
    }
    delete map;
    std::cout<<"Level destructor called"<< std::endl;
}



int Level::getCurrentLevel(){
    return currentLevel;
}




//prints the level
void Level::printLevel(){
    
    for (int i =0; i < dimensions; ++i){//loops through and adds character with random chance
        for (int j = 0; j < dimensions; ++j){
            std::cout << map[i][j] << " ";
            oFile << map[i][j] << " ";
        }
        std::cout << std::endl;
        oFile << std::endl;
        
    }
    std::cout<<getCurrentLevel() << std::endl;
    std::cout << std::endl;
}   



//if the character tries to move out of bounds it "warps" the character to the otherside
void Level::wrap(){
    if (dimensions <= xLocation){
        xLocation = 0;

    }
    else if (dimensions <= yLocation){
        yLocation = 0;

    }
    else if (0 > xLocation){
        xLocation = dimensions -1;

    }
    else if (0 > yLocation){
        yLocation = dimensions -1;

    }
    
}





void Level::playerMove(){
    //finds the player, moves the player and checks what they land on, call other methods accordingly
    pp1->addTurn();
    oFile << "Power Level: " << std::to_string(pp1->getPowerLevel()) << std::endl;
    std::cout << "power level: " << pp1->getPowerLevel() << std::endl;
    std::cout << "lives: " << pp1->getLives() << std::endl;
    std::cout << "coins: " << pp1->getCoins() << std::endl;
    std::cout << "win count: " << pp1->getWinCount() << std::endl;
    std::cout << "player moved" << std::endl;
    int direction(rand()%4);
    xReplace = xLocation;
    yReplace = yLocation;
    


    //adjusts x and y coordinates based on the random number generated
    switch(direction){
        case 0:
            xLocation -=1;
            wrap();
            oFile << "Mario is moving up" << std::endl;
           break;
        case 1:
            ++xLocation;
            wrap();
            oFile << "Mario is moving down" << std::endl;
           break;
        case 2:
            yLocation -= 1;
            wrap();
            oFile << "Mario is moving left" << std::endl;
          break;
        case 3: 
            ++yLocation;
            wrap();
            oFile << "Mario is moving right" << std::endl;
           break;
    }

    //replaces the old space with an X and places the H in the new location
    map[xReplace][yReplace] = 'x'; //replaces old location
    landOn(map[xLocation][yLocation]);  
    if (lostGame == true){
        oFile << "Mario lost the game.";
    }
}


//checks what the character has landed on and calls methods depending on what character

void Level::landOn(char letter){
    switch (letter){//lands on Koopa
        case 'k':
        landEnemy();
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        break;
        case 'g': // lands on Goomba
        landEnemy();
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        break;
        case 'w': //lands on warp pipe
        oFile << "Mario warped." << std::endl;
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        break;
        case 'b': // lands on Boss
        landBoss();
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        if (currentLevel == totalLevels && continueLevel == false){
            oFile << "Mario fought the boss and won the game." << std::endl;
            oFile << "Total Turns: " << pp1->getTotalTurns() << std::endl;
        }
        break;
        case 'x': //lands on Nothing
        landNothing();
        oFile << "Mario landed on nothing." << std::endl;
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        break;
        case 'm': //lands on Mushroom
        landMushroom();
        oFile << "Mario ate a mushroom." << std::endl;
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        break;
        case 'c': //lands on Coin
        landCoin();
        oFile << "Mario collected a coin." << std::endl;
        oFile << "Number of lives: " << std::to_string(pp1->getLives()) << std::endl;
        oFile << "Number of coins: " << std::to_string(pp1->getCoins()) << std::endl;
        printLevel();
        break;
    }
}


//methods for when our hero lands on a specific character


//adds coin and checks if the player has 20 to potentially add a life
void Level::landCoin(){

    std::cout << "landed on coin" << std::endl;
    if(pp1->getCoins() == 20){
        pp1->setLives(pp1->getLives()+1);
        pp1->setCoins(0);
    }
    else{
        pp1->setCoins(pp1->getCoins()+1);
    }
    map[xReplace][yReplace] = 'x';
    map[xLocation][yLocation] = 'h';
    
}

void Level::landEnemy(){//if the user lands on an enemy and checks for Goomba or Koopa

    std::cout << "landed on enemy" << std::endl;
    if(map[xLocation][yLocation] == 'g'){ // if goomba.
        std::cout << "landed on goomba" << std::endl;
        int fightChance = (rand()%100 + 1);
        if (fightChance <= 20){
            oFile << "Mario fought a Goomba and lost." << std::endl;
            if (pp1->getPowerLevel() != 0){
                pp1->setPowerLevel(pp1->getPowerLevel()-1);
                std::cout << "lost powerlevel, moves on" << std::endl;
                //respawn goomba, mario moves on *
                xReplace = xLocation;
                yReplace = yLocation;
                
                playerMove();
                map[xReplace][yReplace] = 'g';
            } else {

                if(pp1->getLives() == 0){
                    std::cout << "lost game" << std::endl;
                    continueLevel = false;
                } else { // respawns and (maybe fights goomba again) **
                pp1->setLives(pp1->getLives()-1);
                    std::cout << "lost life, retry" << std::endl;
                    if (pp1->getLives() != 0){
                    oFile << "Mario stays put and fights again" << std::endl;
                    landEnemy();
                    }
                }
            }
        } else {
            pp1->setWinCount(pp1->getWinCount()+1);// number of enemies mario defeated
            if (pp1->getWinCount() == 7){
                pp1->setLives(pp1->getLives()+1);
                pp1->setWinCount(0);
                
            }
            map[xReplace][yReplace] = 'x';
            map[xLocation][yLocation] = 'h';
            std::cout << "GOOMBA DOWN" << std::endl;
        }
    }
    if(map[xLocation][yLocation] == 'k'){ // if koopa

        std::cout << "landed on koopa" << std::endl;
        int fightChance = (rand()%100 + 1);
        if (fightChance <= 35){
            oFile << "Mario fought a Koopa and lost." << std::endl;
            if (pp1->getPowerLevel() != 0){
                pp1->setPowerLevel(pp1->getPowerLevel()-1);
                std::cout << "lost powerlevel, moves on" << std::endl;
                xReplace = xLocation;
                yReplace = yLocation;
                //map[xReplace][yReplace] = 'k';
                playerMove();
                map[xReplace][yReplace] = 'k';
                //respawn KOOPA, mario moves on 
            } else {
                if(pp1->getLives() == 0){
                    std::cout << "lost game" << std::endl;
                    continueLevel = false;
                    
                } else { // respawns and (maybe fights KOOPA again)
                    pp1->setLives(pp1->getLives()-1);
                    std::cout << "lost life, retry" << std::endl;
                    if (pp1->getLives() != 0){
                    oFile << "Mario stays put and fights again" << std::endl;
                    landEnemy();
                    }
                }
            }
        } else {
            oFile << "Mario fought a Koopa and won." << std::endl;
            pp1->setWinCount(pp1->getWinCount()+1);// number of enemies mario defeated
            if (pp1->getWinCount() == 7){
                pp1->setLives(pp1->getLives()+1);
                pp1->setWinCount(0);
            }
            map[xReplace][yReplace] = 'x';
                        map[xLocation][yLocation] = 'h';
            std::cout << "KOOPA DOWN" << std::endl;

        }
    }
}

void Level::landMushroom(){//adds life
    std::cout << "landed on mushroom" << std::endl;
    if (pp1->getPowerLevel() != 2){
        pp1->setPowerLevel(pp1->getPowerLevel()+1);
    }
    map[xReplace][yReplace] = 'x';
    map[xLocation][yLocation] = 'h';

}

void Level::landNothing(){//does nothing but tells the user they landed on nothing
    std::cout << "landed on nothing" << std::endl;
    map[xReplace][yReplace] = 'x';
    map[xLocation][yLocation] = 'h';
}


void Level::landPipe(){ //takes player to the next level
    std::cout << "landed on pipe" << std::endl;
    continueLevel = false;

}


void Level::landBoss(){
    std::cout<< "landed on boss" << std::endl;
    int fightChance = (rand()%100 + 1);
    if (fightChance <= 50){
        oFile << "Mario fought the boss and lost." << std::endl;
        if (pp1->getPowerLevel() != 0 && pp1->getPowerLevel() != 1){
            pp1->setPowerLevel(pp1->getPowerLevel()-2);
            //respawn BOSS, mario fights again
            oFile << "Mario lost two power levels and fights again" << std::endl;
            std::cout << "You lost 2 power levels, must fight the boss again" << std::endl;
            landBoss();
        } else {//if the user runs out of lives after losing to the boss end the game
            if(pp1->getLives()-1 == 0){
                pp1->setLives(pp1->getLives()-1);
                continueLevel = false;
            } else { // respawns the player but takes away a life
                pp1->setLives(pp1->getLives()-1);
                std::cout<<"you lost a life, fight again!" << std::endl;
                oFile << "Mario loses a life and fights again" << std::endl;
                landBoss();
            }
        }
    } else if (currentLevel != totalLevels) {
        oFile << "Mario fought the boss and won." << std::endl;
        oFile << "Total Turns: " << pp1->getTotalTurns() << std::endl;
        pp1->setWinCount(pp1->getWinCount()+1);// number of enemies mario defeated
        //MARIO GOES TO NEXT LEVEL
        if (pp1->getWinCount() == 7){
            pp1->setLives(pp1->getLives()+1);
            pp1->setWinCount(0);
        }
        std::cout << "BOSS DOWN" << std::endl;
        continueLevel = false;
        }else{//writes to file that theey beat the boss and won + the total turns
            oFile << "Mario fought the boss and won." << std::endl;
            oFile << "Total Turns: " << pp1->getTotalTurns() << std::endl;
            oFile.close();
            std::cout << "You win the game!" << std::endl;
            continueLevel = false;
        }
}
    
    //bool to continue the level, true to continue and false to end
    bool Level::getContinueLevel(){
        return continueLevel;
    }
    //changes continueLevel to false
    void Level::setContinueLevel(){
        continueLevel = false;
    }
    //changes the variable lostGame to true and writes to file that game is lost
    void Level::setLostGame(){
        lostGame = true;
        oFile << "Total Turns: " << pp1->getTotalTurns() << std::endl;
    }
