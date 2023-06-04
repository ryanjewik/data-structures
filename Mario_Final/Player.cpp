#include "Player.h"
#include <iostream>
#include <string>

//constructor
Player::Player(int m_lives){

    this->m_lives = m_lives;
    m_powerLevel = 0;
}

//destructor
Player::~Player(){
    std::cout << "Player destructor called" << std::endl;
}


//adds a turn every move made
void Player::setTotalTurns(){
    m_totalTurns += 1;
}
//tallies wins per level to potentially add a life
void Player::setWinCount(int w){
    m_winCount = w;
}
//returns win count
int Player::getWinCount(){
    return m_winCount;
}

//returns lives
int Player::getLives(){
    return m_lives;
}

//sets the lives to the integer passed in
void Player::setLives(int c){
    m_lives =c;
}

//sets the number of coins to the integer passed in
void Player::setCoins(int c){
    m_coins =c;
}
//returns the number of coins the player has
int Player::getCoins(){
    return m_coins;
}
//returns the player power level
int Player::getPowerLevel(){
    return m_powerLevel;
}
//adjusts the player power level to what is passed in
void Player::setPowerLevel(int c){
    m_powerLevel = c;
}

//increments a turn
void Player::addTurn(){
    m_totalTurns +=1;
}

int Player::getTotalTurns(){
    return m_totalTurns;
}