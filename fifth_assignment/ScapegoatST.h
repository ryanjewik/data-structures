#ifndef SCAPEGOATST_H
#define SCAPEGOATST_H

#include "TreeNode.h"
#include <cmath>


template <typename T>
class ScapegoatST{
public:
  ScapegoatST();
  virtual ~ScapegoatST();
  int getTotalSize();
  void insert(T d);
  void remove(T d);
  bool contains(T d);
  void printTreeInOrder();
  void printTreePostOrder();
  T getMin();
  T getMax();
  T getMedian();
  bool isScapeGoat(TreeNode<T>* subTreeRoot);
  int nodeTreeSize(TreeNode<T>* currRoot, TreeNode<T>* searchRoot);
  TreeNode<T>* getRoot();
  int getSizeAtNode(TreeNode<T>* subTreeRoot);
  double log32;
  int getNodeDepth(TreeNode<T>* subTreeRoot);
  bool rebuildCheck(TreeNode<T>* subTreeRoot);
  void rebuildTree(TreeNode<T>* subTreeRoot, int size);

private:
  int m_size;
  
  TreeNode<T>* m_root;
  T getMinHelper(TreeNode<T>* subTreeRoot);
  T getMaxHelper(TreeNode<T>* subTreeRoot);
  void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
  bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
  void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
  void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
  void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
  TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);

};

template <typename T>
ScapegoatST<T>::ScapegoatST(){
  m_root = NULL;
  m_size = 0;
  log32 = 2.4663034623764317;
}

template <typename T>
ScapegoatST<T>::~ScapegoatST(){
  if(m_root != NULL){
    delete m_root;
  }
}

template <typename T>
int ScapegoatST<T>::getTotalSize(){
  return m_size;
}




template <typename T>
int ScapegoatST<T>::getSizeAtNode(TreeNode<T>* subTreeRoot){
  if (subTreeRoot == NULL){
    return 0;
  }
  return 1 + getSizeAtNode(subTreeRoot->m_left) + getSizeAtNode(subTreeRoot->m_right);
}

template <typename T>
void ScapegoatST<T>::insert(T d){
  //adds the node and adds to the size
  TreeNode<T>* newNode = new TreeNode<T>(d);
  insertHelper(m_root, newNode);
  ++m_size;
  //checks if we must rebalance
}

template <typename T>
void ScapegoatST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    subTreeRoot = newNode;
    rebuildCheck(subTreeRoot);
  } else if(newNode->m_data < subTreeRoot->m_data){
    
    //cout << newNode->m_data << endl;
    newNode->m_parent = subTreeRoot;
    //cout << "parent pointer set to: " <<newNode->m_parent->m_data<< endl;
    insertHelper(subTreeRoot->m_left,newNode);
  } else{
    
    //cout << newNode->m_data << endl;
    newNode->m_parent = subTreeRoot;
    //cout << "parent pointer set to: " <<newNode->m_parent->m_data<< endl;
    insertHelper(subTreeRoot->m_right,newNode);
  }
}

template<typename T>
bool ScapegoatST<T>::rebuildCheck(TreeNode<T>* subTreeRoot){
  
  if (getNodeDepth(subTreeRoot) > (log(getTotalSize()) / (double) log(1.5)) || getNodeDepth(subTreeRoot) < getTotalSize()/2){
    cout << subTreeRoot->m_data << " called scapegoat" << endl;
    
      isScapeGoat(subTreeRoot);
    
  }else{
    cout << "depth: " << getNodeDepth(subTreeRoot) << " size: " << getTotalSize() << endl;
  }

}

template <typename T>
bool ScapegoatST<T>::contains(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  return containsHelper(m_root, newNode);

}

template <typename T>
bool ScapegoatST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
  if(subTreeRoot == NULL){
    return false;
  } else if(newNode->m_data == subTreeRoot->m_data){
    return true;
  } else if(newNode->m_data < subTreeRoot->m_data){
    return containsHelper(subTreeRoot->m_left,newNode);
  } else{
    return containsHelper(subTreeRoot->m_right,newNode);
  }
}

template <typename T>
void ScapegoatST<T>::printTreeInOrder(){
  printTreeInOrderHelper(m_root);
}

template <typename T>
void ScapegoatST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printTreeInOrderHelper(subTreeRoot->m_left);
    cout << subTreeRoot->m_data << endl;
    if (subTreeRoot->m_parent != NULL){
      cout <<"parent data: " << subTreeRoot->m_parent->m_data << endl;
    }else{cout << "no parent" << endl;}
    cout << "node depth: " << getNodeDepth(subTreeRoot) << endl;
    //subTreeRoot->setNodeSize(getSizeAtNode(subTreeRoot));
    //cout << "Node size: " << getSizeAtNode(subTreeRoot) << endl;
    printTreeInOrderHelper(subTreeRoot->m_right);
    //subTreeRoot->setNodeSize(getSizeAtNode(subTreeRoot));
    //cout << "Node size: " << subTreeRoot->getNodeSize() << endl;

  }
  
}

template <typename T>
void ScapegoatST<T>::printTreePostOrder(){
  printTreePostOrderHelper(m_root);
}

template <typename T>
void ScapegoatST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != NULL){
    printTreeInOrderHelper(subTreeRoot->m_left);
    printTreeInOrderHelper(subTreeRoot->m_right);
    cout << subTreeRoot->m_data << endl;
  }
}

