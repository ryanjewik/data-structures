#if !defined(FileProcessor_h)
#include <iostream>
#define FileProcessor_h
#include "Translator.h"

class FileProcessor{
    public:
    FileProcessor();
    virtual ~FileProcessor();
    void processFile(std::string userInputFile, std::string userOutputFile);
    
    private:
    std::string inFile;
    std::string outFile;
    Translator* m_translator;
};
#endif