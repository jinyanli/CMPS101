//-----------------------------------------------------------------------------
// Jinyan Li CMPS101 pa3
//Matrix.java 
//This class will contain a private
//inner class (similar to Node in your List ADT) that encapsulates the column and value information
//corresponding to a matrix entry.
//  A test client for the Matrix ADT
//-----------------------------------------------------------------------------
import java.lang.Double;
import java.lang.Integer;
class Matrix {
    private int matrixSize;

    //private inner class
    private class Entry{
          int col;
          double data;
          double scaler=1;
         Entry(int col,double data) { 
      	      this.col=col;
              this.data=scaler*data;              
      }
         //return colum number
         public int getCol(){
             return col;
         }
         //return data
         public double getData(){
             return data;
         }     
         
        public boolean equals(Object X){
            Entry E=(Entry)X;
            if(this.data==E.data&&this.col==E.col){
                return true;
            }else{
            return false;
            }
        }
         public String toString(){
             return "("+String.valueOf(col)+", "+String.valueOf(data)+")";
    }    
  }
    
    //private Entry newEntry;
    private int NNZ=0; 
    List[] row;
    List<Entry> A=new List<>();
    int rowCount=1;
    int max;
    
    //// Makes a new n x n zero Matrix. pre: n>=1
    Matrix(int matrixSize) {
        if(matrixSize>=1){
        this.matrixSize=matrixSize;
    row=new List[matrixSize+1];
    }else{
            System.out.println("Error:matrixSize isn't greater than 1");
        }
        
    
   }
    
// changes ith row, jth column of this Matrix to x
// pre: 1<=i<=getSize(), 1<=j<=getSize()
    void changeEntry(int i,int j, double x){     
        if(1<=i&&i<=getSize()&&1<=j&&j<=getSize()){
              if(rowCount!=i){
                  if(rowCount<=i){
                  rowCount=i;
                  }
                //if(row[i]==null)
                  A=new List<>();
              }

              if(x!=0){
                  Entry newEntry=new Entry(j,x);
                       if(row[i]==null){
                         A.append(newEntry);
                         row[i]=A;
                         NNZ++;
                      }else{
                           for(row[i].moveTo(0);row[i].getIndex()>=0;row[i].moveNext()){
                               Entry temp=(Entry) row[i].getElement();
                               if(newEntry.col<temp.col){
                                  row[i].insertBefore(newEntry);
                                  NNZ++;
                                  break;
                               }
                               if(newEntry.col==temp.col){
                                  temp.data=x;
                                  break;
                               }
                               if(row[i].getIndex()==row[i].length()-1){
                                   row[i].append(newEntry);
                                   NNZ++;
                                   break;
                               }
                           }
                      }
                  
              }else if(x==0){
                  //Entry newEntry=new Entry(j,x);
                  if(row[i]!=null){
                  for(row[i].moveTo(0);row[i].getIndex()>=0;row[i].moveNext()){
                           Entry temp=(Entry) row[i].getElement();
                           if(j==temp.col){
                              row[i].delete();
                              NNZ--;
                              break;
                           } 
                       }
                  
                  }
              }
        }else{
            System.out.println("ERROR: changeEntry() i and j can't be less than 1");
        }
        
    }
    
    // Returns n, the number of rows and columns of this Matrix
    int getSize(){
     return matrixSize;   
    }
    
    // Returns the number of non-zero entries in this Matrix
    int getNNZ(){
        return NNZ;
    }
 
    // sets this Matrix to the zero state
    void makeZero(){

        NNZ=0;
        Entry newEntry;
  
        for(int i=1;i<=rowCount;i++){
          this.row[i]=null;
        }  
    }
   
   // returns a new Matrix having the same entries as this Matrix
    Matrix copy(){
      Matrix newMatrix=new Matrix(matrixSize);
      Entry newEntry;
  
        for(int i=1;i<=rowCount;i++){
           if(this.row[i]!=null){
            
           for(this.row[i].moveTo(0);this.row[i].getIndex()>=0;this.row[i].moveNext()){
              newEntry=(Entry) this.row[i].getElement();
              newMatrix.changeEntry(i, newEntry.col, newEntry.data);                          
              }
           }
        }  
      return newMatrix;
  }
 
    // returns a new Matrix that is the scalar product of this Matrix with x
    Matrix scalarMult(double x){
  
        Matrix NewMatrix=new Matrix(matrixSize);
        Entry newEntry;
  
        for(int i=1;i<=rowCount;i++){
           if(this.row[i]!=null){
            this.row[i].moveTo(0);
           for(this.row[i].moveTo(0);this.row[i].getIndex()>=0;this.row[i].moveNext()/*int j=0;j<rowCount;j++*/){
               newEntry=(Entry) this.row[i].getElement();
               NewMatrix.changeEntry(i, newEntry.col, newEntry.data*x);   
               //this.row[i].moveNext();
            }
           }
        }  
        return NewMatrix;
    }

