//-----------------------------------------------------------------------------
//Jinyan Li CMPS101 pa5
// GraphTest.c
//Test program for Graph.c ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"Graph.h"
#define INF -1
#define NIL 0

int main(int argc, char* argv[]){
   int i, n=8;
   List S = newList();
   Graph G = newGraph(n);
   Graph T=NULL, C=NULL;

   for(i=1; i<=n; i++) append(S, i);

   addArc(G, 1,2);
   addArc(G, 1,5);
   addArc(G, 2,5);
   addArc(G, 2,6);
   addArc(G, 3,2);
   addArc(G, 3,4);
   addArc(G, 3,6);
   addArc(G, 3,7);
   addArc(G, 3,8);
   addArc(G, 6,5);
   addArc(G, 6,7);
   addArc(G, 8,4);
   addArc(G, 8,7);
   printGraph(stdout, G);

   DFS(G, S);
   fprintf(stdout, "\n");
   fprintf(stdout, "x:  d  f  p\n");
   for(i=1; i<=n; i++){
      fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
   }
   fprintf(stdout, "\n");
   printList(stdout, S);
   fprintf(stdout, "\n");

   T = transpose(G);
   C = copyGraph(G);
   fprintf(stdout, "\n");
   printGraph(stdout, C);
   fprintf(stdout, "\n");
   printGraph(stdout, T);
   fprintf(stdout, "\n");

   DFS(T, S);
   fprintf(stdout, "\n");
   fprintf(stdout, "x:  d  f  p\n");
   for(i=1; i<=n; i++){
      fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
   }
   fprintf(stdout, "\n");
   printList(stdout, S);
   fprintf(stdout, "\n");

//test for SSC for graph G
int SCC=0;
for(moveTo(S,0);getIndex(S)>=0;moveNext(S)){
    //printf("Component \n",getFinish(G4,1));
    if(getParent(T,getElement(S))==NIL){
        SCC=SCC+1;
    }
}


List SCCList=newList();
printf("G contains %d strongly connected components:\n",SCC);
i=1;
for(moveTo(S,getOrder(T)-1);getIndex(S)>=0;movePrev(S)){
    if(getParent(T,getElement(S))!=NIL){
        prepend(SCCList,getElement(S));
    }else{
    prepend(SCCList,getElement(S));
    printf("Component %d:",i);
    printList(stdout,SCCList);
    clear(SCCList);
    i++;
    }
}

//test for another graph G4
printf("\ntesting DFS graph G4\n");
Graph G4=newGraph(8);

addArc(G4,1,2);
addArc(G4,2,3);
addArc(G4,3,4);
addArc(G4,4,3);
addArc(G4,5,1);
addArc(G4,2,5);
addArc(G4,2,6);
addArc(G4,3,7);
addArc(G4,4,8);
addArc(G4,5,6);
addArc(G4,6,7);
addArc(G4,7,6);
addArc(G4,7,8);
addArc(G4,8,8);

clear(S);
//S=newList();
for(i=1;i<=getOrder(G4);i++){

    append(S,i);
}
printGraph(stdout, G4);
DFS(G4,S);
printf("getDiscover(G4,2):%d \n",getDiscover(G4,2));
printf("getParent(G4,2):%d \n",getParent(G4,2));
printf("getFinish(G4,1)%d \n",getFinish(G4,1));
printf("Stack:\n");
printList(stdout,S);

printf("transpose(G4) \n");
Graph GT=transpose(G4);
printGraph(stdout, GT);
//List SSC=newList();
//for(moveTo(S,0);getIndex(S)<getOrder(G4);moveNext(S)){
//    append(SSC,getElement(S));
//    }
DFS(GT,S);
SCC=0;
for(moveTo(S,0);getIndex(S)>=0;moveNext(S)){
    //printf("Component \n",getFinish(G4,1));
    if(getParent(GT,getElement(S))==NIL){
        SCC=SCC+1;
    }
}
printf("Stack:");
printList(stdout,S);
printf("\n");


//find strongly
clear(SCCList);

printf("\n");
for(moveTo(S,0);getIndex(S)>=0;moveNext(S)){
    //printf("Component \n",getFinish(G4,1));
    printf("vertex: %d, parent:%d, discovery:%d, finish:%d\n",getElement(S),getParent(GT,getElement(S)),getDiscover(GT, getElement(S)), getFinish(GT, getElement(S)));

}

printf("\n");
printf("G4 contains %d strongly connected components:\n",SCC);
i=1;
for(moveTo(S,getOrder(GT)-1);getIndex(S)>=0;movePrev(S)){
    if(getParent(GT,getElement(S))!=NIL){
        prepend(SCCList,getElement(S));
    }else{
    prepend(SCCList,getElement(S));
    printf("Component %d:",i);
    printList(stdout,SCCList);
    clear(SCCList);
    i++;
    }
}

printf("\n");
printf("G5=copy of G4:\n");
Graph G5=copyGraph(G4);
printGraph(stdout,G5);
printf("\n");
printf("G5 size:%d\n",getSize(G5));
printf("G5 order:%d\n",getOrder(G5));
printf("G5 vertex:  d  f  p\n");
   for(i=1; i<=n; i++){
      printf("%d:          %d  %d  %d\n", i, getDiscover(G5, i), getFinish(G5, i), getParent(G5, i));
   }
  
   // Free objects
   
   freeGraph(&G5);
   freeGraph(&GT);
   freeList(&S);
   freeList(&SCCList);
   freeGraph(&G4);
   //freeList(&Pa2);
   //freeGraph(&G3);

   freeList(&S);
   freeGraph(&G);
   freeGraph(&T);
   freeGraph(&C);
   return(0);
}



