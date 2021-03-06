//-----------------------------------------------------------------------------
//Jinyan Li CMPS101 pa5
//graph.c
//This is a graph ADT.
//Graph ADT that represents a graph as an array of Lists. Each vertex will be associated
//with an integer label in the range 1 to n, where n is the number of vertices in the graph.
//------------------------

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"
#define INF -1
#define NIL 0
#define UNDEF 0
#define MAX_LEN 300
static void visit (Graph G,int u,int* time,List L);

//private GraphObj
typedef struct GraphObj{
   int order;
   int size;
   int source;
   List * arrayLists;
   int *color; //1=white 2=gray 3=black
   int *parent;
   int *d;
   int *discovery;
   int *finish;
}GraphObj;

typedef GraphObj* Graph;

//Function newGraph() returns a Graph pointing to a newly created GraphObj representing a graph
//having n vertices and no edges
Graph newGraph(int n){
    if(n<0){
        printf("Error: newGraph() n can't be negative");
        exit(1);
    }
    Graph G = malloc(sizeof(GraphObj));
    G->order=n;
    G->size=0;
    G->source=NIL;
    //G->arrayLists=(List *)malloc(n*sizeof(List)+sizeof(List));
    G->arrayLists= calloc(n + 1, sizeof(List));
    G->parent = calloc(n+1, sizeof(int));
    G->color = calloc(n+1, sizeof(int));
    G->d = calloc(n+1, sizeof(int));
    G->discovery=calloc(n+1, sizeof(int));
    G->finish=calloc(n+1, sizeof(int));

   return(G);
}

//Function addEdge() inserts a new edge
//joining u to v, i.e. u is added to the adjacency List of v, and v to the adjacency List of u. Your program is
//required to maintain these lists in sorted order by increasing vertex labels.
void addEdge(Graph G,int u,int v){

if(G==NULL){
        printf("Error:addEdge() Null reference");
        exit(1);
    }

    if(u<1||v<1){
        printf("Error:args in addEdge() less than 1");
        exit(1);
    }
    if(u>getOrder(G)){
        printf("Error: u:%d in addEdge() bigger than order",u);
        exit(1);
    }
     if(v>getOrder(G)){
        printf("Error:v:%d in addEdge() bigger than order",v);
        exit(1);
    }



     if(G->arrayLists[u]==NULL){
         G->arrayLists[u]=newList();
       append(G->arrayLists[u],v);
     }else{
       for(moveTo(G->arrayLists[u],0);getIndex(G->arrayLists[u])>=0;moveNext(G->arrayLists[u])){
        if(v<getElement(G->arrayLists[u])){
            insertBefore(G->arrayLists[u],v);
            break;
        }
        if(getIndex(G->arrayLists[u])==length(G->arrayLists[u])-1){
            append(G->arrayLists[u],v);
            break;
        }
       }

     }

     if(G->arrayLists[v]==NULL){
        G->arrayLists[v]=newList();
        append(G->arrayLists[v],u);
     }else{
        for(moveTo(G->arrayLists[v],0);getIndex(G->arrayLists[v])>=0;moveNext(G->arrayLists[v])){
        if(u<getElement(G->arrayLists[v])){
            insertBefore(G->arrayLists[v],u);

            break;
        }
        if(getIndex(G->arrayLists[v])==length(G->arrayLists[v])-1){
            append(G->arrayLists[v],u);

            break;
        }
       }
     }

   G->size++;

}
//addArc() inserts a new directed edge from
// u to v, i.e. v is added to the adjacency List of u (but not u to the adjacency List of v).
void addArc(Graph G,int u,int v){

if(G==NULL){
        printf("Error:addArc() Null reference");
        exit(1);
    }
    if(u<1||v<1){
        printf("Error:args in addArc() less than 1");
        exit(1);
    }
if(u>getOrder(G)||v>getOrder(G)){
        printf("Error:args in addArc() bigger than order");
        exit(1);
    }

     if(G->arrayLists[u]==NULL){
         G->arrayLists[u]=newList();
       append(G->arrayLists[u],v);
     }else{
       for(moveTo(G->arrayLists[u],0);getIndex(G->arrayLists[u])>=0;moveNext(G->arrayLists[u])){
        if(v<getElement(G->arrayLists[u])){
            insertBefore(G->arrayLists[u],v);
            break;
        }
        if(getIndex(G->arrayLists[u])==length(G->arrayLists[u])-1){
            append(G->arrayLists[u],v);
            break;
        }
       }

     }

   G->size++;

}

//return order value
int getOrder(Graph G){
 if(G==NULL){
        printf("Error:getOrder() Null reference");
        exit(1);
    }
 return G->order;
}

