#include<stdio.h>
#include<stdlib.h>
#define ms 10
void insert (int x);
void sort();
void removes();
void display();
    int data[ms];
    int priority[ms];
    int front,rear;
int n=0;
void main()
{
    int c,x;
    front=rear=-1;
    do
    {
        printf("\n\n*****MENU*****\n");
        printf("1.insert in the queue\n");
        printf("2.remove from queue\n");
        printf("3.display the queue\n");
        printf("Enter your choice \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the data element of the queue\n");
                scanf("%d",&x);
                insert(x);
                break;
            case 2:
                removes();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting....");break;
            default:
                printf("Invalid choice ");
        }
    }while(c!=4);
}
void insert(int x)
{
    if(abs(front-rear)==ms-1)
    {
        printf("Queue overflow \n");
        return;
    }
    else
    {
        rear=(rear+1);
        n++;
        data[rear]=x;
        printf("Enter the priority from 1 to 5 where 1 is the lowest \n");
        scanf("%d",&priority[rear]);
    }
    sort();
}
void removes()
{
    int x,p;
    if(rear==-1)
    {
        printf("Underflow...\n");
        return;
    }
    else if(front==rear)
    {
        x=data[front];
        p=priority[front];
        front=rear=-1;
        n--;
    }
    else
    {
        front=(front+1)%ms;
        p=priority[front];
        x=data[front];
        n--;
    }
    printf("the element removed is %d and the priority is %d ",x,p);
}
void sort()
{
    int temp,i,j,p;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(priority[j]<priority[j+1])
            {
                temp=data[j+1];
                data[j+1]=data[j];
                data[j]=temp;
                p=priority[j+1];
                priority[j+1]=priority[j];
                priority[j]=p;
            }
        }
    }
}
void display()
{
    int i;
    if (front>rear)
    {
        for(i=front;i<ms;i++)
            printf("%d and priority %d\n",data[i],priority[i]);
        for(i=0;i<rear;i++)
            printf("%d and priority %d\n",data[i],priority[i]);
    }
    else if(front<rear)
    {
        for(i=front;i<=rear;i++)
        printf("%d and priority %d\n",data[i],priority[i]);
    }
    else
        printf("%d and priority %d",data[front],priority[i]);
}