 // returns a new Matrix that is the sum of this Matrix with M
// pre: getSize()==M.getSize()
    Matrix add(Matrix M){
    if(this.getSize()!=M.getSize()){
        System.out.println("Not the same size");
        return null; 
    }
        
     Matrix NewMatrix=new Matrix(matrixSize);  
      if(this==M){
        NewMatrix=this.scalarMult(2);
          return NewMatrix;
    }
    
    Entry A;
    Entry B;
    
    if(this.rowCount!=M.rowCount){
        if(this.rowCount<M.rowCount){
            rowCount=M.rowCount;    
        }else{
            rowCount=this.rowCount;  
        }
    }
    
    for(int i=1;i<=rowCount;i++){
        if(this.row[i]!=null&&M.row[i]!=null){
           this.row[i].moveTo(0);
           M.row[i].moveTo(0);           
            while(M.row[i].getIndex()>=0||this.row[i].getIndex()>=0){
                 A=(Entry)this.row[i].getElement();
                 B=(Entry)M.row[i].getElement(); 
                 if(B!=null&&A!=null){
                        if(B.col==A.col){
                          NewMatrix.changeEntry(i, A.col, A.data+B.data); 
                          this.row[i].moveNext();
                          M.row[i].moveNext();
                     }else if(A.col>B.col){
                         NewMatrix.changeEntry(i, B.col, B.data);
                         M.row[i].moveNext();
                     }else{
                         NewMatrix.changeEntry(i, A.col, A.data);
                        this.row[i].moveNext();
                      } 
                }else if(B==null){
                     NewMatrix.changeEntry(i, A.col, A.data);
                  this.row[i].moveNext();
                }else if(A==null){
                     NewMatrix.changeEntry(i, B.col, B.data);
                     M.row[i].moveNext();
                }
           }
        }else if(this.row[i]!=null&&M.row[i]==null){
            for(this.row[i].moveTo(0);this.row[i].getIndex()>=0;this.row[i].moveNext()){
                A=(Entry) this.row[i].getElement();
                      NewMatrix.changeEntry(i, A.col, A.data);
            }
        }else if(this.row[i]==null&&M.row[i]!=null){
            for(M.row[i].moveTo(0);M.row[i].getIndex()>=0;M.row[i].moveNext()){
                B=(Entry) M.row[i].getElement();
                      NewMatrix.changeEntry(i, B.col, B.data);
            } 
        }
  }  
    return NewMatrix;
}
 
// returns a new Matrix that is the difference of this Matrix with M
// pre: getSize()==M.getSize()
 Matrix sub(Matrix M){
    if(this.getSize()!=M.getSize()){
        System.out.println("Not the same size");
        return null; 
    }
    if(this==M){
       Matrix NewMatrix=new Matrix(matrixSize);
       NewMatrix=M.copy();
       NewMatrix.makeZero();
       return NewMatrix;
    }
    Matrix NewMatrix=new Matrix(matrixSize);  
    Entry A;
    Entry B;
     if(this.rowCount!=M.rowCount){
        if(this.rowCount<M.rowCount){
            rowCount=M.rowCount;    
        }else{
            rowCount=this.rowCount;  
        }
    }
    
    for(int i=1;i<=rowCount;i++){
        if(this.row[i]!=null&&M.row[i]!=null){
           this.row[i].moveTo(0);
           M.row[i].moveTo(0);           
            while(M.row[i].getIndex()>=0||this.row[i].getIndex()>=0){
                 A=(Entry)this.row[i].getElement();
                 B=(Entry)M.row[i].getElement(); 
                   if(B!=null&&A!=null){
                 if(B.col==A.col){
                      NewMatrix.changeEntry(i, A.col, A.data-B.data); 
                      this.row[i].moveNext();
                      M.row[i].moveNext();
                 }else if(A.col>B.col){
                     NewMatrix.changeEntry(i, B.col, 0-B.data);
                     M.row[i].moveNext();
                 }else{
                     NewMatrix.changeEntry(i, A.col, A.data-0);
                    this.row[i].moveNext();
                 }
                }else if(B==null){
                     NewMatrix.changeEntry(i, A.col, A.data-0);
                  this.row[i].moveNext();
                }else if(A==null){
                     NewMatrix.changeEntry(i, B.col, 0-B.data);
                     M.row[i].moveNext();
                }
             }
        }else if(this.row[i]!=null&&M.row[i]==null){
            for(this.row[i].moveTo(0);this.row[i].getIndex()>=0;this.row[i].moveNext()){
                A=(Entry) this.row[i].getElement();
                      NewMatrix.changeEntry(i, A.col,A.data-0);
            }
        }else if(this.row[i]==null&&M.row[i]!=null){
            for(M.row[i].moveTo(0);M.row[i].getIndex()>=0;M.row[i].moveNext()){
                B=(Entry) M.row[i].getElement();
                      NewMatrix.changeEntry(i, B.col, 0-B.data);
            } 
        }
  }  
    return NewMatrix;
 }

//override Object equals method
 public boolean equals(Object X){
       Matrix x=(Matrix)X;
       Entry A;
       Entry B;
       if(this==x)
           return true;
       
        if(this.rowCount!=x.rowCount){
        if(this.rowCount<x.rowCount){
            rowCount=x.rowCount;    
        }else{
            rowCount=this.rowCount;  
        }
    }
       
       for(int i=1;i<=rowCount;i++){
           if(this.row[i]!=null&&x.row[i]!=null){
               this.row[i].moveTo(0);
               x.row[i].moveTo(0);  
                while(this.row[i].getIndex()>=0||x.row[i].getIndex()>=0){
                     A=(Entry)this.row[i].getElement();
                     B=(Entry)x.row[i].getElement(); 
                     if(A!=null&&B!=null){
                            
                         if(A.equals(B)){
                              this.row[i].moveNext();
                              x.row[i].moveNext();
                         }else{
                             return false;
                         }
                         
                     }else if(A==null&&B==null){                    
                     }else{
                          return false;
                      }
                     
                }
            }else if(this.row[i]==null&&x.row[i]==null){                    
            }else{
              return false;
            }
         }
       
       return true;
   }
    
