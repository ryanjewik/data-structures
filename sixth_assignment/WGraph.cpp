/// @file WGraph.cpp
/// @brief Allows for the creation of a Weighted Graph
/// @author Ryan Jewik - jewik@chapman.edu
#include "WGraph.h"
using namespace std;
#include "DblList.h"
#include "ListNode.h"
#include "PQueue.h"


// defaultconstructor
WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
  m_MST = NULL;
  m_cost = 0;
}

//overload constructor
WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  m_MST = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
    m_MST[i] = new double [sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max(); //essentially infinity
      m_conn[i][j] = std::numeric_limits<double>::max();
      m_MST [i][j] = 0;
    }
  }
}

//destructor
WGraph::~WGraph(){
  //release memory
}


//prints the adjacency matrix
void WGraph::printGraph(){
  for (int i =0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
        cout << m_adj[i][j] << " ";
    }
    cout << endl;
  }
}

//adds edge
void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;

  }
}

//removes edge
void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

//returns true if two vertices are adjacent
bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}


void WGraph::calcFW(){ //runtime complexity O(v^3)
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < m_size; ++ im){ //intermediate points --> transitive closure
    for(int source = 0; source < m_size; ++source){ //source = starting point
      for(int sink = 0; sink <m_size; ++sink){ //sink = ending point
        if(source == sink){
          continue;
        }else if(m_conn[source][im] != std::numeric_limits<double>::max() &&
          m_conn[im][sink] != std::numeric_limits<double>::max() &&
          m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
           m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j]; //constant
}


//checks the m_conn matrix and adds connections as needed
int WGraph::computeMSTHelper(int x, int y){
  for (int i = 0; i < m_size; ++i){
   if (m_conn[i][x] == 1){//checks the x axis
    if (y != i&& m_conn[i][y] != 1){      
      m_conn[y][i] = 1;
      m_conn[i][y] = 1;
      cout << i << " " << x << endl;
      computeMSTHelper(i,x);
      cout << "added connection between: " << y << " and " << i << " and its' vice versa" << endl;
    }

   }
   if (m_conn[i][y] == 1){//checks the y axis
    if (x != i && m_conn[i][x] != 1){
      m_conn[x][i] = 1;
      m_conn[i][x] = 1;
      cout << i << " " << y << endl;
      computeMSTHelper(i,y);
      cout << "added connection between: " << x << " and " << i << " and its' vice versa" << endl;
    }
   }
  }
  return 0;
}

int WGraph::computeMST(){//prints the MST and the cost
  DblList<int> visitedVertices;
  //create a doublelist of integers to signify which vertices have been visited
  PQueue<double> pq(true);
  //create a priority queue that holds doubles for weights
  cout << "-------------------------" << endl;
  //create priority queue
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      if (i == j){
        break;
      }
      else if (m_adj[i][j] != 0){
        pq.add(m_adj[i][j]);
        cout << "adding: " << m_adj[i][j] << " to the pq" << endl;

      }
    }
  }
  //populating m_conn with zeros
  for (int i = 0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
      m_conn[i][j] = 0;
    }
  }

  cout << "-------------------------" << endl;
  //the first connection created in the MSt
  double sumCost = 0;
  double tempAdd;
  tempAdd = pq.remove();
  //cout << "enqueueing: " << tempAdd << endl;
    for (int i = 0; i < m_size; ++i){
      for (int j =0; j < m_size; ++j){
        if (i ==j){
          break;
        }
        else if(m_adj[i][j] == tempAdd){
          m_MST[i][j] = tempAdd;
          m_MST[j][i] = tempAdd;
          m_conn[i][j] = 1;
          m_conn[j][i] = 1;
          sumCost += tempAdd;
          cout << "just added "<< tempAdd << " to m_MST at: " << i << ", " << j << ": this was the start" << endl;
        }
      }
    }
    
    //any following connections to the MST
    while (pq.size() != 0){
      tempAdd = pq.remove();
      //cout << "enqueueing: " << tempAdd << endl;
      for (int i = 0; i < m_size; ++i){
        for (int j =0; j < m_size; ++j){
          if (i ==j){
            break;
          }
          else if(m_adj[i][j] == tempAdd){
            if (m_conn[i][j] != 1){//if there is no connection already, add the connection
                m_MST[i][j] = tempAdd;
                m_MST[j][i] = tempAdd;
                sumCost += tempAdd; //adds the weight to the total cost
                cout << "just added "<< tempAdd << " to m_MST at: " << i << ", " << j << ": now onto the next loop" << endl;

              //will add the connection to m_conn, then using computeMSTHelper add any more connections needed
              m_conn[i][j] = 1;
              m_conn[j][i] = 1;
              computeMSTHelper(i,j);
              
            }
          }
        }
      }
    }



  cout << "MST cost:" << sumCost << endl;
  cout << "m_MST:" << endl;
  for (int i = 0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
      cout << m_MST[i][j] << " ";
    }
    cout << endl;
  }
}
