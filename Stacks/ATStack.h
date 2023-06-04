#ifndef ATSTACK_H
#define ATSTACK_H


template <typename T> 
class ATStack{
    public:
        ATStack(int iSize);
        ~ATStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isFull();
        bool isEmpty();
        int size();

        private:
        char* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};

template <typename T>
ATStack<T>::ATStack(int iSize){
    stackArr = new char[iSize];
    maxSize = iSize;
    count = 0;
    top = -1; //because we will be preincrementing we start with -1 so that the first element can be placed in 0
}

template <typename T>
ATStack<T>::~ATStack(){
    delete[] stackArr;
}

template <typename T>
bool ATStack<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool ATStack<T>:: isEmpty(){
    return (count == 0);
}

template <typename T>
int ATStack<T>::size(){
    return count;
}

template <typename T>
void ATStack<T>::push(T c){
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

template <typename T>
T ATStack<T>::pop(){
    --count;
    return stackArr[top--]; //uses decrement because once you remove an item from the top the top is technically one less
    
}

template <typename T>
T ATStack<T>::peek(){
    return stackArr[top];
}


#endif