//-----------------------------------------------------------------------------
// Jinyan Li CMPS101 pa3
//MatrixTest.java 
//  A test client for the Matrix ADT
//-----------------------------------------------------------------------------

public class MatrixTest{
   public static void main(String[] args){
      int i, j, n=10000;
      Matrix A = new Matrix(n);
      Matrix B = new Matrix(n);
      Matrix test1 = new Matrix(n);
      Matrix test2 = new Matrix(n);
      Matrix test3 = new Matrix(-1);

      ///matrix 1 and 2
      A.changeEntry(1,1,1);B.changeEntry(1,1,1);
      A.changeEntry(1,2,2);B.changeEntry(1,2,0);     
      A.changeEntry(1,3,3); B.changeEntry(1,3,1);   
      A.changeEntry(2,1,4); B.changeEntry(2,1,0);    
      A.changeEntry(2,2,5); B.changeEntry(2,2,1);    
      A.changeEntry(2,3,6); B.changeEntry(2,3,0);     
      A.changeEntry(3,1,7); B.changeEntry(3,1,1);      
      A.changeEntry(3,2,8); B.changeEntry(3,2,1);
      A.changeEntry(3,3,9); B.changeEntry(3,3,1);
           
      //matrix3
      test1.changeEntry(4, 7, -2402.8);
      test1.changeEntry(6, 5, -3604.1);
      test1.changeEntry(3, 1, -3013.9);
      test1.changeEntry(5, 7, -9982.4);
      test1.changeEntry(7, 9, -644.5);
      test1.changeEntry(8, 7, 1820.5);
      test1.changeEntry(1, 4, 5830.3);
      test1.changeEntry(6, 4, 5568);
      test1.changeEntry(8, 9, 9063.2);
      test1.changeEntry(6, 7, 8095.4);
      test1.changeEntry(5, 1, -1114.8);
      test1.changeEntry(2, 4, -6315.9);
      test1.changeEntry(1, 1, 8596.3);
      test1.changeEntry(4, 5, -9229.6);
      test1.changeEntry(8, 8, -4961.3);
      
      //matrix4
      test2.changeEntry(5, 2, 816.8);
      test2.changeEntry(10, 3, 9159.8);
      test2.changeEntry(2, 10, -872.5);
      test2.changeEntry(1, 2, 835.0);
      test2.changeEntry(3, 8, 9269.1);
      test2.changeEntry(3, 5, -5437.9);
      test2.changeEntry(7, 1, -8517.1);
      test2.changeEntry(7, 3, 2903.1);
      test2.changeEntry(6, 3, 848.7);
      test2.changeEntry(4, 8, 6786.0);
      test2.changeEntry(8, 9, 3664.7);
      test2.changeEntry(9, 10, -2108.5);
      
      //Test for matrix 1 and 2
      testMatrixFunction("Test1: Test for ordered inputs matrix","A","B",A,B);
      testMatrixFunction("Test2: Test for unordered inputs matrix","test1","test2",test1,test2);
      
      
   }
 //method for testing Matrix ADT function arg1:information of the test, arg2:name for matrix 1, 
 //arg3:name for matrix 2,arg4:input1,arg5:input2
   public static void testMatrixFunction(String info,String name1,String name2, Matrix A,Matrix B){
     System.out.println(info+" "+name1+" "+name2);
      
      System.out.println("print matrix "+name1+" \r\n number of none zero element "+A.getNNZ()+"");
      System.out.println(A);

      
      
      //print matrix  B
      System.out.println("print matrix "+name2+"\r\n number of none zero element "+B.getNNZ()+"  ");
      System.out.println(B);
      
      System.out.println("Operation test for matrix 1 and 2:");
      System.out.println(name1+"*1.5");
      Matrix C = A.scalarMult(1.5);
      System.out.println("number of none zero element: "+C.getNNZ());
      System.out.println(C);
      
      System.out.println(name1+"*1.5");
      Matrix D = B.scalarMult(1.5);
      System.out.println("number of none zero element: "+D.getNNZ());
      System.out.println(D);
      
      
      System.out.println(name1+".add("+name2+")");
      Matrix E = A.add(B);
      System.out.println("number of none zero element: "+E.getNNZ());
      System.out.println(E);
      
      System.out.println(name1+".add("+name1+")");
      Matrix F = A.add(A);
      System.out.println("number of none zero element: "+F.getNNZ());
      System.out.println(F);
      
      System.out.println(name2+".add("+name2+")");
      Matrix G = B.add(B);
      System.out.println("number of none zero element: "+G.getNNZ());
      System.out.println(G);
      
      
      System.out.println(name2+".sub("+name1+")");
      Matrix H = B.sub(A);
      System.out.println("number of none zero element: "+H.getNNZ());
      System.out.println(H);
      
      System.out.println(name1+".sub("+name2+")");
      Matrix I = A.sub(B);
      System.out.println("number of none zero element: "+I.getNNZ());
      System.out.println(I);
      
      System.out.println(name1+".sub("+name1+")");
      Matrix J = A.sub(B);
      System.out.println("number of none zero element: "+J.getNNZ());
      System.out.println(J);
      
      System.out.println(name2+".transpose();");
      Matrix K = B.transpose();
      System.out.println("number of none zero element: "+K.getNNZ());
      System.out.println(K);

      System.out.println(name1+".mul("+name2+")");
      Matrix L = A.mult(B);
      System.out.println("number of none zero element: "+L.getNNZ());
      System.out.println(L);
      
      System.out.println(name1+".mul("+name1+")");
      Matrix L2 = A.mult(A);
      System.out.println("number of none zero element: "+L.getNNZ());
      System.out.println(L2);
      
      
      System.out.println(name2+".mul("+name2+")");
      Matrix M = B.mult(B);
      System.out.println("number of none zero element: "+M.getNNZ());
      System.out.println(M);
      

      //Test for changeEntry replace element function
      System.out.println("Test for changeEntry replace element function:"+name1+".changeEntry(3,2,1):");
      A.changeEntry(3,2,1);
      System.out.println("number of non zero elements: "+A.getNNZ());
      System.out.println(A);
      
      //Test for changeEntry delete element function
      System.out.println("Test for changeEntry delete element function:"+name1+".changeEntry(3,2,0):");
      A.changeEntry(3,2,0);
      System.out.println("number of non zero elements: "+A.getNNZ());
      System.out.println(A);
      
      //Test for wrong input 
      System.out.println("Test for wrong input (1):"+name1+".changeEntry(0,0,0):");
       A.changeEntry(0,0,0);
      System.out.println("number of non zero elements: "+A.getNNZ());
      System.out.println(A);
      
      System.out.println("Test for wrong input (2):"+name1+".changeEntry(0,0,1)");
      A.changeEntry(0,0,1);
      System.out.println("number of non zero elements: "+A.getNNZ());
      System.out.println(A);
      
      
      System.out.println("Test for "+name1+".copy():");
      Matrix N = A.copy();
      System.out.println("print A.copy()");
      System.out.println("number of none zero element: "+N.getNNZ());
      System.out.println(N);
      
      System.out.println("Test for equals method:");
      System.out.println("is "+name1+" equal to "+name1+"'s copy?:");
      System.out.println(A.equals(N));
      System.out.println("is "+name1+" equal to "+name2+"?:");
      System.out.println(A.equals(B));
      System.out.println("is "+name1+" equal to "+name1+"?:");
      System.out.println(A.equals(A));

      System.out.println("test for makeZero method for matrix"+name1+":");
      A.makeZero();
      System.out.println("number of none zero element: "+A.getNNZ());
      System.out.println(A);  
       }
}
