#include<xmtc.h>       /*MERGE SORT*/
int main()
{
   int A[8]={9,3,7,6,4,5,2,1},s=0,j;
    int B[8],C[8],N=8,Z,x,d,c=0,y,k,a;
   Z=N;
   while(Z>=2)
   { 
      if(Z%2==0) a=0; else {a=1;c=1;}
      Z=Z/2;
      s=s+1; 
   }
   if (c==1) s=s+1;  
   printf("s=%d",s);   // number of steps

   for(x=1;x<=s;x++)
   {  
      int i=1,c1[10],c2[10];
                  for( int l=1;l<=x;l++)
                  i=i*2;
      if(N%2==0) d=(N/i)-1;
      else d=N/i;       // d=no. of threads in each step
      printf("\nArray:\n");
      for(y=0;y<N;y++)
      printf("%d\t",A[y]);
      spawn(0,d)  
       {   c1[$]=0;c2[$]=0;
         for(int j=0;j<(i-1);j++)   // no. of comparisions in each thread
         { 
           if ((A[i*$]<=A[i*$+(i/2)]))
           { 
             B[i*$+j]=A[i*$];
             c1[$]++;
             for(k=1;k<(i/2);k++)
             A[i*$+k-1]=A[i*$+k];
             if(j==(i-2)) B[i*$+j+1]=A[i*$+(i/2)];
           }
           else
           {
             B[i*$+j]=A[i*$+(i/2)];
             c2[$]++;
             for(k=1;k<(i/2);k++)
             A[i*$+(i/2)+k-1]=A[i*$+(i/2)+k];
             if(j==(i-2)) B[i*$+j+1]=A[i*$];
           }
           if((c1[$]==(i/2))||(c2[$]==(i/2)))    //out of for-loop
           break;
         }
	}
      spawn(0,d)  {
	
           if(c1[$]==(i/2))
           {  
             for(k=0+c2[$];k<(i-(i/2));k++)
               B[i*$+(i/2)+k]=A[i*$+(i/2)+k];
           }
           if(c2[$]==(i/2))
           {  
             for(k=0+c1[$];k<(i-(i/2));k++)
               B[i*$+(i/2)+k]=A[i*$+k];
           }
         
         
       }
       
    
      
     for(y=0;y<N;y++)
     { A[y]=B[y];
     }
    }
    printf("\nSorted list:\n");
    for(y=0;y<N;y++)
     printf("%d\t",A[y]);
    printf("\n");
    return 0;
}
