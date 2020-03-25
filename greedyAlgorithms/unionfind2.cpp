#include<bits/stdc++.h>
using namespace std;
// a structure to represent an edge in the graph
class Edge{
public:
  int src,dest;
};

// a structure to represent a graph
class Graph{
public:
  //V -> number of vertices,E-> number of edges
  int V,E;
  //graph is represented as an array of edges
  Edge* edge;
};
class subset{
public:
  int parent;
  int rank;
};
//Create a graph with V vertices and E edges
Graph* createGraph(int V,int E){
  Graph* graph = new Graph();
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[graph->E * sizeof(Edge)];
  return graph;
}

// A utility function to find set of an element i
//(uses path compression technique)
int find(subset subsets[],int i){
  //find root and make root as parent of i (path compression)
  if (subsets[i].parent != i)
      subsets[i].parent = find(subsets,subsets[i].parent);

  return subsets[i].parent;
}

// A function that does union of two sets of x and y
//(uses union by rank)
void Union(subset subsets[],int x,int y){
  int xroot = find(subsets,x);
  int yroot = find(subsets,y);

  // Attack smaller rank tree under root of high rank stree
  //(Union by Rank)
  if (subsets[xroot].rank < subsets[yroot].rank)
      subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
      subsets[yroot].parent = xroot;

  //If ranks are same, then make one as root and increment
  //its rank by one
  else{
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

//The main function to check wheather a given graph is cyclic or not
int isCycle(Graph* graph){
  int V = graph->V;
  int E = graph->E;

  //Allocate memory for creating V sets
  subset *subsets = (subset*) malloc(V * sizeof(subset));

  for(int v = 0;v < V; v++){
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  //Iterate through all edges of graph,find sets of both
  // vertices of every edge, if sets are same,then there is
  //cycle in graph.
  for(int e=0;e<E;e++){
    int x = find(subsets,graph->edge[e].src);
    int y = find(subsets,graph->edge[e].dest);

    if(x==y)
    return 1;
    Union(subsets,x,y);
  }
  return 0;
}

int main(){
  /* Let us create the following Graph
   0
   |\
   | \
   1--2 */
   int V =3,E = 3;
   Graph* graph = createGraph(V,E);
   // add edge 0-1
   graph->edge[0].src = 0;
   graph->edge[0].dest = 1;
   // add edge 1-2
   graph->edge[1].src = 1;
   graph->edge[1].dest = 2;
   // add edge 0-2
   graph->edge[2].src = 0;
   graph->edge[2].dest = 2;

   if(isCycle(graph)){
   cout<<"Graph contains cycle";
 }else{
   cout<<"Graph doesn't contains cycle";
 }
 return 0;
}
