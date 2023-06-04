#include "UGraph.h"
#include <iostream>
using namespace std;

int main(){
  
  UGraph myGraph(8U);
  myGraph.addEdge(0U,1U);
  myGraph.addEdge(0U,2U);
  myGraph.addEdge(0U,3U);
  myGraph.addEdge(1U,4U);
  myGraph.addEdge(3U,7U);
  myGraph.addEdge(4U,5U);
  myGraph.addEdge(4U,6U);
  myGraph.addEdge(6U,7U);

  cout << myGraph.areAdjacent(3U,7U) << endl;
  cout << myGraph.areAdjacent(2U,7U) << endl;
  cout << "============\n";

  myGraph.printDFS(0U);
  cout << "============\n";
  myGraph.printBFS(0U);

  return 0;
}
