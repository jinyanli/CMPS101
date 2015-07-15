//List.java Author Jinyan Li, Class CMPS101 pa3
//---------------------------------------------------------------------------------------
//
//   This file constitutes the solution to the first excercise in the ADT handout.
//   Recall that all ADT operations should state their own preconditions in a comment
//   block, and then check that those conditions are satisfied.  If a precondition is
//   violated, the ADT operation should cause the program to quit with a useful error
//   message.  See functions getFront() and Dequeue() below for examples on how to do
//   this. Observe that I've added two other operations called equals() and copy()
//   respectively.  equals() compares two queues for equality and returns an appropriate
//   boolean value.  Note that equals() does not overide Object's equals() method. copy()
//   creates a new List object identical to it's argument List.
//
//---------------------------------------------------------------------------------------

public class List<T>{

   private class Node <T>{
      // Fields
      T data;
      Node next;
      Node previous;
      // Constructor
      Node(T data) { 
      	      this.data = data;
      	      next = null; 
      	      previous=null;
      }
      Node(Node previous, T data, Node next) { 
      	      this.previous=previous;
       	      this.data = data;
      	      this.next = next; 
      	      
      }
      public boolean equals(Object X){
            Node N=(Node)X;
          if(this.data.equals(N.data)){
                return true;
            }else{
                return false;
            }
      }
      // toString:  Overides Object's toString method.
      public String toString() { return String.valueOf(data); }
   }

   // Fields
   
   private Node front;
   private Node back;
   private Node cursor;
   private int cursorIndex;
   private int length;

   // Constructor
   List() {
   front = back =cursor= null; 
   length = 0; 
   cursorIndex=0;
   }
// Inserts new element before front element in this List.
   void prepend(T data){
   	   if(front==null){
   	   front=new Node(null,data,null);
   	   cursor=front;
   	   }
   	   else{
   	   Node newNode=new Node(null,data,front);
   	   front.previous=newNode;
   	   front=newNode;
   	}
   	length++;
   }  
   
   // Inserts new element after back element in this List.
   void append(T data){
   	   if(front==null){
   	   front=new Node(null,data,null);
   	   cursor=front;
   	   }
   	   else{
   	   Node current=front;
   	   while(current.next!=null){
   	   current=current.next;
   	     }
   	   Node newNode=new Node(current,data,null);
   	   current.next=newNode;
            newNode.previous=current;
   	  }
   	
   	length++;
   }
   
   // Inserts new element before cursor element in this
// List. Pre: length()>0, getIndex()>=0
   void insertBefore(T data1){
   	   if(length()>0&&getIndex()>=0)
   	   {
                   if(cursor.previous!=null){
   	   	  Node NewNode=new Node(cursor.previous,data1,cursor);
                  NewNode.previous=cursor.previous;
                  cursor.previous.next=NewNode;
                  cursor.previous=NewNode;
                  cursorIndex++;
                  }
                  if(cursor.previous==null){
                    Node NewNode=new Node(null,data1,cursor);
                    cursor.previous=NewNode;
                    NewNode.next=cursor;
                    front=NewNode;
                    cursorIndex++;
                  }                   	   	 
                   length++;
   	   }
   
   }
      
   // Inserts new element after cursor element in this
// List. Pre: length()>0, getIndex()>=0
   void insertAfter(T data2){
   	    if(length()>0&&getIndex()>=0)
   	   {
   	   	   Node NewNode=new Node(cursor,data2,cursor.next);
                     if(cursor.next!=null){
                     NewNode.next=cursor.next;
                     cursor.next.previous=NewNode;
                     }
                   NewNode.previous=cursor;   	   	 
                   length++;
   	   	  cursor.next=NewNode;
   	   	  
   	   }
   }
   
   // Deletes cursor element in this List. Cursor is undefined after this
// operation. Pre: length()>0, getIndex()>=0
   void delete(){
   if(length()>0&&getIndex()>=0){
        if(cursor.previous!=null&&cursor.next!=null){
        cursor.previous.next=cursor.next;
        cursor.next.previous=cursor.previous;
        cursor=null;
        }
      else if(cursor.previous==null){
      cursor.next.previous=null;
      cursor=null;
      }
      else if(cursor.next==null){
      cursor.previous.next=null;
      cursor=null;
        }   
   } 
   else return;
  }
   
   
   // If 0<=i<=length()-1, moves the cursor to the element
// at index i, otherwise the cursor becomes undefined.
   void moveTo(int index){
       if(front==null) return;
       else{
       if(index < 0|| index >=length) return; 
       }       
       cursor=front;
       cursorIndex=index;
       int i=0;
       if(index!=0){     
       while(i < index){
      	      cursor=cursor.next;
      	      i++;
       		}
      }
   }
   
 
   // If 0<getIndex()<=length()-1, moves the cursor one step toward the
// front of the list. If getIndex()==0, cursor becomes undefined.
// If getIndex()==-1, cursor remains undefined. This operation is
// equivalent to moveTo(getIndex()-1).
   void movePrev(){
      if(getIndex()<=0){
        cursorIndex=-1;
        cursor=null;
      }
     if(0<getIndex()&&getIndex()<=length()-1){
     cursor=cursor.previous;
     cursorIndex--;  
      }
     
      
   }
   
