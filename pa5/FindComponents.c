//-----------------------------------------------------------------------------
//Jinyan Li CMPS101 pa5
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
   //int BUFSIZE = 1000;
   int count=0;
   //int arrayLength;
   FILE *in, *out;
   //int line[MAX_LEN];

   //int* token;
   int i=0;
   //int lineNumber;


   // check command line for correct number of arguments
   
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing
   in = fopen(argv[1], "r");
   //in = fopen("C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\pa5\\pa5\\in1.txt", "r");
   //in2 = fopen("C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\pa4\\in22.txt", "r");
   out = fopen(argv[2], "w");
   //out = fopen("C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\pa5\\pa5\\out1(1).txt", "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   count=0;
   //int **array = (int**)malloc(MAX_LEN*sizeof(int*));
   //array=(char **)malloc(linesize*sizeof(char));
//array[count] = (int *)malloc((size+1)*sizeof(int));

  int intArray[MAX_LEN];
  fscanf (in, "%d", &i);
  intArray[count]=i;
  //int lineNum=1;
  while (!feof (in))
    {
/*
      printf (" %d ", intArray[count]);
      if(count%2==0){
      printf ("line:%d\n",lineNum);
      lineNum++;
      }
*/
      fscanf (in, "%d", &i);
      count++;
      intArray[count]=i;
   }
 //printf ("\n");
Graph G=NULL;
G=newGraph(intArray[0]);


//int lineNum=2;
for(i=1;intArray[i]!=0&&intArray[i+1]!=0;i=i+2){
addArc(G,intArray[i],intArray[i+1]);
//printf ("line:%d %d %d\n",lineNum, intArray[i],intArray[i+1]);
//lineNum++;
}
fprintf(out,"Adjacency list representation of G:\n");
//printGraph(stdout,G);
printGraph(out,G);
fprintf(out,"\n");

List S=newList();
for(i=1;i<=getOrder(G);i++){

    append(S,i);
}

//fprintf(out,"\n");

DFS(G,S);
Graph GT=transpose(G);
DFS(GT,S);

int SCC=0;
for(moveTo(S,0);getIndex(S)>=0;moveNext(S)){
    //printf("Component \n",getFinish(G4,1));
    if(getParent(GT,getElement(S))==NIL){
        SCC=SCC+1;
    }
}

List SCCList=newList();
fprintf(out,"G contains %d strongly connected components:\n",SCC);
i=1;
for(moveTo(S,getOrder(GT)-1);getIndex(S)>=0;movePrev(S)){
    if(getParent(GT,getElement(S))!=NIL){
        prepend(SCCList,getElement(S));
    }else{
    prepend(SCCList,getElement(S));
    fprintf(out,"Component %d: ",i);
    printList(out,SCCList);
    //fprintf(out,"\n");
    clear(SCCList);
    i++;
    }
}


   /* close files */
   freeList(&S);
   freeList(&SCCList);
   fclose(in);
   //fclose(in2);
   fclose(out);
   freeGraph(&G);
   freeGraph(&GT);
   return(0);
}

