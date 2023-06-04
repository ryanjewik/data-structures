#include "ACStack.h"

ACStack::ACStack(int iSize){
    stackArr = new char[iSize];
    maxSize = iSize;
    count = 0;
    top = -1; //because we will be preincrementing we start with -1 so that the first element can be placed in 0
}

ACStack::~ACStack(){
    delete[] stackArr;
}

bool ACStack::isFull(){
    return (count == maxSize);
}

bool ACStack:: isEmpty(){
    return (count == 0);
}

int ACStack::size(){
    return count;
}

void ACStack::push(char c){
    if(isFull()){
        char* temp = new char [2*maxSize];
        for (int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *=2;
        delete[] stackArr;
        stackArr = temp;

    }
    stackArr[++top] = c;
    ++count;
}

char ACStack::pop(){
    return stackArr[top--]; //uses decrement because once you remove an item from the top the top is technically one less
    --count;
}

char ACStack::peek(){
    return stackArr[top];
}

