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
  T getPerson(int n);
  void printTreeInOrder();
  void printTreePostOrder();
  void testPrint();
  void ascArray(TreeNode<T>* subTreeRoot);
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
  int treeToArray(TreeNode<T> *ptr, TreeNode<T> *arr[], int i);
  void rebuildTree(TreeNode<T> *u);
  TreeNode<T> *arrayToTree(TreeNode<T> **a, int i ,int n);
  void printTree();
  void printTree(TreeNode<T>* root);
  void printTreeHelper(TreeNode<T>* root, int space);


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
  T personHelper(TreeNode<T>* subTreeRoot, int n);

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
void ScapegoatST<T>::ascArray(TreeNode<T>* subTreeRoot){
  int size = getSizeAtNode(subTreeRoot);
  TreeNode<T> **arr = new TreeNode<T>* [size];
    treeToArray(subTreeRoot, arr, 0);
    cout << "array" << endl;
    for (int i = 0; i < size; i++){
      cout <<arr[i]->m_data << endl;
    }
}

template <typename T>
void ScapegoatST<T>::printTree(){
  printTreeHelper(m_root, 0);
}

template <typename T>
void ScapegoatST<T>::printTree(TreeNode<T>* root){
  printTreeHelper(root, 0);
}

template <typename T>
void ScapegoatST<T>::printTreeHelper(TreeNode<T>* root, int space){
  if (root == NULL){
    return;
  }
  space += 10;
  printTreeHelper(root->m_right,space);
  cout << endl;

  for (int i =10; i<space; i++){
    cout << " ";
  }
  cout << root->m_data << "\n";
  printTreeHelper(root->m_left, space);
}

template <typename T>
void ScapegoatST<T>::testPrint(){
  cout << m_root->m_data<< endl;
  cout << m_root->m_left->m_data << endl;
  cout << m_root->m_left->m_right->m_data << endl;
  cout << "left tree done" <<endl;
  cout << m_root->m_right->m_data << endl;//20
  cout << m_root->m_right->m_left->m_data << endl;//14
 // cout << m_root->m_right->m_left->m_right->m_data << endl;
  cout << m_root->m_right->m_right->m_data << endl;//30
  //cout << m_root->m_right->m_right->m_right->m_data << endl;//
  //cout << m_root->m_right->m_right->m_left->m_data << endl;
  cout << m_root->m_right->m_right->m_right->m_data << endl;//40
  cout << m_root->m_right->m_right->m_right->m_left->m_data << endl;//35
  cout << m_root->m_right->m_right->m_right->m_left->m_left->m_data << endl;//35
  cout << m_root->m_right->m_right->m_right->m_right->m_data << endl;//55
  cout << m_root->m_right->m_right->m_right->m_right->m_left->m_data << endl;//50
    //cout << m_root->m_right->m_right->m_right->m_right->m_left->m_left->m_data << endl;

}

template <typename T>
int ScapegoatST<T>::getTotalSize(){
  return m_size;
}


template <typename T>
int ScapegoatST<T>::treeToArray(TreeNode<T> *subTreeRoot, TreeNode<T> *arr[], int i)
{
  if (subTreeRoot == NULL){
    return i;
  }
  i = treeToArray(subTreeRoot->m_left, arr, i);
  arr[i++] = subTreeRoot;
  return treeToArray(subTreeRoot->m_right, arr, i);
}

template <typename T>
void ScapegoatST<T>::rebuildTree(TreeNode<T> *subTreeRoot)
{
  TreeNode<T> *parentRoot = subTreeRoot->m_parent;
  int size = getSizeAtNode(subTreeRoot);
  TreeNode<T> **arr = new TreeNode<T>* [size];

  treeToArray(subTreeRoot, arr, 0);

  if (parentRoot == NULL){
    m_root = arrayToTree(arr, 0, size);
    m_root->m_parent = NULL;
  }
  else if (parentRoot->m_left == subTreeRoot){
    parentRoot->m_left = arrayToTree(arr, 0, size);
    parentRoot->m_left->m_parent = parentRoot;
  }
  else{
    parentRoot->m_right = arrayToTree(arr, 0, size);
    parentRoot->m_right->m_parent = parentRoot;
  }
}
 

