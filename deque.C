#include<stdio.h>
#include<conio.h>
# define size 6
int arr[size];
int left=-1,right=-1;
void insert_right()
{
 int n;
 printf("enter the number to be inserted in the queue");
 scanf("%d",&n);
 if((left==0 && right==size-1) ||(left==right+1))
 printf("\noverflow");
 if(left==-1)
 {
    left=0;
    right=0;
 }
 else
 {
    if(right==size-1)
    right=0;
    else
    right++;
 }
 arr[right]=n;
}
void insert_left()
{
 int n;
 printf("enter the number to be inserted in the queue");
 scanf("%d",&n);
 if((left==0 && right==size-1) ||(left==right+1))
 printf("\noverflow");
 if(left==-1)
 {
    left=0;
    right=0;
 }
 else
 {
  if(left==0)
    left=size-1;
  else
    left--;
 }
 arr[left]=n;
}
void delete_left()
{
 if(left== -1)
    printf("\nunderflow");
 printf("\nthe deleted element is %d",arr[left]);
  if(left == right)
  {
     left=-1;
     right=-1;
  }
  else
  {
     if(left==size-1)
       left=0;
     else
       left++;
  }
}
void delete_right()
{
 if(left== -1)
 printf("\nunderflow");
 printf("\nthe deleted element is %d",arr[right]);
  if(left == right)
  {
       left=-1;
       right=-1;
  }
  else
  {
     if(right==0)
       right=size-1;
     else
       right--;
  }
}
void display()
{
int front=left,rear=right;
if(front == -1)
printf("\nqueue is empty");
printf("\nthe elements are");
if(front<=rear)
{
   while(front<=rear)
   {
      printf("%d ",arr[front]);
      front++;
   }
}
else
{
   while(front<=size-1)
   {
      printf("%d",arr[front]);
      front++;
   }
   front=0;
   while(front<=rear)
   {
      printf("%d",arr[front]);
   }
}
printf("\n");
}
void input_deque()
{
int opt;
do
{
  printf("\ninput inserted deque");
  printf("\n1)insert at right");
  printf("\n2)delete fromr left");
  printf("\n3)delete from right");
  printf("\n4)display");
  printf("\n5)exit");
  printf("\nenter option");
  scanf("%d",&opt);
  switch(opt)
  {
     case 1:insert_right(); break;
     case 2:delete_left();  break;
     case 3:delete_right(); break;
     case 4:display();      break;
  }
}while(opt!=5);
}
void output_deque()
{
int opt;
do
{
  printf("\noutput inserted deque");
  printf("\n1)insert at right");
  printf("\n2)insert at left");
  printf("\n3)delete from left");
  printf("\n4)display");
  printf("\n5)exit");
  printf("\nenter option");
  scanf("%d",&opt);
  switch(opt)
  {
     case 1:insert_right(); break;
     case 2:insert_left();  break;
     case 3:delete_left(); break;
     case 4:display();      break;
  }
}while(opt!=5);
}
void main()
{
 int opt;
 clrscr();
 printf("\n1)input restricted queue");
 printf("\n2)output restricted queue");
 printf("\nenter your option");
 scanf("%d",&opt);
 switch(opt)
 {
  case 1:input_deque();break;
  case 2:output_deque();break;
 }
 getch();
}