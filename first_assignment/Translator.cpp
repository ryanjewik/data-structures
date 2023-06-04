#include <iostream>
#include <cstdlib>
#include "Translator.h"
#include <ctype.h>
#include <string>



//default constructor
Translator::Translator(){
    m_model = new Model();
}

//destructor
Translator::~Translator(){
    delete m_model;
    std::cout<<"Translator destructor called" << std::endl;
}

//checks if the character is a vowel
bool Translator::isVowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return true;
    }
    else{
        return false;
    }
}


//checks for a vowel, then for a consonant, then everything else.
std::string Translator::translateEnglishWord(std::string singleWord){
    std::string outputStr = "";
    
    

    for (int i = 0; i < singleWord.length(); i++){
        
        if (isVowel(singleWord[i])==true){
            outputStr += m_model->translateSingleVowel(singleWord[i]);
        }
        else if (isalpha(singleWord[i]) != 0){
            outputStr += m_model->translateSingleConsonant(singleWord[i]);
        }
        else{
            outputStr += m_model->translateSingleVowel(singleWord[i]);
        }
        

    }

    return outputStr;
}

//functions identically to the "translateEnglishWord" because the above method accounts for spaces
std::string Translator::translateEnglishSentence(std::string sentence){
    std::string outputStr = "";
    
    for (int i = 0; i < sentence.length(); i++){
        if (isVowel(sentence[i])==true){
            outputStr += m_model->translateSingleVowel(sentence[i]);
        }
        else if (isalpha(sentence[i]) != 0){
            outputStr += m_model->translateSingleConsonant(sentence[i]);
        }
        else{
            outputStr += m_model->translateSingleVowel(sentence[i]);
        }
    }
    
    
    return outputStr;
}

