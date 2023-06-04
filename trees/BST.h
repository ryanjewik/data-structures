#ifndef BST_H
#define BST_H

#include <TreeNode.h>
//#include <cstlib>
#include <iostream>
using namespace std;

template <typename T>
class BST{
    public:
    BST();
    virtual ~BST();
    int getSize();
    bool contains(T d);
    void remove(T d);
    void insert(T d);

    void printTreeInOrder();
    void printTreePostOrder();
    T getMin();
    T getMinHelper(TreeNode<T>* currNode);
    T getMax();
    T getMaxHelper(TreeNode<T>* currNode);
    void remove(T d);

    private:
    int m_size;
    TreeNode<T>* m_root;
    bool containsHelper(TreeNode<T>* currNode, T d);
    void insertHelper(TreeNode<T>* currNode, T d);
    T getMedian();
    void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
    TreeNode<T>* getSuccessor(TreeNode<T>* node);
    

};

template <typename T>
BST<T>::BST(){
    m_root = NULL;
    m_size = 0;
}

template <typename T>
BST<T>::~BST(){

}

template <typename T>
int BST<T>::getSize(){
    return m_size;
}

/*
template <typename T> //iterative solution
bool BST<T>::contains(t d){//assuming no repeated values
    if (m_root == NULL){
        return false;
    }
    if (m_root -> m_data == d){
        return true;
    }
    bool found = false;
    TreeNode<T>* current = m_root;
    while (!found){
        if (d > current->data){
            current = current->m_right;
        }else{
            current = current->m_left;
        }
    }
    if (current ==NULL){
        found = false;
        break;
    }
}
*/

template <typename T> 
bool BST<T>::contains(T d){
    return containsHelper(m_root, d);
}

template <typename T> //recursive solution
bool BST<T>::containsHelper(TreeNode<T>* currNode, T d){
    if (currNode == NULL){
        return false;
    }else if (d < currNode -> m_data){
        return containsHelper(currNode->m_left, d);
    }else if (d > currNode -> m_data){
        return containsHelper(currNode->m_right, d);
    }else{
        return true;
    }
}

template <typename T>
void BST<T>::insert(T d){
    TreeNode<T> newNode = new TreeNode<T>(d);
    insertHelper(m_root, newNode);
    ++m_size;
}

template <typename T>
void BST<T>::insertHelper(TreeNode<T>* currNode, T d){
    if(currNode == NULL){
        currNode = newNode;
    }else if(newNode->m_data < currNode->m_data){
        insertHelper(currNode->m_left, newNode);
    }else if(newNode->m_data > currNode->m_data){
        insertHelper(currNode->m_right, newNode);
    }
}

template <typename T>
T BST<T>::getMin(){
    //check if empty
    return getMinHelper(m_root);
}

template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if (subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }
    else{
        return getMinHelper(subTreeRoot->m_left);
    }
}

template <typename T>
T BST<T>::getMax(){
    //check if empty
    return getMaxHelper(m_root);
}

template <typename T>
T BST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if (subTreeRoot->right == NULL){
        return subTreeRoot->m_data;
    }
    else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}

template <typename T>
T BST<T>::getMedian(){
    //check if empty
    return m_root->m_data;
}

template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if (key < target->m_data){
            target = target->m_left;
        }else{
            target = target->right;
        }
    }
}

template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* node){
    
}


template <typename T>
void BST<T>::remove(T d){
    //check if empty
    TreeNode<T>* parent = NULL;
    TreeNode<T>* target = NULL;
    target - m_root;
    findTarget(d,target,parent);
    if(target==NULL){//value wasn't in tree, nothing to do
        return;
    }

    //check if leaf
    if (target->m_left == NULL && target->m_right == NULL){ // no children
        if (target == m_root){//leaf is the root of tree
            m_root = NULL;
        }else{ // it's not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
        delete target; //free the memory
    } else if(target->m_left != NULL && target->m_right != NULL){//2 child case
        TreeNode<T>* suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value); // remove successor
        target->m_data = value;
    }else{ // 1 child
        TreeNode<T>* child;
        if (target->m_left != NULL){
            child = target->m_left;
        }else{
            child = target->m_right;
        }
        if(target == m_root){
            m_root = child;
        }else{
            if(target ==parent->m_left){
                parent->m_left = child;
            }else{
                parent->m_right = child;
            }
        }
        delete target;
    }
    --m_size;
}


#endif