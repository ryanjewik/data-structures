#if !defined(Translator_h)
#include <iostream>
#define Translator_h
#include "Model.h"

class Translator{
    public:
    Translator();
    virtual ~Translator();
    std::string translateEnglishWord(std::string singleWord);
    std::string translateEnglishSentence(std::string sentence);
    private:
    bool isVowel(char c);
    Model* m_model;

};
#endif