//Author Jinyan Li, Class CMPS101 pa3
//input two matrices from file and do arithmetic operations

import java.io.*;
import java.util.Scanner;
   public class Sparse{
   public static void main(String[] args)throws IOException{
      Scanner in = null;
      Scanner in2 = null;
      Scanner in3 = null;
      PrintWriter out = null;
      String line = null;
      //String[] token = null;
      int lineNumber = 0;
     
      //DEBUG
      //args = new String[2];
      
      if(args.length !=2){
         System.err.println("Usage: FileIO infile outfile");
         System.exit(1);
      }
      
      //DEBUG
      //args[0] = "C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\pa3\\in3.txt";
      //args[1] = "C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\pa3\\outpa3 3.txt";
      in = new Scanner(new File(args[0]));
      in2 = new Scanner(new File(args[0]));
      in3 = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));
      
      
      while(in2.hasNextLine()){
         lineNumber++;
       in2.nextLine(); 
      }

      String[] anArray=new String[lineNumber];
     // String[] anArray2=new String[lineNumber];
            
      int j=0;

      while(in3.hasNextLine()){         
         anArray[j]=in3.nextLine();
         j++;
      }
     
     int row,col,i,matrixSize,ASize,BSize;
     double data;
     String[] str=new String[3];
     
     //read the first line
     str=anArray[0].split(" ", 3);
     matrixSize=Integer.parseInt(str[0]);
     ASize=Integer.parseInt(str[1]);
     BSize=Integer.parseInt(str[2]);
     Matrix A = new Matrix(matrixSize);
     Matrix B = new Matrix(matrixSize);
      
     //read matrix1 from file
      for(i=2;i<ASize+2;i++){
          str=anArray[i].split(" ", 3);
          row=Integer.parseInt(str[0]);
          col=Integer.parseInt(str[1]);
          data=Double.parseDouble(str[2]);
          A.changeEntry(row, col, data);
      }
      
      //read matrix2 from file
      for(i=ASize+3;i<BSize+3+ASize;i++){
          str=anArray[i].split(" ", 3);
          row=Integer.parseInt(str[0]);
          col=Integer.parseInt(str[1]);
          data=Double.parseDouble(str[2]);
          B.changeEntry(row, col, data);
      }
      
      //do arithmetic operations
      out.println("A has "+A.getNNZ()+" non-zero entries:");
      out.println(A);

      out.println("B has "+B.getNNZ()+" non-zero entries:");
      out.println(B);
      
      out.println("(1.5)*A =");
      Matrix C = A.scalarMult(1.5);
      out.println(C);
      
      out.println("A+B =");
      Matrix D = A.add(B);
      out.println(D);
      
      out.println("A+A =");
      Matrix E = A.add(A);
      out.println(E);
      
      out.println("B-A =");
      Matrix F = B.sub(A);
      out.println(F);
      
      out.println("A-A =");
      Matrix G = A.sub(A);
      out.println(G);
      
      out.println("Transpose(A)=");
      Matrix H = A.transpose();
      out.println(H);

      out.println("A*B=");
      Matrix I = A.mult(B);
      out.println(I);
      
      out.println("B*B");
      Matrix J = B.mult(B);
      out.println(J);

  

      in.close();
      in2.close();
      in3.close();
      out.close();
     
   }
}
   
