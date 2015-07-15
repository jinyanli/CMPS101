//-----------------------------------------------------------------------------
// List.c
// Implementation file for List ADT
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "List.h"
int globalMalloc;
// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   int data;
   struct NodeObj* next;
   struct NodeObj* previous;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type

typedef struct ListObj{
   Node front;
   Node back;
   int length;
   Node cursor;
   int cursorIndex;
} ListObj;

// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.

Node newNode(int data){
   Node N = malloc(sizeof(NodeObj));
   N->data = data;
   N->next = NULL;
   N->previous=NULL;
   return(N);
}

//struct Node* front;


void* myMalloc(size_t t)
{
    globalMalloc++;    //global counter
    void*p = malloc(t);
    if(p==NULL) printf("error: can not allocate");
    return p;
}
void myFree(void*t)
{
    if(t == NULL)   printf(".,.,.,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,ERROR");
    globalMalloc--; //global counter
    free(t);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(void){
   List Q;
   Q = malloc(sizeof(ListObj));
   Q->front = Q->back = NULL;
   Q->length = 0;
   Q->cursor = 0;
   return(Q);
}


// freeList()
// Frees all heap memory associated with List *pQ, and sets *pQ to NULL.S
void freeList(List* pQ){
   if(pQ!=NULL && *pQ!=NULL) {
      while( !isEmpty(*pQ) ) {
         DeList(*pQ);
      }
      free(*pQ);
      *pQ = NULL;
   }
}


// Access functions -----------------------------------------------------------

// getFront()
// Returns the value at the front of Q.
// Pre: !isEmpty(Q)

/////////////////////////////////////////////////

//Inserts new element before front element in this List.
//return error if the argument is null
void prepend(List Q,int dataP){
    if(Q==NULL){
        printf("Error: prepend() has Null reference");
        exit(1);
    }

   

     if(Q->front==NULL){
       Node N=newNode(dataP);
           Q->front=N;
   	   Q->cursor=Q->front;
   	   }
     else{
         Node N=newNode(dataP);
           N->next=Q->front;
   	   Q->front->previous=N;
   	   Q->front=N;
   	}
   	Q->length++;
       // Q->cursorIndex++;
   }

// Inserts new element after back element in this List.
//return error if the argument is null
void append(List Q,int data){
  if(Q==NULL){
        printf("Error:append() Null reference");
        exit(1);
    }
   
     if(Q->front==NULL){
   	    Node N=newNode(data);
            Q->front=N;
           //Q->back=N;
   	   Q->cursor=Q->front;
   	   }
     else{
           Node N=newNode(data);
           Q->back=Q->front;
   	   while(Q->back->next!=NULL){
   	   Q->back=Q->back->next;
   	     }
   	   Q->back->next=N;
           N->previous=Q->back;
	  }
   	Q->length++;
   }

// If 0<=i<=length()-1, moves the cursor to the element
// at index i, otherwise the cursor becomes undefined.
//return error if the argument is null
void moveTo(List Q, int index){
        if(Q==NULL){
        printf("Error:moveTO() Null reference");
        exit(1);
    }

    if(Q->front==NULL){
            printf("Empty List\n");
       // exit(1);
        }
       else{
       if(index < 0|| index >=Q->length)
           printf("Wrong Index\n");
       //exit(1);
       }

       Q->cursor=Q->front;
       Q->cursorIndex=index;
       int i=0;
       if(index!=0){
       while(i < index){
      	      Q->cursor=Q->cursor->next;
      	      i++;
       		}
      }
 }

// Returns the index of the cursor element in this list, or
 // returns -1 if the cursor element is undefined.
//return error if the argument is null
int getIndex(List Q){
    if(Q==NULL){
        printf("Error: GetIndex() has Null reference");
        exit(1);
    }
    return Q->cursorIndex;
                     }

// Returns cursor element in this list.
// Pre: length()>0, getIndex()>=0
//return error if the argument is null
int getElement(List Q){
     if(Q==NULL){
        printf("Error: getElement has Null reference");
        exit(1);
    }
    if(length(Q)>0&&getIndex(Q)>=0){
   	   return Q->cursor->data;
      }
     else{
      return 0;
      }
}

// If 0<=getIndex()<length()-1, moves the cursor one step toward the
// back of the list. If getIndex()==length()-1, cursor becomes
// undefined. If getIndex()==-1, cursor remains undefined. This
// operation is equivalent to moveTo(getIndex()+1).
//return error if the argument is null
void moveNext(List Q){
    if(Q==NULL){
        printf("Error: moveNext() has Null reference");
        exit(1);
    }
    if(getIndex(Q)>=length(Q)){
       Q->cursorIndex=-1;
      }
    if(Q->cursor->next==NULL){
       Q->cursorIndex=-1;
      }
       if(0<=getIndex(Q)&&getIndex(Q)<=length(Q)-1){
     Q->cursor=Q->cursor->next;
     Q->cursorIndex++;
    }
}

// Returns number of elements in this list.
//return error if the argument is null
int length(List Q){
    if(Q==NULL){
        printf("Error: length() has Null reference");
        exit(1);
    }
    if( Q==NULL ){
      printf("List Error: calling getLength() on NULL List reference\n");
      exit(1);
   }
    return Q->length;
}

// If 0<getIndex()<=length()-1, moves the cursor one step toward the
// front of the list. If getIndex()==0, cursor becomes undefined.
// If getIndex()==-1, cursor remains undefined. This operation is
// equivalent to moveTo(getIndex()-1).
//return error if the argument is null
void movePrev(List Q){
    if(Q==NULL){
        printf("Error: movePrev() has Null reference");
        exit(1);
    }
    if(getIndex(Q)<=0){
        Q->cursorIndex=-1;
        Q->cursor=NULL;
      }
     if(0<getIndex(Q)&&getIndex(Q)<=length(Q)-1){
     Q->cursor=Q->cursor->previous;
     Q->cursorIndex--;
      }
}

// Returns a new list representing the same integer sequence as this
// list. The cursor in the new list is undefined, regardless of the
// state of the cursor in this List. This List is unchanged.
//return error if the argument is null
List copyList(List Q){
    if(Q==NULL){
        printf("Error: copyList) has Null reference");
        exit(1);
    }
    List newQ=newList();
    Node N;
      N=Q->front;

      while( N!=NULL ){
         append(newQ,N->data);
         N = N->next;
      }
      return newQ;
   }

// Inserts new element before cursor element in this
 // List. Pre: length()>0, getIndex()>=0
//return error if the argument is null
void insertBefore(List Q,int data1){
   	   if(Q==NULL){
        printf("Error: insertBefore() has Null reference");
        exit(1);
    }
    if(length(Q)>0&&getIndex(Q)>=0)
   	   {
                   if(Q->cursor->previous!=NULL){
   	   	  //Node NewNode=new Node(cursor.previous,data1,cursor);
                  Node N=newNode(data1);

                  N->previous=Q->cursor->previous;
                  N->next=Q->cursor;
                  Q->cursor->previous->next=N;
                  Q->cursor->previous=N;
                  Q->cursorIndex++;
                  }
                  if(Q->cursor->previous==NULL){
                    //Node NewNode=new Node(null,data1,cursor);
                      Node N=newNode(data1);
                    Q->cursor->previous=N;
                    N->next=Q->cursor;
                    Q->front=N;
                    Q->cursorIndex++;
                  }
                   Q->length++;
   	   }else{
               printf("Empty List\n");
           }

   }

// Inserts new element after cursor element in this
 // List. Pre: length()>0, getIndex()>=0
//return error if the argument is null
void insertAfter(List Q,int data2){
   	     if(Q==NULL){
        printf("Error: insertAfter() has Null reference");
        exit(1);
    }
    if(length(Q)>0&&getIndex(Q)>=0)
   	   {
   	   	   //Node NewNode=new Node(cursor,data2,cursor.next);
                       Node N=newNode(data2);
                       N->previous=Q->cursor;
                       N->next=Q->cursor->next;
                     if(Q->cursor->next!=NULL){
                     //NewNode.next=cursor.next;
                     N->next=Q->cursor->next;
                     Q->cursor->next->previous=N;
                     }

                    N->previous=Q->cursor;
                    Q->cursor->next=N;
                    Q->length++;


   	   }else{
               printf("Empty List\n");
           }
   }

// Deletes cursor element in this List. Cursor is undefined after this
 // operation. Pre: length()>0, getIndex()>=0
//return error if the argument is null
void delete(List Q){
   if(Q==NULL){
        printf("Error: delete() has Null reference");
        exit(1);
   }

    if(length(Q)>0&&getIndex(Q)>=0){
        if(Q->cursor->previous!=NULL&&Q->cursor->next!=NULL){
        Q->cursor->previous->next=Q->cursor->next;
        Q->cursor->next->previous=Q->cursor->previous;
        Q->cursor=NULL;
        }
      else if(Q->cursor->previous==NULL){
      Q->cursor->next->previous=NULL;
      Q->cursor=NULL;
      }
      else if(Q->cursor->next==NULL){
      Q->cursor->previous->next=NULL;
      Q->cursor=NULL;
        }
        Q->length--;
        Node N=Q->cursor;
        freeNode(&N);
     }
   else  printf("Empty List\n");
  }

// Re-sets this List to the empty state.
//return error if the argument is null
void clear(List Q){
   if(Q==NULL){
        printf("Error: clear() has Null reference");
        exit(1);
   }
   while(!isEmpty(Q)){
    DeList(Q);
   }
   /*
   freeList(Q);
   Q->cursor=NULL;
   Q->front=NULL;
   */
   //Q->length=0;
   }

// Deletes the front element in this List. Pre: length()>0
//return error if the argument is null
void deleteFront(List Q){
 if(Q==NULL){
        printf("Error: deleteFront() has Null reference");
        exit(1);
   }
 //if(Q->front==NULL) return;

   	   Q->front=Q->front->next;
   	   Q->front->previous=NULL;
   	    Node N=Q->front->previous;
        freeNode(&N);
   	   Q->length--;
}

//Deletes the back element in this List. Pre: length()>0
//return error if the argument is null
void deleteBack(List Q){
    if(Q==NULL){
        printf("Error: deleteFront() has Null reference");
        exit(1);
   }

      Node current=Q->front;
      while(current->next->next!=NULL){
      current=current->next;
      }
      current->next=NULL;
      Node N=current->next;
        freeNode(&N);
      Q->length--;

}

/////////////////////////////////////////////////

int front(List Q){
   if( Q==NULL ){
      printf("List Error: calling Front() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(Q) ){
      printf("List Error: calling Front() on an empty List\n");
      exit(1);
   }
   return(Q->front->data);
}

// getLength()
// Returns the length of Q.
int getLength(List Q){
   if( Q==NULL ){
      printf("List Error: calling getLength() on NULL List reference\n");
      exit(1);
   }
   return(Q->length);
}

// isEmpty()
// Returns true (1) if Q is empty, otherwise returns false (0)
int isEmpty(List Q){
   if( Q==NULL ){
      printf("List Error: calling isEmpty() on NULL List reference\n");
      exit(1);
   }
   return(Q->length==0);
}


// Manipulation procedures ----------------------------------------------------

// EnList()
// Places new data element at the end of Q
void EnList(List Q, int data)
{
   Node N = newNode(data);

   if( Q==NULL ){
      printf("List Error: calling EnList() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(Q) ) { Q->front = Q->back = N; }
   else { Q->back->next = N; Q->back = N; }
   Q->length++;
}

// DeList()
// Deletes element at front of Q
// Pre: !isEmpty(Q)
void DeList(List Q){
   Node N = NULL;

   if( Q==NULL ){
      printf("List Error: calling DeList() on NULL List reference\n");
      exit(1);
   }
   if( isEmpty(Q) ){
      printf("List Error: calling DeList on an empty List\n");
      exit(1);
   }
   N = Q->front;
   if( getLength(Q)>1 ) {
            Q->front = Q->front->next;
   }
   else {
            Q->front = Q->back = NULL;
   }
   Q->length--;
   freeNode(&N);
}


// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in Q on a single line to stdout.
void printList(FILE* out,List Q){
   Node N = NULL;

   if( Q==NULL ){
      printf("List Error: calling printList() on NULL List reference\n");
      exit(1);
   }
   for(N = Q->front; N != NULL; N = N->next){
      fprintf(out,"%d ", N->data);
   }
   fprintf(out,"\n");
}

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B){
   int flag = 1;
   Node N = NULL;
   Node M = NULL;

   if( A==NULL || B==NULL ){
      printf("List Error: calling equals() on NULL List reference\n");
      exit(1);
   }
   N = A->front;
   M = B->front;
   if( A->length != B->length ) { return 0; }
   while( flag && N!=NULL){
      flag = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return flag;
}

// Enqueue()
// Places new data element at the end of Q
void Enqueue(List Q, int data)
{
   Node N = newNode(data);

   if( Q==NULL ){
      printf("Queue Error: calling Enqueue() on NULL Queue reference\n");
      exit(1);
   }
   if( isEmpty(Q) ) { Q->front = Q->back = N; }
   else { Q->back->next = N; Q->back = N; }
   Q->length++;
}

// Dequeue()
// Deletes element at front of Q
// Pre: !isEmpty(Q)
void Dequeue(List Q){
   Node N = NULL;

   if( Q==NULL ){
      printf("Queue Error: calling Dequeue() on NULL Queue reference\n");
      exit(1);
   }
   if( isEmpty(Q) ){
      printf("Queue Error: calling Dequeue on an empty Queue\n");
      exit(1);
   }
   N = Q->front;
   if( getLength(Q)>1 ) { Q->front = Q->front->next; }
   else { Q->front = Q->back = NULL; }
   Q->length--;
   freeNode(&N);
}

