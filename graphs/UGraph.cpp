#include "UGraph.h"

UGraph::UGraph(){
  m_size = 0;
  VertexID** m_adj;
}

UGraph::UGraph(unsigned int sz){
  // allocate sz * sz adj matrix and initialize all edges to 0
  m_size = sz;
  m_adj = new VertexID*[sz];
  for (int i =0; i < sz; ++i){
    m_adj[i] = new VertexID[sz];
  }
  for (int i = 0; i < sz; ++i){
    for (int k = 0; k < sz; ++k){
      m_adj[i][k] = 0;
    }
  }
}


UGraph::~UGraph(){
  //release memory - do this last
  for (int i =0; i < m_size; ++i){
    delete m_adj[i];
  }
  delete m_adj;
}

void UGraph::addEdge(VertexID i, VertexID j){
  m_adj[i][j] = 1;
  m_adj[j][i] =1;
}

void UGraph::removeEdge(VertexID i, VertexID j){
  m_adj[i][j] = 0;
  m_adj[j][i] = 0;
}

bool UGraph::areAdjacent(VertexID i, VertexID j){
  if (m_adj[i][j] == 1){
    return true;
  }else{return false;}
}

void UGraph::printDFS(VertexID i){
  std::stack<VertexID> stk;
  std::set<VertexID> visited;
  stk.push(i);
  //complete the printDFS method
  std::cout << stk.top() << std::endl;
  stk.pop();

  std::cout << stk.top() << std::endl;
  stk.pop();

  std::cout << stk.top() << std::endl;
  stk.pop();
}

void UGraph::printBFS(VertexID i){
  std::deque<VertexID> queue;
  std::set<VertexID> visited;
  queue.push_back(i);
  //complete the printBFS method

}
