#include<stdio.h>
#include<conio.h>
#define size 5
int front = -1 , rear = -1 , cir[size];
void enqueue()
{
	int ele;
	printf("Enter an element\n");
	scanf("%d",&ele);
	if(front == size-1)
	{
		printf("Circular Queue Overflow\n");
	}
	else
	{
		if(front == -1 && rear == -1)
		{
			front = rear = 0;
			cir[rear]=ele;
		}
		else
		{
			rear = (rear + 1)%size;
			cir[rear]=ele;
		}
	}
}
void dequeue()
{
	if(front == -1)
	{
	printf("Circular Queue Underflow\n");
	}
	printf("Element Deleted : %d\n",cir[front]);
	if(front == rear)
	{
	front = -1,rear = -1;
	}
	else if(front==size-1)
	{
	front=0;
	}
	else
	front ++;


}
void display()
{
	int i;
	if(front < rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",cir[i]);
		}
	}
	else
	{
		for(i=front;i <= size;i++)
		{
			printf("%d ",cir[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d ",cir[i]);
		}
	}
	printf("\n");
}
void main()
{
	int c;
	clrscr();
	printf("1.Insert 2.Delete 3.Display 4.EXIT\n");
	do
	{
		printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : enqueue();break;
			case 2 : dequeue();break;
			case 3 : display();break;
			case 4 : printf("GOODBYE");
		}
	}while(c != 4);
getch();
}