 // returns a new Matrix that is the transpose of this Matrix
 Matrix transpose(){
        Matrix newMatrix=new Matrix(matrixSize);  
        Entry A;
        Entry B;
        for(int i=1;i<=rowCount;i++){
           //this.row[i].moveTo(0);
           if(this.row[i]!=null){
               
               for(this.row[i].moveTo(0);this.row[i].getIndex()>=0;this.row[i].moveNext()){
                  A=(Entry) this.row[i].getElement();
                  //B=(Entry) M.row[i].getElement();
                  newMatrix.changeEntry(A.col, i, A.data);   
                  //this.row[i].moveNext();
                  
              }
           }
           //rowCount=1;
        }
        return newMatrix;
    }   
    
// returns a new Matrix that is the product of this Matrix with M
// pre: getSize()==M.getSize()
    Matrix mult(Matrix M){
        if(this.getSize()!=M.getSize()){
        System.out.println("Not the same size");
        return null; 
        }
         Matrix newMatrix=new Matrix(matrixSize);
         Entry A;
         Entry B;
         Matrix This=new Matrix(matrixSize);
         This=this.copy();
         
         //A=(Entry)This.row[1].getElement();
         if(this==M){         
           M=M.copy();
       }      
        M=M.transpose();
      
         if(this.rowCount!=M.rowCount){
        if(this.rowCount<M.rowCount){
            rowCount=M.rowCount;    
        }else{
            rowCount=this.rowCount;  
        }
    }
        
        double sum=0;
        for(int i=1;i<=rowCount;i++){
            if(This.row[i]!=null){
            This.row[i].moveTo(0);          
            for(int j=1;j<=rowCount;j++){
                if(M.row[j]!=null){
                    M.row[j].moveTo(0);
                    while(M.row[j].getIndex()>=0&&This.row[i].getIndex()>=0){
                     A=(Entry)This.row[i].getElement();
                     B=(Entry)M.row[j].getElement(); 
                      if(B.col==A.col){
                          sum=sum+A.data*B.data;
                          This.row[i].moveNext();
                          M.row[j].moveNext();
                     }else if(A.col>B.col){
                         M.row[j].moveNext();
                     }else{
                        This.row[i].moveNext();
                      } 
                    }
                    newMatrix.changeEntry(i, j, sum);
                    sum=0;
                    This.row[i].moveTo(0);
                }
              }    
            }
        }
            
            
        return newMatrix;
    }
    
    // overrides Object's toString() method
    public String toString(){
          String str = "";
          for(int i=1;i<=rowCount;i++){
              //for(A.moveTo(0);A.getIndex()>=0;A.moveNext()){
              if(row[i]!=null){    
              str+=i+":"+row[i].toString()+" ";
              //}
              str+="\r\n";
              }
          }
          return str;
    }
}
