#ifndef UGraph_H
#define UGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>

/* DO NOT CHANGE ANYTHING ABOUT THIS FILE
This is for an unweighted, undirected UGraph implemented with adjacency matrix of fixed size */

typedef unsigned int VertexID; //we are creating a type name called VertexID that is the same as an unsigned int

class UGraph{
  public: 
    UGraph();
    UGraph(unsigned int sz);
    ~UGraph();
    void addEdge(VertexID i, VertexID j);
    void removeEdge(VertexID i, VertexID j);
    bool areAdjacent(VertexID i, VertexID j);
    void printDFS(VertexID i); //print path of a DFS starting at i
    void printBFS(VertexID i); //print path of a BFS starting at i
  private:
    VertexID** m_adj;
    unsigned int m_size; //nodes in UGraph (fixed)
};

#endif