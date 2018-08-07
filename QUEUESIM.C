#include<stdio.h>
#include<conio.h>
# define size 5
int arr[size];
int front=-1,rear=-1;
void insert()
{
 int n;
 printf("enter the number to be inserted in the queue");
 scanf("%d",&n);
 if(rear==size-1)
 printf("\noverflow");
 else if(front==-1 && rear==-1)
 front=0,rear=0;
 else
 rear++;
 arr[rear]=n;
}
void delte()
{
 if(front == -1 || front>rear)
 printf("\nunderflow");
 else
 {
  printf("\nthe deleted element is %d",arr[front]);
  front++;
  if(front>rear)
  front=-1,rear=-1;
 }
}
void display()
{
int i;
if(front == -1 || front>rear)
printf("\nqueue is empty");
else
{
 for(i=0;i<=rear;i++)
 printf("%d,",arr[i]);
}
}
void main()
{
 int opt;
 do
 {
  printf("1)insert\n 2)delete\n 3)display\n 4)exit\n");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:insert(); break;
   case 2:delte(); break;
   case 3:display(); break;
  }
 }while(opt<=3);
 getch();
}