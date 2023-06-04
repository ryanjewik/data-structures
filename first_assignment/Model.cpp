//using namespace std;
#include <iostream>
#include "Model.h"
#include <string>

//default constructor
Model::Model(){
}

//destructor
Model::~Model(){
    std::cout<<"Model destructor called" << std::endl;
}

//alters the consonant
std::string Model::translateSingleConsonant(char singleLetter){
    std::string outputStr1 = "";
    outputStr1 = outputStr1 + singleLetter + 'o' + singleLetter;
    return outputStr1;
}


//leaves vowels alone, also applies to symbols and numbers
std::string Model::translateSingleVowel(char singleLetter){
    std::string outputStr1 = "";
    outputStr1 = outputStr1 + singleLetter;
    return outputStr1;
}


