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
void main()
{
    int i=0;
    int A[]={2,7,4,1,5,3};
    select(A,6);
    for (i=0;i<6;i++)
    {
        printf("%d",A[i]);
    }
    getch();
}
