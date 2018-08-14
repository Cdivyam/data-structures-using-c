#include<stdio.h>
#include<conio.h>
# define SIZE 5
int front=-1,rear=-1;
struct prior
{
 int data;
 int priority;
}s[SIZE];
void enqueue()
{
 int i,data,pri;
 printf("enter the element\n");
 scanf("%d",&data);

 printf("enter the priority\n");
 scanf("%d",&pri);
 if(rear==SIZE-1)
 {
	printf("overflow");
 }
 else
 {
	if(rear==-1)
	{
		rear=0;
		front=0;
	}
 else
	{
	  rear++;
	}
	  s[rear].data=data;
	  s[rear].priority=pri;
	}
 }
void dequeue()
{
 int i,j;struct prior temp;
   for(i=front;i<=rear;i++)
   {
     for(j=front+1;j<=rear;j++)
   {
   if(s[i].priority<s[j].priority)
   {
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
   }
  }
}
  if(front==-1)
  {
  printf("underflow");
  }
  else
 {
  printf("\n deleted=%d ",s[front].data);
 }
 if(front==rear)
 {
   front=-1;
   rear=-1;
 }
 else
 {
   front++;
 }
 }
void display()
{
 int i,j;struct prior temp;
   for(i=front;i<=rear;i++)
   {
     for(j=front+1;j<=rear;j++)
   {
   if(s[i].priority<s[j].priority)
   {
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
   }
  }
}

	printf("the priority queue is\n");
	for(i=front;i<=rear;i++)
	 {
	    printf(" \t %d ",s[i].data);
	 }
}
void main()
{
	int ch;
	clrscr();
	 printf("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
	do
	 {
	  // printf("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
	   printf("enter your choice\n");
	   scanf("%d",&ch);
	 switch(ch)
	 {
	   case 1:enqueue();
	   break;
	   case 2:dequeue();
	   break;
	   case 3:display();
	   break;
	   case 4:printf("exit");
	   break;
	 }
	 }
	 while(ch<=3);

	getch();
}
