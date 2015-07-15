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

   int count=0;
   int arrayLength;
   FILE *in,*in2, *out;
   char line[MAX_LEN];
   //char anArray[MAX_LEN];
   //char anArray2[MAX_LEN];
   //char* ptr;
   //char **stringArray = (char **)malloc(MAX_LEN* sizeof(char *));
   //char tokenlist[MAX_LEN];
   char* token;
   //int i;
   //int lineNumber;
   //int stringLength=10;

   // check command line for correct number of arguments
   
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
   in2 = fopen(argv[1], "r");
   //in = fopen("C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\in2.txt", "r");
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


 //int x;

int linesize=0;
   char buffer[MAX_LEN];
   while(fgets(buffer,MAX_LEN, in2) != NULL) {
      token=strtok (buffer, "\n");
      if(token!=NULL){ 
      linesize++;
      }
  }
  
   int size=linesize;
   
   count=0;
   char **array = (char **)malloc(MAX_LEN*sizeof(char*));
   //array=malloc(linesize*sizeof(char));
  while(fgets(line,MAX_LEN, in) != NULL) {
       token = strtok(line, "\n");
      if(token!=NULL){
      //strcat(token, "\0");
      size = strlen(token);
      array[count] = (char *)malloc((size+1)*sizeof(char));
      strcpy(array[count], token);
      //printf("%d\n",count);      
       //printf("%s\n",array[count]); 
      count++;
       
       }
     
      
  }
  

List A = newList();   
    
//insertion sort
       
        
         append(A,0);         
	 arrayLength=1;
         for(arrayLength=1;arrayLength<linesize;arrayLength++){
            //A.moveTo(k);              
            char* temp=array[arrayLength];    
            for(moveTo(A,0);getIndex(A)>=0;moveNext(A)){               
               if(length(A)==1){
                      if(strcmp(array[getElement(A)],temp)>0){
                      insertBefore(A,arrayLength);
                      break;
                     }else {               
                      insertAfter(A,arrayLength);
                     break;
                     }
                 }
              
            	  if(strcmp(array[getElement(A)],temp)>0||strcmp(array[getElement(A)],temp)>0){
                  insertBefore(A,arrayLength);
                  break;
                  }else if(getIndex(A)==length(A)-1){
                   insertAfter(A,arrayLength);
                   break;
                   }
              }
            }
   

    for(moveTo(A,0); getIndex(A)>=0; moveNext(A)){ 
       fprintf(out,"%s",array[getElement(A)]);
       fprintf(out,"\n");
       //printf("%s",array[getElement(A)]); 
       //printf("\n");
   }

  
freeList(&A);
int i;
for(i=0;i<linesize;i++){
free(array[i]);
}
free(array);


   /* close files */
   fclose(in);
   fclose(in2);
   fclose(out);

   return(0);
}

