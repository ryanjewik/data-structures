#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>
#include <iostream>

template <typename T>
class TreeNode{
    public:
        TreeNode(T d)
        virtual ~TreeNode();
        TreeNode<T>* m_left;
        TreeNode<T>* m_right;
        T m_data;
};
template <typename T>
TreeNode<T>::TreeNode(T d){
    m_data = d;
    m_left = NULL;
    m_right = NULL;
}


template <typename T>
TreeNode<T>::~TreeNode(){
    //delete m_left
    //delete m_right
}



#endif