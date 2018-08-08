#include<stdio.h>
#include<conio.h>
#define max 5
int arr[max],front=-1,rear=-1;
void enqueue()
{
int ele,i,j,temp;
printf("enter the element");
scanf("%d",&ele);
if(rear==max-1 && front==0)
printf("overflow");
else
{
 if(front==-1)
 {front=0;rear=0;}
 else
 rear++;
 arr[rear]=ele;
}
for(i=front;i<=rear;i++)
{
 for(j=front;j<=rear;j++)
 {
  if(arr[i]<arr[j])
  {
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   }
 }
}
}
void dequeue()
{
int i,j,temp;
for(i=front;i<=rear;i++)
{
 for(j=front;j<=rear;j++)
 {
  if(arr[i]<arr[j])
  {
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   }
 }
}
if(front==-1)
printf("underflow");
else
{
 printf("deleted = %d",arr[front]);
 if(front==rear)
 {front=-1;rear=-1;}
 else
 {
 front++;
 }
}
}
void display()
{
int i;
for(i=front;i<=rear;i++)
{
printf("%d,",arr[i]);
}
}
void main()
{
int i;
clrscr();
printf("1)enter\n2) delete\n3)display\n4)exit\n");
do
{
printf("\nenter the number");
scanf("%d",&i);
switch(i)
{
case 1: enqueue(); break;
case 2: dequeue(); break;
case 3: display(); break;

}
}while(i<=3);
getch();
}