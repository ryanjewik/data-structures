#include <iostream>
#include "FileProcessor.h"
#include <fstream>
using namespace std;

//default constructor
FileProcessor::FileProcessor(){
}

//destructor
FileProcessor::~FileProcessor(){
    std::cout<<"The File Processor Destructor has been called" << std::endl;
}


//reads and writes onto files
void FileProcessor::processFile(std::string userInputFile, std::string userOutputFile){
    std::string myText;
    ifstream myFile;
    ofstream oFile;
    Translator* m_translator = new Translator();
    std::string fileText;
    myFile.open(userInputFile, ios::in);
    std::string temp;

    //reads the input file
    while(myFile.is_open() == true){
        //std::cout<<"a" << std::endl;
        myFile >> temp;
        fileText += temp;
        if (myFile.eof()){
            break;
        }
        fileText +=" ";
    }
    
    

   //writes the original string to the output file
    oFile.open(userOutputFile, ios::out);
    oFile << "<HTML>";
    oFile << "<p><b>" << fileText << "</b></p>";
    oFile << "</HTML>";
    

    //run the string modifier (translateEnglishSentence)
    fileText = m_translator->translateEnglishSentence(fileText);
    

    //writes the modified string to the output file
    oFile << "<HTML>";
    oFile << "<p><em>" << fileText << "</em></p>";
    oFile << "</HTML>";
    myFile.close();
    
}

/*
int main(){
    FileProcessor fileprocessor;
    fileprocessor.processFile("test.txt.txt", "blank.html");

    return 0;
}
*/
