#ifndef MonoStack_H
#define MonoStack_H
#include <iostream>
#include <string>

template <typename T> 
class MonoStack{
    public:
        MonoStack(int iSize, char m_direction);
        ~MonoStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();
        char m_direction;

        private:
        T* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
        int iLength;
        int iHeight;
        int bottom; //just used for printing
};

#endif