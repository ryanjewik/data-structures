#ifndef ListStack_H
#define ListStack_H


template <typename T> 
class ListStack{
    public:
        ListStack();
        ~ListStack();
        void push(T c); //add to the top
        T pop(); //remove from the top
        T peek(); //return the top without removing
        bool isEmpty();

        
        int size();

        private:
        //ListNode<T>*
        char* stackArr;
        int count; //number of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //index of the current top of the stack
};

template <typename T>
ListStack<T>::ListStack(){
    stackArr = new char[iSize];
    maxSize = iSize;
    count = 0;
    top = -1; //because we will be preincrementing we start with -1 so that the first element can be placed in 0
}

template <typename T>
ListStack<T>::~ListStack(){
    delete[] stackArr;
}



template <typename T>
bool ListStack<T>:: isEmpty(){
    return (count == 0);
}

template <typename T>
int ListStack<T>::size(){
    return m_list->size();
}

template <typename T>
void ListStack<T>::push(T c){
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
T ListStack<T>::pop(){
    --count;
    return stackArr[top--]; //uses decrement because once you remove an item from the top the top is technically one less
    
}

template <typename T>
T ListStack<T>::peek(){
    return stackArr[top];
}


#endif