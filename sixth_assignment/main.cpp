#include "WGraph.h"
#include <iostream>
using namespace std;
#include <fstream>
#include "DblList.h"
#include "ListNode.h"
#include "PQueue.h"

int main(int argc, char**argv){
  
  std::string m_file = argv[1];
  ifstream inFile;
  inFile.open(m_file, ios::in);
  int n_dimensions;
  inFile >> n_dimensions;

  
  WGraph myWG(n_dimensions);
  
  double temp;
  for (int i =0; i < n_dimensions; ++i){
    for (int j = 0; j < n_dimensions; ++j){
        inFile >> temp;
        myWG.addEdge(i,j, temp);
    }
  }
  inFile.close();
  myWG.computeMST();
  return 0;
}