template <typename T>
int ScapegoatST<T>::getNodeDepth(TreeNode<T>* subTreeRoot){
  TreeNode<T>* newNode = m_root;
  int depth = 0;

  while (newNode->m_data != subTreeRoot->m_data){

    if (subTreeRoot->m_data == newNode->m_data){
      return depth;
    }
    else if (subTreeRoot->m_data < newNode->m_data){

      depth++;
      newNode = newNode->m_left;
    }else if (subTreeRoot->m_data > newNode->m_data){

      depth++;
      newNode = newNode->m_right;
    }else if (newNode == NULL){
      return -1;
    }
  }
  return depth;
}

template <typename T>
void ScapegoatST<T>::rebuildTree(TreeNode<T>* subTreeRoot, int size){
    int* treeArray[size];
    for (int i = 0; i < size; i++){
      
    }
}


template<typename T>
bool ScapegoatST<T>::isScapeGoat(TreeNode<T>* subTreeRoot){
    if (getSizeAtNode(subTreeRoot->m_parent) / getSizeAtNode(subTreeRoot) >= (double)3/2){
      cout << "scapegoat found on: "<< subTreeRoot->m_data << endl;
      return true;
    }else{
      cout << "no scapegoat here on: " << subTreeRoot->m_data << endl;
      if (subTreeRoot->m_parent != NULL){
      return isScapeGoat(subTreeRoot->m_parent);
      }else{false;}
      }
}

/*
template<typename T>
int ScapegoatST<T>::nodeTreeSize(TreeNode<T>* currRoot, TreeNode<T>* searchRoot){
    //bool searching = true;
    if (currRoot == NULL){
        return -1;
    }else if (currRoot == searchRoot){
        searchRoot->incNodeSize();
        return currRoot->getNodeSize();
    }else if ((currRoot->m_left != NULL && searchRoot ->m_right == NULL)){
        searchRoot->incNodeSize();
        return nodeTreeSize(currRoot->m_left, searchRoot);
    }else if((currRoot->m_left== NULL && currRoot->m_right != NULL)){
        searchRoot->incNodeSize();
        return nodeTreeSize(currRoot->m_right, searchRoot);
    }
    else if (currRoot->m_left != NULL && currRoot->m_right != NULL){
        searchRoot->incNodeSize();
        if (nodeTreeSize(currRoot->m_left, searchRoot) != -1){
            return nodeTreeSize(currRoot->m_left, searchRoot);
        }
        searchRoot->incNodeSize();
        if (nodeTreeSize(currRoot->m_right, searchRoot) != -1){
        return nodeTreeSize(currRoot->m_right, searchRoot);
        }
        
    }else if (currRoot -> m_left == NULL && currRoot -> m_right == NULL){
        return -1;
    }
    
}
*/



/*
template <typename T>
bool ScapegoatST::iterativeContains(T d){
  if(m_root == NULL){
    return false;
  }
  if(m_root->m_data ==  d){
    return true;
  }
  bool found = false;
  TreeNode<T>* currRoot = m_root;
  while(!found){
    if(d < currRoot->m_data){
      currRoot = currRoot->m_left;
    } else{
      currRoot = currRoot->m_right;
    }
    if(currRoot == NULL){
      found = false;
      break;
    }
    if(currRoot->m_data == d){
      found = true;
      break;
    }

  }
  return found;
}
*/

template <typename T>
T ScapegoatST<T>::getMin(){
  //check if empty
  return getMinHelper(m_root);
}

template <typename T>
T ScapegoatST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_left==NULL){
    return subTreeRoot->m_data;
  } else{
    return getMinHelper(subTreeRoot->m_left);
  }
}

template <typename T>
T ScapegoatST<T>::getMax(){
  //check if empty
  return getMaxHelper(m_root);
}

template <typename T>
T ScapegoatST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
  if(subTreeRoot->m_right==NULL){
    return subTreeRoot->m_data;
  } else{
    return getMaxHelper(subTreeRoot->m_right);
  }

}

template <typename T>
TreeNode<T>* ScapegoatST<T>::getRoot(){
    return m_root;
}


template <typename T>
T ScapegoatST<T>::getMedian(){
  //check if empty
  return m_root->m_data;
}

template <typename T>
void ScapegoatST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->m_data != key){
    parent = target;
    if(key < target->m_data){
      target = target->m_left;
    } else{
      target = target->m_right;
    }
  }
}

template <typename T>
TreeNode<T>* ScapegoatST<T>::getSuccessor(TreeNode<T>* rightChild){
  while(rightChild->m_left != NULL){
    rightChild = rightChild->m_left;
  }
  return rightChild;
}

template <typename T>
void ScapegoatST<T>::remove(T d){
  //check if empty
  TreeNode<T>* target = NULL;
  TreeNode<T>* parent = NULL;
  target = m_root;
  findTarget(d,target,parent);
  if(target == NULL){ //value wasn't in tree, nothing to do
    return;
  }
  //check if leaf (including the root)
  if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf
    if(target == m_root){ //leaf is the root of tree
      m_root = NULL;
    } else{ //it's not the root
      if(target ==  parent->m_left){
        parent->m_left = NULL;
      } else{
        parent->m_right = NULL;
      }
      rebuildCheck(parent);
    }
    //delete target; //free the memory

  } else if(target->m_left != NULL && target->m_right != NULL){ //2 child case
    TreeNode<T>* suc = getSuccessor(target->m_right);
    T value = suc->m_data;
    remove(value); //remove successor treenode
    target->m_data = value;
    rebuildCheck(target);

  } else{ //1 child
    TreeNode<T>* child;
    if(target->m_left != NULL){
      child = target->m_left;
    } else{
      child = target->m_right;
    }
    rebuildCheck(child);
    if(target ==  m_root){
      m_root = child;
    } else{
      if(target == parent->m_left){
        //cout << "I'm here!" << endl;
        parent->m_left = child;
      } else{
        parent->m_right = child;
      }
    }
      //delete target;
  }
  --m_size;


}



#endif