   // If 0<=getIndex()<length()-1, moves the cursor one step toward the
// back of the list. If getIndex()==length()-1, cursor becomes
// undefined. If getIndex()==-1, cursor remains undefined. This
// operation is equivalent to moveTo(getIndex()+1).
   void moveNext(){
  if(getIndex()>=length()){ 
       cursorIndex=-1; 
      }
    if(cursor.next==null){ 
       cursorIndex=-1; 
      }
       if(0<=getIndex()&&getIndex()<=length()-1){
     cursor=cursor.next;
     cursorIndex++;  
    }
   }
     
   // Deletes the front element in this List. Pre: length()>0
   void deleteFront(){
   	   if(front==null) return;
   	   
   	   front=front.next;
   	   front.previous=null;
   	   length--;
   }
   
   // Re-sets this List to the empty state.
   void clear(){
   cursor=null;
   front=null;
   length=0;
   }
   
   // Deletes the back element in this List. Pre: length()>0
   void deleteBack(){
   if(front==null) return;
   
   if(front.next==null){
      front=null;
      length--;
      return;
      }
      Node current=front;
      while(current.next.next!=null){
      current=current.next;
      }
      current.next=null;
      length--;
   }
   
   void print(){
   Node current=front;
   while(current!=null){
   System.out.println(current.data);
   current=current.next;
     }
   }
   
   // Access Functions //////////////////////////////////////////////////////////////////
   // Returns cursor element in this list.
// Pre: length()>0, getIndex()>=0
   T getElement(){
   if(length()>0&&getIndex()>=0){
   	   return (T) cursor.data;
      }
     else{
      return null;
      }
   }
   
   // Returns number of elements in this list.
   int length(){
   return length;
   }
 
   // Returns the index of the cursor element in this list, or
// returns -1 if the cursor element is undefined.
   int getIndex(){
   /*if(length!=0&&cursor.next==null&&cursor.previous==null)return 1;
   if(length==0) return 0;
   */
     return cursorIndex;
   }
   
   // Returns front element in this list. Pre: length()>0
  T front(){
     if(length>0){
      return (T)front.data;
     }else{
         System.out.println("Error:length!>0");
     return null;
     }
   }
   
  // Returns back element in this List. Pre: length()>0
  T back(){
      if(length>0){
   	   int x=getIndex();
   	   int y;
   	   moveTo(length-1);  	   
   	   return (T)cursor.data; 
      }else{
         System.out.println("Error:length!>0");
     return null;
     }           
   }
   
   // equals(): returns true if this List is identical to  Q, false otherwise.
  public boolean equals(Object X){
      boolean flag  = true;
      List Q=(List)X;
      Node N = this.front;
      Node M = Q.front;

      if( this.length==Q.length ){
         while( flag && N!=null){
            flag = (N.data.equals(M.data));
            N = N.next;
            M = M.next;
         }
         return flag;
      }else{
         return false;
      }
   }

   // Manipulation Procedures ///////////////////////////////////////////////////////////


   // Other Functions ///////////////////////////////////////////////////////////////////

   // toString():  overides Object's toString() method.
   public String toString(){
      String str = "";
      for(Node N=front; N!=null; N=N.next){
         str += N.toString()+" ";
      }
      return str;
   }

   ///////////////////////////////////////////////////////////

   // Enqueue(): appends data to back of this queue
   void Enqueue(T data){
      Node node = new Node(data);
      if( this.isEmpty() ) { front = back = node; }
      else { back.next = node; back = node; }
      length++;
   }

   // Dequeue(): deletes element from front of this queue
   // Pre: !this.isEmpty()
   void Dequeue(){
      if(this.isEmpty()){
         throw new RuntimeException("Queue Error: Dequeue() called on empty Queue");
      }
      if(this.length>1) {front = front.next;}
      else {front = back = null;}
      length--;
   }
   // isEmpty(): returns true if this is an empty queue, false otherwise
   boolean isEmpty() { return length==0; }
   
   // copy(): returns a new List identical to this one.
   List copy(){
      List Q = new List();
      Node N = this.front;

      while( N!=null ){
         Q.Enqueue(N.data);
         N = N.next;
      }
      return Q;
   }

}
