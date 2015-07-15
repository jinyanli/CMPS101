//-----------------------------------------------------------------------------
//Jinyan Li CMPS101 pa4
//FindPath.c
//This program will takes two arguments first one is the input file second one is output file
//This program will read the graph data in input file and print out the adj list and path to certain vertex from source vertex
//of the graph in output file
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"Graph.h"
#define INF -1
#define NIL 0
#define MAX_LEN 3000

int main(int argc, char **argv){

   int count=0;
   FILE *in, *out;
   int i=0;


   // check command line for correct number of arguments
   
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing
   in = fopen(argv[1], "r");
   
   out = fopen(argv[2], "w");
 
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   count=0;

  int intArray[MAX_LEN];
  fscanf (in, "%d", &i);
  intArray[count]=i;

  while (!feof (in))
    {
      fscanf (in, "%d", &i);
      count++;
      intArray[count]=i;
   }
 //printf ("\n");
Graph G=NULL;
G=newGraph(intArray[0]);



for(i=1;intArray[i]!=0&&intArray[i+1]!=0;i=i+2){
addEdge(G,intArray[i],intArray[i+1]);

}

printGraph(out,G);
//fprintf(out,"\n");
List L=newList();

for(i=i+2;intArray[i]!=0&&intArray[i+1]!=0;i=i+2){

    BFS(G,intArray[i]);
    getPath(L,G,intArray[i+1]);
    if(getDist(G,intArray[i+1])!=INF){
    fprintf(out,"\n");
    fprintf(out,"The distance from %d to %d is %d \n",intArray[i],intArray[i+1],getDist(G,intArray[i+1]));
    fprintf(out,"A shortest %d-%d path is: ",intArray[i],intArray[i+1]);
    printList(out,L);
    
    clear(L);
    }else{
    fprintf(out,"The distance from %d to %d is infinity \n",intArray[i],intArray[i+1]);
    fprintf(out,"No %d-%d path exists \n",intArray[i],intArray[i+1]);
    fprintf(out,"\n");
    clear(L);
    }
}



   /* close files */
   freeList(&L);
   fclose(in);
   fclose(out);
   freeGraph(&G);
   return(0);
}

