//-----------------------------------------------------------------------------
//Author Jinyan Li, CMPS 101, pa2
// Lex.c
// Illustrates file input-output commands and text processing using the
// string functions strtok and strcat.
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"

#define MAX_LEN 160

int main(int argc, char * argv[]){

   int n, count=0;
   int arrayLength;
   FILE *in,*in2,*in3, *out;
   char line[MAX_LEN];
   char anArray[MAX_LEN];
   char anArray2[MAX_LEN];
   char* ptr;
   //char **stringArray = (char **)malloc(MAX_LEN* sizeof(char *));
   char tokenlist[MAX_LEN];
   char* token;
   int i;
   int lineNumber;
   int stringLength=10;

   // check command line for correct number of arguments
   
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
   //in = fopen("C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\in1.txt", "r");
   out = fopen(argv[2], "w");
   //out = fopen("C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\out.txt", "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }
   i=0;
   n=0;
   int x=0;
    int y=0;
   ptr=anArray;
 
    
  while(fgets(line, MAX_LEN, in) != NULL){   
         
      token = strtok(line, "\n");             
      x=0;        
     if(token!=NULL){
      lineNumber++;
        //printf("input: %s\n",line); 
        for(y=0;y<stringLength;y++){
          anArray[i]=*(token+x);
          x++;
          i++;
        } 
      } 
             
  }
   
   i=0;
   
   for(i=0;i<lineNumber;i++){
       anArray2[i]=anArray[i*stringLength];    
   }
   
//Testing code
//printf("number of elemsnt :%d",lineNumber);  
//printf("\n");

List A = newList();   
    
//insertion sort
       
         x=0;
         append(A,0);         
	 arrayLength=1;
         for(arrayLength=1;arrayLength<lineNumber;arrayLength++){
            //A.moveTo(k);              
            char temp=anArray2[arrayLength];    
            for(moveTo(A,0);getIndex(A)>=0;moveNext(A)){               
               if(length(A)==1){
                      if(anArray2[getElement(A)]>temp){
                      insertBefore(A,arrayLength);
                      break;
                     }else {               
                      insertAfter(A,arrayLength);
                     break;
                     }
                 }
              
            	  if(anArray2[getElement(A)]>temp||anArray2[getElement(A)]==temp){
                  insertBefore(A,arrayLength);
                  break;
                  }else if(getIndex(A)==length(A)-1){
                   insertAfter(A,arrayLength);
                   break;
                   }
              }
            }
   i=0;
 
/*Testing code
     printf("List Order: ");
      for(moveTo(A,0); getIndex(A)>=0; moveNext(A)){ 
       printf("%d",getElement(A)); 
     }
       printf("\n");

      for(i=0;i<30;i++){  
             printf("%c",anArray[i]);
            if(anArray[i]!='\0') {
            fprintf(out,"%c",anArray[i]);
          }
        } 
 
*/
      //printf("\r\n"); 
     //printf("\nsorted list \n");
//output
       for(moveTo(A,0); getIndex(A)>=0; moveNext(A)){ 
         for(i=stringLength*getElement(A);i<stringLength*getElement(A)+stringLength;i++){  
            if(anArray[i]!='\0') {
             //printf("%c",anArray[i]);
            fprintf(out,"%c",anArray[i]);
            }else break;
        }   
         //printf("\r\n");   
         fprintf(out,"\r\n");       
   }
   
freeList(&A);
   
   
   /* read each line of input file, then count and print tokens */
  
/*
      fprintf(out, "line %d contains %d token%s: \n", count, n, n==1?"":"s");
      fprintf(out, "%s\n", tokenlist);
   
*/

   /* close files */
   fclose(in);
   fclose(out);

   return(0);
}

