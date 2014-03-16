#include<xmtc.h>        /*Matrix Vector Multiplication*/
int main()

{  
   int A[20][50],C[50],D[20];
   int i,j,row=4,col=4,x; //change values of row and col to get different input sets.
   for(i=0;i<col;i++)
   {  
      C[i]=i+1;
      C[i]=C[i]%5;
   }
   for(i=0;i<row;i++)
   {  
      for(j=0;j<col;j++)
      {
        A[i][j]=i+1+j;
        A[i][j]=A[i][j]%10;
        if(A[i][j]%7==0)
        A[i][j]=0;
        if(A[i][j]%3==0)
        A[i][j]=0;
      } 
   }
   printf("\nSparse Matrix:");
   for(i=0;i<row;i++)
   {  printf("\n");
      for(int j=0;j<col;j++)
        printf("%d\t",A[i][j]);
   }
   printf("\nDense Vector:");
   for(i=0;i<col;i++)
   printf("\n%d",C[i]);
  
   spawn(0,row-1)
    {
	int tempcounter;
        for(tempcounter=0;tempcounter<col;tempcounter++)
          { 
            D[$]+=C[tempcounter]*A[$][tempcounter];
          }  
    }
   printf("\nOutput\n");
   for(i=0;i<row;i++)
   {  
        printf("%d\n",D[i]);
   }
  return 0;
}
