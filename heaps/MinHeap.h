#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <typename T>
class MinHeap{
    public:
    MinHeap(int c) //c is the capacity of the array
    virtual ~MinHeap();
    void insert(T k)
    T getMin();
    void deleteMin();
    bool isEmpty();

    private:
    T* m_heap;
    int m_size; //how many things are in the heap
    int m_cap; //the max capacity of the heap
    int getLeftIdx(int i);
    int getRightIdx(int i);
    int getParentIdx(int i);
}
template<typename T>
MinHeap<T>::MinHeap(int c){
    m_size =0;
    m_cap = c;
}

template<typename T>
MinHeap<T>::~MinHeap(){
    delete[] m_heap;
}

template <typename T>
T MinHeap<T>::getMin(){
    //check for an empty heap (throw an exception)
    return m_heap[0];
}

template <typename T>
T MinHeap<T>::getLeftIdx(int i){
    return (2 * i + 1)
}

template <typename T>
T MinHeap<T>::getRightIdx(int i){
    return (2 * i + 2)
}
template <typename T>
T MinHeap<T>::getParentIdx(int i){
    return ((i -1)/2);
}

template <typename T>
bool MinHeap<T>::isEmpty(){
    return (m_size ==0);
}

template <typename T>
int MinHeap<T>::
#endif