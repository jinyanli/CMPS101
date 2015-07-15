//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_


// Exported type --------------------------------------------------------------


typedef struct ListObj* List;


void* myMalloc(size_t t);
void myFree(void*t);
// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object.

//new function**********************************
List newList(void);

//Inserts new element before front element in this List.
//return error if the argument is null
void prepend(List Q,int dataP);

// Inserts new element after back element in this List.
//return error if the argument is null
void append(List Q,int dataA);

// If 0<=i<=length()-1, moves the cursor to the element
// at index i, otherwise the cursor becomes undefined.
//return error if the argument is null
void moveTo(List Q, int i);

// Returns the index of the cursor element in this list, or
 // returns -1 if the cursor element is undefined.
//return error if the argument is null
int getIndex(List Q);

// Returns cursor element in this list.
 // Pre: length()>0, getIndex()>=0
//return error if the argument is null
int getElement(List Q);

// If 0<=getIndex()<length()-1, moves the cursor one step toward the
 // back of the list. If getIndex()==length()-1, cursor becomes
 // undefined. If getIndex()==-1, cursor remains undefined. This
 // operation is equivalent to moveTo(getIndex()+1).
//return error if the argument is null
void moveNext(List Q);

// Returns number of elements in this list.
//return error if the argument is null
int length(List Q);

// If 0<getIndex()<=length()-1, moves the cursor one step toward the
 // front of the list. If getIndex()==0, cursor becomes undefined.
 // If getIndex()==-1, cursor remains undefined. This operation is
 // equivalent to moveTo(getIndex()-1).
//return error if the argument is null
void movePrev(List Q);

// Returns a new list representing the same integer sequence as this
// list. The cursor in the new list is undefined, regardless of the
 // state of the cursor in this List. This List is unchanged.
//return error if the argument is null
List copyList(List Q);

// Inserts new element before cursor element in this
 // List. Pre: length()>0, getIndex()>=0
//return error if the argument is null
void insertBefore(List Q,int data1);

// Inserts new element after cursor element in this
 // List. Pre: length()>0, getIndex()>=0
//return error if the argument is null
void insertAfter(List Q,int data2);

// Deletes cursor element in this List. Cursor is undefined after this
 // operation. Pre: length()>0, getIndex()>=0
//return error if the argument is null
void delete(List Q);

// Re-sets this List to the empty state.
//return error if the argument is null
void clear(List Q);

// Deletes the front element in this List. Pre: length()>0
//return error if the argument is null
void deleteFront(List Q);

// Deletes the back element in this List. Pre: length()>0
//return error if the argument is null
void deleteBack(List Q);
//new function**********************************
// freeList()
// Frees all heap memory associated with List *pQ, and sets *pQ to NULL.
void freeList(List* pQ);


// Access functions -----------------------------------------------------------

// Front()
// Returns the value at the front of Q.
// Pre: !isEmpty(Q)
int front(List Q);

// back()
// Returns the value at the end of Q.
// Pre: !isEmpty(Q)
int back(List Q);
// Length()
// Returns the length of Q.
int length(List Q);

// isEmpty()
// Returns true (1) if Q is empty, otherwise returns false (0)
int isEmpty(List Q);


// Manipulation procedures ----------------------------------------------------


// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in Q on a single line to stdout.
void printList(FILE* out,List Q);

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B);

#endif

