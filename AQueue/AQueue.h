#ifndef AQUEUE_H
#define AQUEUE_H

template<typename T>
class AQueue{
    public:
        AQueue(int size);
        ~AQueue();
        void add(T data);
        T remove(); 
        T peak();
        bool isFull();
        bool isEmpty();
        int size();


    private:
        int maxSize;
        int front;
        int back;
        T* arr;
        int count;

};


template<typename T>
AQueue<T>::AQueue(int s){
    maxSize = s;
    front = 0;
    back = -1;
    count = 0;
    arr = new T[maxSize];
}

template<typename T>
AQueue<T>::~AQueue(){
    delete[]arr;
}

template<typename T>
bool AQueue<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool AQueue<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
int AQueue<T>::size(){
    return count;
}

template <typename T>
void AQueue<T>::add(T data){
    arr[++back] = data;
    ++count;
}

template <typename T>
T AQueue<T>::remove(){
    T ret = arr[front];
    ++front;
    --count;
    return ret;
}

template<typename T>
T AQueue<T>::peak(){
    T ret = arr[front];
    return ret;
}

#endif