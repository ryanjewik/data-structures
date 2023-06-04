#ifndef ACSTACK_H
#define ACSTACK_H

class ACStack{
    public:
        ACStack(int iSize);
        virtual ~ACStack();
        void push(char c); //add to the top
        char pop(); //remove from the top
        char peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();

        private:
        char* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};





#endif