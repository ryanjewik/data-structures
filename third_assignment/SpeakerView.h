#ifndef SpeakerView_H
#define SpeakerView_H
#include <string>
#include <iostream>
using namespace std;
#include "MonoStack.h"
#include "MonoStack.cpp"



class SpeakerView{
    public:
        std::string m_fileName;
        int iLength;
        int iHeight;
        void readFile(std::string fileName);
        SpeakerView();
        SpeakerView(std::string fileName);
        virtual ~SpeakerView();
        double**stands;
        //MonoStack(int iSize, char m_direction);
    private:
        char o;
};





#endif