#include <iostream>
#include "ScapegoatST.h"
//#include "TreeNode.h"
//#include "BST.h"
using namespace std;

int main(){
  
  ScapegoatST<int> scapeTree;
  scapeTree.insert(13);
  scapeTree.insert(12);
  scapeTree.insert(15);
  scapeTree.insert(9);
  scapeTree.insert(17);
  scapeTree.insert(2);
  scapeTree.insert(1);
  scapeTree.insert(7);
  scapeTree.insert(0);
  scapeTree.insert(4);
  scapeTree.insert(5);
  scapeTree.insert(18);
  scapeTree.insert(19);
  scapeTree.insert(20);
  scapeTree.insert(21);
  scapeTree.insert(22);
  scapeTree.insert(23);
  scapeTree.insert(24);
  scapeTree.insert(25);
  scapeTree.insert(26);
  scapeTree.insert(27);
  scapeTree.insert(28);
  scapeTree.insert(29);
  scapeTree.insert(30);
  scapeTree.remove(18);
  scapeTree.remove(19);
  scapeTree.remove(20);
  scapeTree.remove(21);
  scapeTree.remove(22);
  scapeTree.remove(23);
  scapeTree.remove(24);
  scapeTree.remove(25);
  scapeTree.remove(26);
  scapeTree.remove(27);
  scapeTree.remove(28);
  scapeTree.remove(29);
  scapeTree.remove(30);

    //next set
    scapeTree.printTree();
    // scapeTree.remove(26);
    // cout << "called remove" << endl;
    // scapeTree.printTree();
    // cout <<"doing something drastic" << endl;
    // scapeTree.remove(19);
    // scapeTree.remove(18);
    // scapeTree.remove(17);
    // scapeTree.printTree();
    // scapeTree.remove(100);

    cout << "testing getter function" << endl;
    //cout << scapeTree.getPerson(10) << endl;
    scapeTree.ascArray(scapeTree.getRoot());




    //scapeTree.printTreePostOrder();
    //cout << scapeTree.getTotalSize() << endl;

    cout << "--------------------------------------------"<<endl;

    //scapeTree.testPrint();
    
    //scapeTree.printTreePostOrder();
   // scapeTree.remove(20);
    //cout << scapeTree.getSizeAtNode()
    //cout << scapeTree.nodeTreeSize(scapeTree.getRoot(),scapeTree.getRoot()) << endl;
    //scapeTree.printTreePostOrder();
    

    return 0;
}