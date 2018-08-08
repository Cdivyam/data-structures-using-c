#include<stdio.h>
#include<conio.h>
# define SIZE 5
int arr[SIZE],front=-1,rear=-1;
struct prior
{
int data;
int priority;
}s[SIZE];
void enqueue()
{
int i,j,k=0;
printf("enter the element\n");
scanf("%d",&s[k].data);
printf("enter the priority\n");
scanf("%d",&s[k].priority);
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
	  arr[rear]=s[k].data;
	}

}
void dequeue()
{
if(front==-1)
{
printf("underflow");
}
else
{
printf("deleted=%d",arr[front]);
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
int i,j,temp;
for(i=front;i<=rear;i++)
{
for(j=front+1;j<=rear;j++)
{
if(s[i].priority>s[j].priority)
{
 temp=arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
}
}
}

	printf("the priority queue is\n");
	for(i=front;i<=rear;i++)
	 {
	    printf("%d ",arr[i]);
	 }
}
void main()
{
	int ch;
	clrscr();
	do
	 {
	   printf("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
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