//return size value
int getSize(Graph G){
if(G==NULL){
        printf("Error:getOrder() Null reference");
        exit(1);
    }
return G->size;
}

//do BFS on a graph
void BFS(Graph G,int s){
if(G==NULL){
        printf("Error:BFS() Null reference");
        exit(1);
    }
    if(s<=0||s>G->order){
        printf("Error:BFS() wrong size argument");
        exit(1);
    }

int i;
G->source=s;
for(i=1;i<G->order+1;i++){
        G->color[i] = 1;
        G->parent[i] = NIL;
        G->d[i] = INF;
    }
        G->color[s] = 2;
        G->parent[s] = NIL;
        G->d[s] = 0;
List Q=newList();

append(Q,s);

while(!isEmpty(Q)){
    int u;
    u=front(Q);
    deleteFront(Q);
    if(G->arrayLists[u]!=NULL){
      for(moveTo(G->arrayLists[u],0);getIndex(G->arrayLists[u])>=0;moveNext(G->arrayLists[u])){
         if(G->color[getElement(G->arrayLists[u])]==1){
         G->color[getElement(G->arrayLists[u])]=2;
         G->d[getElement(G->arrayLists[u])]=G->d[u]+1;
         G->parent[getElement(G->arrayLists[u])]=u;
         append(Q,getElement(G->arrayLists[u]));
       }
        G->color[u]=3;
      }
    }
}

freeList(&Q);
}


void DFS(Graph G,List S){
if(G==NULL){
        printf("Error:DFS() Null reference");
        exit(1);
    }
if(length(S)!=getOrder(G)){
        printf("Error:DFS() List has different size");
        exit(1);
    }
if(S==NULL){
        printf("Error:DFS() Null list reference");
        exit(1);
    }

int i;
for(i=1;i<G->order+1;i++){
        G->color[i] = 1;
        G->parent[i] = NIL;
        //G->d[i] = INF;
        G->discovery[i]=UNDEF;
        G->finish[i]=UNDEF;
    }
    List L=newList();
    int time=0;
    for(moveTo(S,0);getIndex(S)>=0;moveNext(S)){
        if(G->color[getElement(S)]==1){
          int u=getElement(S);
           visit(G,u,&time,L);
        }
    }
    //printList(stdout,L);
    clear(S);
    for(moveTo(L,0);getIndex(L)>=0;moveNext(L)){
        append(S,getElement(L));
    }
    freeList(&L);
}

//private functon of DFS()
void visit (Graph G,int u,int* time,List L){
if(G==NULL){
        printf("Error:visit() Null reference");
        exit(1);
    }

if(L==NULL){
        printf("Error:visit() Null list reference");
        exit(1);
    }

if(time==NULL){
        printf("Error:visit() Null time reference");
        exit(1);
    }
if(u<1){
        printf("Error:visit() u can't be less than 1");
        exit(1);
    }
*time=*time+1;
G->discovery[u]=*time;
G->color[u]=2;
if(G->arrayLists[u]!=NULL){
for(moveTo(G->arrayLists[u],0);getIndex(G->arrayLists[u])>=0;moveNext(G->arrayLists[u])){
    if(G->color[getElement(G->arrayLists[u])]==1){

        G->parent[getElement(G->arrayLists[u])]=u;
         int v=getElement(G->arrayLists[u]);
        visit(G,v,time,L);
    }
   }
}
   G->color[u]=3;
   *time=*time+1;
   G->finish[u]=*time;
   prepend(L,u);
}

//returns a reference to a new graph that is a copy of G
Graph copyGraph(Graph G){
 if(G==NULL){
        printf("Error:copyGraph() Null reference");
        exit(1);
    }
Graph newG=newGraph(getOrder(G));
newG->size=getSize(G);
//newG->source=getSource(G);
int i;
for(i=1;i<=getOrder(G);i++){
    /*
    newG->parent[i]=G->parent[i];
    newG->color[i]=G->color[i];
    newG->d[i]=G->d[i];
    newG->discovery[i]=G->discovery[i];
    newG->finish[i]=G->finish[i];
    */
     if(G->arrayLists[i]!=NULL){
    newG->arrayLists[i]=copyList(G->arrayLists[i]);
    }
}
return newG;
}


//return the discover time of the vertex
int getDiscover(Graph G,int u){
    if(G==NULL){
        printf("Error:getDiscover() Null reference");
        exit(1);
    }
    if(u<=0||u>G->order){
        printf("Error:getDiscover() wrong size argument");
        exit(1);
    }
  return G->discovery[u];
}

