//-----------------------------------------------------------------------------
// ListTest.c
// A test client for List ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include"List.h"

int main(int argc, char* argv[]){

   int i;
   List A = newList();
   List B = newList();

   for(i=1; i<=10; i++){
      EnList(A, i);
      EnList(B, 11-i);
   }
   printList(A);
   printList(B);
   printf("\n");

   for(i=1; i<=6; i++){
      EnList(A, getFront(B));
      DeList(B);
   }
   printList(A);
   printList(B);
   printf("\n");

   printf("%s\n", equals(A,B)?"true":"false");
   printf("%s\n", equals(A,A)?"true":"false");

   freeList(&A);
   freeList(&B);

   return(0);
}

