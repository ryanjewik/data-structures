#ifndef Model_h
#define Model_h
#include <iostream>

class Model
{
    public:
    Model();
    virtual ~Model();
    std::string translateSingleConsonant(char singleLetter);
    std::string translateSingleVowel(char singleLetter);

    private:
    

};
#endif