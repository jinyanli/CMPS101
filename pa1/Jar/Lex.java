//Author Jinyan Li, Assignment: pa1 Class CMPS101

import java.io.*;
import java.util.Scanner;
   public class Lex{
   public static void main(String[] args)throws IOException{
       Scanner in = null;
       Scanner in2 = null;
       Scanner in3 = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      int i, n, lineNumber = 0;
     
      //args = new String[2];
      
      if(args.length !=2){
         System.err.println("Usage: FileIO infile outfile");
         System.exit(1);
      }
      
      //DEBUG
      //args[0] = "C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\in2.txt";
      //args[1] = "C:\\Users\\Jinyan\\Desktop\\ucsc\\2015Winter\\CMPS101\\out1.txt";
      in = new Scanner(new File(args[0]));
      in2 = new Scanner(new File(args[0]));
      in3 = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));
      
      
      while(in2.hasNextLine()){
         lineNumber++;
       in2.nextLine();         
      }

      String[] anArray=new String[lineNumber];
      String[] anArray2=new String[lineNumber];
            
      int j=0;

      while(in3.hasNextLine()){         
         anArray[j]=in3.nextLine();
         j++;
      }
     
         anArray2=anArray.clone();

         List A = new List();   

//insertion sort
         int x=0;
          A.append(0);
	 for(int k=1;k<anArray.length;k++){
            //A.moveTo(k);              
            String temp=anArray[k];    
            for(A.moveTo(0);A.getIndex()>=0;A.moveNext()){               
                  if(A.length()==1){
                      if(anArray[A.getElement()].compareTo(temp)>0){
                      A.insertBefore(k);
                      break;
                     }else {               
                      A.insertAfter(k);
                     break;
                     }
                 }
              
            	  if(anArray[A.getElement()].compareTo(temp)>0||anArray[A.getElement()].compareTo(temp)==0){
                  A.insertBefore(k);
                  break;
                  }else if(A.getIndex()==A.length()-1){
                   A.insertAfter(k);
                  break;
                   }

          }
       }
             

        for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
            	out.println(anArray2[A.getElement()]);           	 
            }
                       
      in.close();
      out.close();    
   }
}
   

