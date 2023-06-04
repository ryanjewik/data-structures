#ifndef DBLLIST_H
#define DBLLIST_H

#include "ListNode.h"

template <typename T>
class DblList{
    public:
        DblList();
        virtual ~DblList();
        int size();
        bool isEmpty();
        void addFront(T data);
        void addBack(T data);
        void add(T data, int position);
        T get(int position);
        T removeFront();
        T removeBack();
        T remove(int position);

    private:
    ListNode<T>* m_front; //list node pointer that points to the front
    ListNode<T>* m_back; //list node pointer that points to the back
    ListNode<T>* m_prev;
    int m_size;
};

template<typename T>
DblList<T>::DblList(){
    m_front =NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
DblList<T>::~DblList(){
    //loop through to delete each node
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
int DblList<T>::size(){
    return m_size;
}

template<typename T>
bool DblList<T>::isEmpty(){
    return (m_size ==0);
}

template<typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if (!isEmpty()){
        newNode->m_next = m_front;
        m_front->m_prev = newNode;
    }else{
        m_back = newNode;
    }
    m_front = newNode;
    ++m_size;
}
template<typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        m_back->m_next = newNode;
        newNode->m_prev = m_back;
    }else{
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template<typename T>
void DblList<T>::add(T data, int position){
    if(isEmpty()){
        addFront(data);
    }else if(position ==0){
        addFront(data);
    }else if(position >= m_size){
        addBack(data);
    }else{
        ListNode<T>* current = m_front;
        int cPosition = 0;
        while (cPosition !=position){
            current = current->m_next;
            ++cPosition;
        }
        ListNode<T>* newNode =  new ListNode<T>(data);
        current->m_prev->m_next = newNode;
        newNode->m_prev = current->m_prev;
        current->m_prev = newNode;
        newNode->m_next = current;
        ++m_size;
    }
}

template<typename T>
T DblList<T>::removeFront(){
    T data = m_front->m_data;
    if (m_size == 1){
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currFront = m_front;
        m_front = m_front->m_next;
        m_front = m_prev = NULL;
        delete currFront;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::removeBack(){
    T data = m_back->m_data;
    if(m_size ==1){
        delete m_back;
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currBack = m_back; //line 128 for the prof
        m_back = m_back-> m_prev;
        m_back -> m_next = NULL;
        delete currBack;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::remove(int position){
    T data;
    if (position == 0){
        data = removeFront();
    }else if(position >= m_size -1){
        data  =removeBack();
    }else{
        ListNode<T>* current = m_front;
        int cPosition = 0;
        while(cPosition != position){
            current = current->m_next;
            ++cPosition;
        }
        data = current ->m_data;
        current -> m_prev->m_next = current->m_next;
        current -> m_next->m_prev = current->m_prev;
        delete current;
    }
    --m_size;
    return data;
}

template <typename T>
T DblList<T>::get(int position){
    ListNode<T>* current = m_front;
    int cPosition = 0;
    while(cPosition != position){
        current = current->m_next;
        ++cPosition;
    }
    return current->m_data;
}

#endif