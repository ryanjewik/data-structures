#include "MonoStack.h"
#include <iostream>
#include <string>


//MonoStack constructor
template <typename T>
MonoStack<T>::MonoStack(int iSize, char m_direction){
    stackArr = new T[iSize];
    maxSize = iSize;
    this->m_direction = m_direction;
    count = 0;
    top = -1; //because we will be preincrementing we start with -1 so that the first element can be placed in 0
    bottom = 0; //just used for printing
    std::cout<<"monostack created" << std::endl;
}


//MonoStack destructor
template <typename T>
MonoStack<T>::~MonoStack(){
    delete[] stackArr;
    std::cout << "MonoStack destructor called" << std::endl;
}

//returns true if full
template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}

//returns true if empty
template <typename T>
bool MonoStack<T>:: isEmpty(){
    return (count == 0);
}

//returns size of the MonoStack
template <typename T>
int MonoStack<T>::size(){
    return count;
}


//adds element to the stack
template <typename T>
void MonoStack<T>::push(T c){
    T comparisonValue;
    bool addValue;
    if (m_direction == 'd'){ // decreasing monostack
        if(isEmpty()){//adds first value if empty
            ++count;
            ++top;
            stackArr[top] = c;
        }else {//if not empty
            for (int i = top; i >= 0; i--){//checks the top value downward
                if (stackArr[i] > c){// if the value in the array is greater than the one being added, add it
                    addValue = true;
                }
                else if(stackArr[i] < c){// if the value in the array is less than the one being added, don't
                    addValue = false;                  
                    ++top;
                    pop();
                    stackArr[top] = c;
                    break;
                }
            }
            if (addValue == true){
                    ++count;
                    ++top;
                    stackArr[top] = c;
            }
        }

}
    else if(m_direction == 'i'){//increasing monostack
        if(isEmpty()){//adds first value if empty
            stackArr[count] = c;
            ++count;
            ++top;
           
        }else {//if not empty
            for (int i = top; i >= 0; i--){//checks the top value downward
                if (stackArr[i] < c){ // if the value in the array is less than the one being added, add it
                    addValue = true;
                    
                    
                }
                else if(stackArr[i] > c){ // if the values in the array is greater than the one being added, don't
                    addValue = false;
                    ++top;
                    pop();
                    stackArr[top] = c;
                    break;
                }
            }
            if (addValue == true){
                    ++count;
                    ++top;
                    stackArr[top] = c;
            }
        }
        if (size() == 0){
            ++count;
        }
    }else{//if invalid direction
        std::cout <<"invalid direction please use 'i' or 'd'." << std::endl;
    }
}


//moves top
template <typename T>
T MonoStack<T>::pop(){
    
    
    return stackArr[top--]; //uses decrement because once you remove an item from the top the top is technically one less
    
}


//looks at the top
template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top--];
}