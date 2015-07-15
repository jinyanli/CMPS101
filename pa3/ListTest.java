//-----------------------------------------------------------------------------
//  ListTest.java author:jinyan li pa3
//  A test client for the List ADT. Use this to test your list module. The
//  correct output is given below.
//-----------------------------------------------------------------------------
import java.lang.Double;
import java.lang.Integer;
public class ListTest{
   public static void main(String[] args){
      List<Integer> A = new List<Integer>();
      List<Integer> B = new List<Integer>();
      
      for(int i=1; i<=30; i++){
         A.append(i);
         B.prepend(i);
      }
      System.out.println("List A: "+A);
      System.out.println("List B: "+B);
      
      for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
          System.out.print(A.getElement()+" ");
      }
      System.out.println();
      for(B.moveTo(B.length()-1); B.getIndex()>=0; B.movePrev()){
          System.out.print(B.getElement()+" ");
      }
      System.out.println();
      
      List C = A.copy();
      System.out.println("A.equals(B)?: "+A.equals(B));
      System.out.println("B.equals(C)?: "+B.equals(C));
      System.out.println("C.equals(A)?: "+C.equals(A));
      
      System.out.println("A.front()="+A.front());
      System.out.println("A.back()="+A.back());
      
      //test for insert aefore and after, delete, moveto, and clear method
      System.out.println("test for insert before and after, delete, moveto, and clear method");
      A.moveTo(0);
      A.insertBefore(123);
      A.moveTo(A.length()-1);
      A.insertAfter(456);
      A.moveTo(15);
      A.moveTo(5);
      A.insertBefore(-1);
      A.moveTo(15);
      A.insertAfter(-2);
      A.moveTo(10);
      A.delete();
      System.out.println(A);
      System.out.println("A.deleteBack() and A.deleteFront();");
      A.deleteBack();
      A.deleteFront();
      System.out.println(A);
      A.clear();
      System.out.println("A.deleteBack() and A.deleteFront();");
      System.out.println("A.deleteBack() and A.deleteFront();");
      A.deleteBack();
      A.deleteFront();
      System.out.println("A.front()="+A.front());
      System.out.println("A.back()="+A.back());
      System.out.println("A.length():"+A.length());
      System.out.println("A.isEmpty()"+A.isEmpty());
   }
}

// Output of this program:
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// false
// false
// true
// 1 2 3 4 5 -1 6 7 8 9 11 12 13 14 15 -2 16 17 18 19 20
// 0

