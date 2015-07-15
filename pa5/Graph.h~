//-----------------------------------------------------------------------------
// Graph.h
// Header file for List ADT
//-----------------------------------------------------------------------------
#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_
#define INF -1
#define NIL 0
#define UNDEF 0
#include "List.h"

//private GraphObj
typedef struct GraphObj* Graph;

//Function newGraph() returns a Graph pointing to a newly created GraphObj representing a graph
//having n vertices and no edges
Graph newGraph(int n);

//Function addEdge() inserts a new edge
//joining u to v, i.e. u is added to the adjacency List of v, and v to the adjacency List of u. Your program is
//required to maintain these lists in sorted order by increasing vertex labels.
void addEdge(Graph G,int u,int v);
//addArc() inserts a new directed edge from
// u to v, i.e. v is added to the adjacency List of u (but not u to the adjacency List of v).
void addArc(Graph G,int u,int v);
//freeGraph
void freeGraph(Graph* pG);

//return order value
int getOrder(Graph G);

//return size value
int getSize(Graph G);

//return the parent vertex
int getParent(Graph G,int u);

//return distance from source to certain vertex
int getDist(Graph G,int u);

//return source vertex
int getSource(Graph G);

//Function getPath()
//appends to the List L the vertices of a shortest path in G from source to u, or appends to L the value NIL if
//no such path exists.
void getPath(List L,Graph G,int u);
//delete all edges
void makeNull(Graph G);

//do BFS on a graph
void BFS(Graph G,int s);

//do DFS on a graph
void DFS(Graph G,List S);

//returns a reference to a new graph that is a copy of G
Graph copyGraph(Graph G);

//Function transpose() returns a reference to a new graph object representing the transpose of G
Graph transpose(Graph G);

//return the discover time of the vertex
int getDiscover(Graph G,int u);

//return the finish time of the vertex
int getFinish(Graph G,int u);

//print adj list of a graph
void printGraph(FILE* out, Graph G);
#endif