//return the finish time of the vertex
int getFinish(Graph G,int u){
     if(G==NULL){
        printf("Error:getFinish() Null reference");
        exit(1);
    }
    if(u<=0||u>G->order){
        printf("Error:getFinish() wrong size argument");
        exit(1);
    }
 return G->finish[u];
}


//Function transpose() returns a reference to a new graph object representing the transpose of G
Graph transpose(Graph G){
if(G==NULL){
        printf("Error:transpose() Null reference");
        exit(1);
    }
Graph newG=newGraph(getOrder(G));
int u;
for(u=1;u<=G->order;u++){
   if(G->arrayLists[u]!=NULL){
   for(moveTo(G->arrayLists[u],0);getIndex(G->arrayLists[u])>=0;moveNext(G->arrayLists[u])){
    int v=getElement(G->arrayLists[u]);
    addArc(newG,v,u);
   }
 }
}

return newG;
}
//return distance from source to certain vertex
int getDist(Graph G,int u){
 if(u<1||u>getOrder(G)){
    printf("Error:getDist() wrong input");
        exit(1);
 }

 if( G==NULL ){
      printf("Graph Error: calling getDist() on NULL Graph reference\n");
      exit(1);
   }
   return G->d[u];


}

//return source vertex
int getSource(Graph G){

 if( G==NULL ){
      printf("Graph Error: calling getSource() on NULL Graph reference\n");
      exit(1);
   }
     /*
    int i=NIL;
     for(i=1;i<G->order+1;i++){
         if(G->d[i]==0){
         return i;
         }
     }
     return i;
     */
     return G->source;
}

//return the parent vertex
int getParent(Graph G,int u){
 if( G==NULL ){
      printf("Graph Error: calling getParent() on NULL Graph reference\n");
      exit(1);
   }
if(u<1||u>getOrder(G)){
    printf("Error:getDist() wrong input");
        exit(1);
 }
 return G->parent[u];
}

//delete all edges
void makeNull(Graph G){
if( G==NULL ){
      printf("Graph Error: calling makeNull() on NULL Graph reference\n");
      exit(1);
   }
   int i;

   for(i=0;i<getOrder(G)+1;i++){
     if(G->arrayLists[i]!=NULL){
       clear(G->arrayLists[i]);
     }
     G->parent[i]=NIL;
     //if(i!=getSize(G)){
     G->d[i]=INF;
      //}
      G->color[i]=1;
   }
    G->size=0;
    G->source=NIL;
}
//Function getPath()
//appends to the List L the vertices of a shortest path in G from source to u, or appends to L the value NIL if
//no such path exists.
void getPath(List L,Graph G,int u){
if( G==NULL ){
      printf("Graph Error: calling getPath() on NULL Graph reference\n");
      exit(1);
   }
if( L==NULL ){
      printf("List Error: calling getPath() on NULL List reference\n");
      exit(1);
   }

if(getSource(G)==NIL){
    printf(" Error: getPath() haven't called BFS\n");
      exit(1);
}
 //int i;
 //i=G->parent[u];
    if(getDist(G,u)==INF){
       prepend(L,NIL);
   }else if(G->parent[u]==NIL){
       prepend(L,u);
   }else{
    prepend(L,u);
    getPath(L,G,G->parent[u]);
      }
   }

//free graph object from heap
void freeGraph(Graph* pG){
 if( pG==NULL ){
      printf("List Error: calling freeGraph() on NULL Graph reference\n");
      exit(1);
   }
 int i;
 int n;
 n=(*pG)->order+1;

 for(i=0;i<n;i++){

    freeList(&(*pG)->arrayLists[i]);

/*
    if((*pG)->parent[i]!=NULL)
    free(&((*pG)->parent[i]));

    if((*pG)->color[i]!=NULL)
    free(&((*pG)->color[i]));

    if((*pG)->d[i]!=NULL)
    free(&((*pG)->d[i]));
*/

 }

    free((*pG)->arrayLists);
    free((*pG)->parent);
    free((*pG)->color);
    free((*pG)->d);
    free((*pG)->discovery);
    free((*pG)->finish);
    free(*pG);
    //free(&pG);
    //free(pG);
    pG=NULL;
}

//print graph
void printGraph(FILE* out, Graph G){

   if( G==NULL ){
      printf("List Error: calling printGraph() on NULL Graph reference\n");
      exit(1);
   }
   int i;
   for(i=1;i<=G->order;i++){

       fprintf(out,"%d: ",i);
       if(G->arrayLists[i]!=NULL){
       printList(out,G->arrayLists[i]);
      }else{
      fprintf(out,"\n");
      }
   }
   //fprintf(out,"\n");
}

