//-----------------------------------------------------------------------------
//Jinyan Li CMPS101 pa4
// GraphTest.c
//Test program for Graph.c ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){
   int i, s, max, min, d, n=35;
   List  C = newList(); // central vertices
   List  P = newList(); // peripheral vertices
   List  E = newList(); // eccentricities
   Graph G = NULL;

/*
   // Build graph G
   G = newGraph(n);
   for(i=1; i<n; i++){
      if( i%7!=0 )
        addEdge(G, i, i+1);
      if( i<=28  )
       addEdge(G, i, i+7);
   }
   addEdge(G, 9, 31);
   addEdge(G, 17, 13);
   addEdge(G, 14, 33);

   // Print adjacency list representation of G
   printGraph(stdout, G);

   // Calculate the eccentricity of each vertex
   for(s=1; s<=n; s++){
      BFS(G, s);
      max = getDist(G, 1);
      for(i=2; i<=n; i++){
         d = getDist(G, i);
         max = ( max<d ? d : max );
      }
      append(E, max);
   }
printf("Source of G %d Size of G %d Order of G %d",getSource(G),getSize(G),getOrder(G));

   // Determine the Radius and Diameter of G, as well as the Central and
   // Peripheral vertices.
   append(C, 1);
   append(P, 1);
   min = max = front(E);
   moveTo(E,0);
   moveNext(E);
   for(i=2; i<=n; i++){
      d = getElement(E);
      if( d==min ){
         append(C, i);
      }else if( d<min ){
         min = d;
         clear(C);
         append(C, i);
      }
      if( d==max ){
         append(P, i);
      }else if( d>max ){
         max = d;
         clear(P);
         append(P, i);
      }
      moveNext(E);
   }

   // Print results
   printf("\n");
   printf("Radius = %d\n", min);
   printf("Central vert%s: ", length(C)==1?"ex":"ices");
   printList(stdout, C);
   printf("\n");
   printf("Diameter = %d\n", max);
   printf("Peripheral vert%s: ", length(P)==1?"ex":"ices");
   printList(stdout, P);
   printf("\n");

   freeList(&C);
   freeList(&P);
   freeList(&E);
   freeGraph(&G);

*/
//testing undirected graph
printf("testing undirected graph G2\n");
  Graph G2= newGraph(6);
   addEdge(G2, 1, 2);
   addEdge(G2, 1, 3);
   addEdge(G2, 2, 4);
   addEdge(G2, 2, 5);
   addEdge(G2, 2, 6);
   addEdge(G2, 3, 4);
   addEdge(G2, 4, 5);
   addEdge(G2, 5, 6);
   //addEdge(G2, 4, 6);
    printGraph(stdout, G2);
    BFS(G2, 3);

printf("Source of G:%d Size of G:%d Order of G:%d \n",getSource(G2),getSize(G2),getOrder(G2));
printf("getDist(G2,6)%d\n",getDist(G2,6));
printf("getDist(G2,3)%d\n",getDist(G2,3));
printf("getParent(G2,5)%d\n",getParent(G2,5));


List Pa=newList();
printf("getPath(Pa,G2,3);\n");
getPath(Pa,G2,6);
printList(stdout,Pa);
BFS(G2, 1);
clear(Pa);
getPath(Pa,G2,5);
printList(stdout,Pa);

printf("makeNull(G2)\n");
makeNull(G2);
printGraph(stdout, G2);


    freeList(&Pa);
    freeGraph(&G2);


//testing directed graph
printf("testing directed graph G3\n");
Graph G3=newGraph(4);

addArc(G3,1,2);
addArc(G3,1,3);
addArc(G3,3,2);
addArc(G3,3,4);
addArc(G3,4,1);

printGraph(stdout, G3);
   BFS(G3, 3);

printf("Source of G3:%d Size of G3:%d Order of G3:%d \n",getSource(G3),getSize(G3),getOrder(G3));
printf("getDist(G3,6):%d\n",getDist(G3,1));
printf("getDist(G3,3):%d\n",getDist(G3,2));
printf("getParent(G3,3):%d\n",getParent(G3,3));


List Pa2=newList();
printf("getPath(Pa2,G3,1)\n");
getPath(Pa2,G3,1);
printList(stdout,Pa2);


   // Free objects
  
   
    freeList(&Pa2);
   freeGraph(&G3);

   return(0);
}

