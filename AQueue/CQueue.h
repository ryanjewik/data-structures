#ifndef CQUEUE_H
#define CQUEUE_H

//CQueue stands for circular queue?

template<typename T>
class CQueue{
    public:
        CQueue(int size);
        ~CQueue();
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
CQueue<T>::CQueue(int s){
    maxSize = s;
    front = 0;
    back = -1;
    count = 0;
    arr = new T[maxSize];
}

template<typename T>
CQueue<T>::~CQueue(){
    delete[]arr;
}

template<typename T>
bool CQueue<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool CQueue<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
int CQueue<T>::size(){
    return count;
}

template <typename T>
void CQueue<T>::add(T data){
    if (back == maxSize -1){
        back = -1;
    }
    arr[++back] = data;
    ++count;
}

template <typename T>
T CQueue<T>::remove(){
    T ret = arr[front];
    ++front;
    --count;
    if (front == maxSize){
        front =0;
    }
    return ret;
}

template<typename T>
T CQueue<T>::peak(){
    T ret = arr[front];
    return ret;
}

#endif