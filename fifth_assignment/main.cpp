#include <iostream>
#include "ScapegoatST.h"
//#include "TreeNode.h"
//#include "BST.h"
using namespace std;

int main(){
    ScapegoatST<int> scapeTree;
     scapeTree.insert(10);
    scapeTree.insert(4);
    scapeTree.insert(20);
    scapeTree.insert(30);
    scapeTree.insert(7);
    scapeTree.insert(14);
    scapeTree.printTreePostOrder();
    cout << scapeTree.getTotalSize() << endl;
    scapeTree.remove(4);
    //cout << scapeTree.getSizeAtNode()
    //cout << scapeTree.nodeTreeSize(scapeTree.getRoot(),scapeTree.getRoot()) << endl;
    

    return 0;
}