template <typename T>
TreeNode<T> * ScapegoatST<T>::arrayToTree(TreeNode<T> **arr, int i, int size)
{
  int median = size / 2;
  if (size== 0)
    return NULL;

  arr[i+median]->m_right = arrayToTree(arr, i+median+1, size-median-1);//fills right side
  if (arr[i+median]->m_right != NULL){
    arr[i+median]->m_right->m_parent = arr[i+median];
  }

  arr[i+median]->m_left = arrayToTree(arr, i, median);//fills left side
  if (arr[i+median]->m_left != NULL){
    arr[i+median]->m_left->m_parent = arr[i+median];
  }

  return arr[i+median];
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
  //cout << "1st part: " << getNodeDepth(subTreeRoot) << endl;
  //cout <<"2nd part: " <<  log(getTotalSize()) / (double) log(1.5) << endl;
  if(subTreeRoot != m_root){
    cout << ((double)(log(getTotalSize())) / (double)(log(1.5))) << endl;
  if (getNodeDepth(subTreeRoot) > ((double)(log(getTotalSize())) / (double)(log(1.5))) || getNodeDepth(subTreeRoot) < (getTotalSize()/2)){
    //cout << subTreeRoot->m_data << " called scapegoat" << endl;
    
      isScapeGoat(subTreeRoot);
    
  }else{
    if(subTreeRoot != m_root){
    rebuildCheck(subTreeRoot->m_parent);
    }
  }
  }
}

template <typename T>
bool ScapegoatST<T>::contains(T d){
  TreeNode<T>* newNode = new TreeNode<T>(d);
  return containsHelper(m_root, newNode);

}

template <typename T>
T ScapegoatST<T>::getPerson(int n){
  return personHelper(m_root, n);
}

template <typename T>
T ScapegoatST<T>::personHelper(TreeNode<T>* subTreeRoot, int n){
  if (subTreeRoot == NULL){
    
  }else if(n == subTreeRoot->m_data/*->getID()*/){
    return subTreeRoot;
  } else if(n < subTreeRoot->m_data/*->getID()*/){
    return containsHelper(subTreeRoot->m_left,n);
  } else{
    return containsHelper(subTreeRoot->m_right,n);
  }
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
    // if (subTreeRoot->m_parent != NULL){
    //   //cout <<"parent data: " << subTreeRoot->m_parent->m_data << endl;
    // }else{cout << "no parent" << endl;}
    //cout << "node depth: " << getNodeDepth(subTreeRoot) << endl;
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




template<typename T>
bool ScapegoatST<T>::isScapeGoat(TreeNode<T>* subTreeRoot){
  if(subTreeRoot != m_root){
    //cout << "child size: " << getSizeAtNode(subTreeRoot) << endl;
    //cout <<"parent size: " << getSizeAtNode(subTreeRoot->m_parent) << endl;
    //cout << ((double)getSizeAtNode(subTreeRoot) / (double)getSizeAtNode(subTreeRoot->m_parent)) << endl;
    //cout << 2.0/3.0 << endl;
    if (((double)getSizeAtNode(subTreeRoot) / (double)getSizeAtNode(subTreeRoot->m_parent)) > 2.0/3.0){
      //cout << "scapegoat found on: "<< subTreeRoot->m_data << endl;
      printTreeInOrder();
      //cout <<"--------" << endl;
      rebuildTree(subTreeRoot);
      printTreeInOrder();
      cout <<"--------" << endl;
      return true;
    }else{
      //cout << "no scapegoat here on: " << subTreeRoot->m_data << endl;
      if (subTreeRoot->m_parent != NULL){
      return isScapeGoat(subTreeRoot->m_parent);
      }else{false;}
      }
  }else{
    //cout <<"root so no scapegoat" << endl;
  }
}


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
