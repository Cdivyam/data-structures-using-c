#include<stdio.h>
#include<conio.h>
void select(int A[],int n)
{
    int i,imin,j,temp;
    for( i=0;i<n-1;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[imin])
            {
                imin=j;
            }
            temp=A[i];
            A[i]=A[imin];
            A[imin]=temp;
        }
    }
}
void bubble(int A[],int n)
{
    int k,i,temp;
    for(k=1;k<=n-1;k++)
    {
        for(i=0;i<n-1;i++)
        {
            if(A[i]>A[i+1])
            {
               temp=A[i];
               A[i]=A[i+1];
               A[i+1]=temp;

            }
        }
    }
    for (i=0;i<6;i++)
    {
        printf("%d",A[i]);
    }
}
void main()
{
    int i=0;
    int A[]={5,6,4,7,3,2};
    select(A,6);
    for (i=0;i<6;i++)
   {
       printf("%d",A[i]);
   }
   printf("\n");
    bubble(A,6);

    getch();
}
