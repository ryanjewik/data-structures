#include "SpeakerView.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;


//default constructor
SpeakerView::SpeakerView(){
    
}

//overload constructor
SpeakerView::SpeakerView(std::string fileName){
    o = 'd';
    m_fileName = fileName;
    readFile(m_fileName);


}


//SpeakerView destructor
SpeakerView::~SpeakerView(){
    std::cout<<"speaker view destructor called" << std::endl;
}


//reads file and creates an array of the values for us to read
void SpeakerView::readFile(string fileName){
    ifstream inFile;
    inFile.open(fileName, ios::in);

    ifstream fileOpener;
    fileOpener.open(fileName, ios::in);

    std::string tempString;
    int iHeight = 0;
    int iLength = 0;
    std::string firstNextString;
    double dNextString;
    std::string iString;
    double dISS;
    double endDISS;
    std::string prevValue;
    std::string endString;
    std::string bigString;
    std::string lastString;
    std::string lengthFinder;
    std::string len;
    int iLowerLen;
    int iUpperLen;
    double value;
    



    //reads file
    if (inFile.is_open()){
        
        while(!inFile.eof()){

        

        //creates one larger string to hold all of the values and separates them with spaces
        inFile >> tempString;
        if (tempString != lastString){
            bigString += " " + tempString;
            lastString = tempString;
            std::cout << bigString << std::endl;
            }
        }
    }

        

            //need to find the dimensions to create a 2d array
            inFile.close();
            inFile.open(fileName, ios::in);
            fileOpener.open(fileName, ios::in);
            istringstream sss(bigString);

            
            getline(inFile, tempString);
            inFile >> firstNextString;

            //finding the bounds to prevent it from reading the next row
            
            istringstream ss(bigString);
            ss >> len;
            iLowerLen = stoi(len);
            iUpperLen = stoi(firstNextString);
            while(iLowerLen!= iUpperLen ){
            iLength ++;
            ss >> len;
            iLowerLen = stoi(len);
            }
            inFile.close();
            inFile.open(fileName, ios::in);


        while(!inFile.eof()){//every time it gets a line it adds to the height
            ++iHeight;
            getline(inFile, tempString);
            inFile >> firstNextString;
            
            

            
            //sets the value where it should stop reading
            if (prevValue != firstNextString){
                
                //dISS = stod(tempString);
                dNextString = stod(firstNextString);
                //std::cout << dNextString << std::endl;
                prevValue = firstNextString;
                
            }
            std::cout << '\n' << std::endl;
            istringstream s(bigString);
            s >> tempString;
            dISS = stod(tempString);

            for (int i = 0; i < iLength; ++i){
                sss >> tempString;
                std::cout << tempString << std::endl;
            }
        }
    

    //creates a 2d array so it's easy to read and push values into MonoStack
    stands = new double*[iHeight];
    for (int i = 0; i < iHeight; ++i){
        stands[i] = new double[iLength];
    }

    //populates the array to be read
    istringstream ssss(bigString);
    for (int i = 0; i < iHeight; ++i){
        for (int j = 0; j < iLength; ++j){
            ssss >> tempString;
            value = stod(tempString);
            stands[i][j] = value;
        }
    }
        
    inFile.close();


    //creates monostack object and will populate monostack
    
    for (int j = 0; j < iLength; ++j){//populates
        MonoStack<double> mStack(iHeight, 'd');
        for (int i = iHeight -1; i >= 0; --i){
        mStack.push(stands[i][j]);
        }
        //prints
        std::cout << "For column " << j << " there are " << mStack.size() << " people that can see. Their heights are: ";
        
        for (int k = 0; k < mStack.size(); ++k){
            std::cout << mStack.peek() << ", ";
        }
        std::cout << " inches." << std::endl;
    }

    
    
    
}

/*
int main(int argc, char** argv){
    SpeakerView("test.txt");

    return 0;
}
*/
