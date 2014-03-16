#include <xmtc.h>             /*String Matching*/
int main()
{  
   int c[10],b[10];
   int a[10][10],n1,n2,i,j,d,row,col,min,max,l1,l2;
   l1=6;l2=4;               //change values of l1 and l2 for different input sets(l1 and l2 are length of strings).
   row=l1+1;col=l2+1;
   d=row+col-1;
   c[0]='A';
   for(j=1;j<l1;j++)
   {  c[j]=c[j-1]+1;
      if(c[j]>90) 
      c[j]=(c[j]-90)+64;
   }
   printf("\nString1:");
   for(j=0;j<l1;j++)
   printf("%c\t",c[j]);
   b[0]='A';
   for(j=1;j<l2;j++)
   {  if(j%2==0)
      b[j]=b[j-1]+1;
      else
      b[j]=b[j-1]+2;
      if(b[j]>90) 
      b[j]=(b[j]-90)+63;
   }
   printf("\nString2:");
   for(j=0;j<l2;j++)
   printf("%c\t",b[j]);
   for(j=1;j<row;j++)
   a[j][0]=0;
   for(j=1;j<col;j++)
   a[0][j]=0;
   a[0][0]=0;
   if(row<col)
    { min=row; max=col; }
   else
    { min=col; max=row; }
   
    for(i=2;i<d;i++)
    {  
       if(i>=min)
       {
          if(i>(row-1)) n1=row-1;else n1=i;
          if((i>=max)&&(row<col)) n2=(i-max)+1;
          else
          if(row>=col) n2=(i-min)+1;
          else n2=0;
       }
       else
       { 
         n1=i;
         n2=0;
       }
     
    spawn(n2,n1)
       { if(($!=0) && ((i-$)!=0))
          {
	     int tmp1 = 0, tmp2 = 0, tmp3 = 0;
             if( c[$-1]==b[i-$-1] )
               tmp1=a[$-1][i-$-1] + 2;
             else
               tmp1=a[$-1][i-$-1] - 2;

             tmp2=a[$][i-$-1]-2;
             tmp3=a[$-1][i-$]-2;

	     if(tmp1>tmp2) {
		if(tmp1>tmp3) {
		    if (tmp1>0) {
	     	        a[$][i-$]=tmp1;
		    } else {
	     	        a[$][i-$]=0;
		    }
		} else {
		    if (tmp3>0) {
	     	        a[$][i-$]=tmp3;
		    } else {
	     	        a[$][i-$]=0;
		    }
		}
	     } else {
		if(tmp2>tmp3) {
		    if (tmp2>0) {
	     	        a[$][i-$]=tmp2;
		    } else {
	     	        a[$][i-$]=0;
		    }
		} else {
		    if (tmp3>0) {
	     	        a[$][i-$]=tmp3;
		    } else {
	     	        a[$][i-$]=0;
		    }
		}
	     }
          }
        }
    } 
    printf("\nOutput Matrix:"); 
    for(i=0;i<row;i++)
    {  printf("\n");
        for(j=0;j<col;j++)
           printf("%d\t",a[i][j]);
    }
    printf("\nCost of matching=%d\n",a[row-1][col-1]);
   return 0;	
}
