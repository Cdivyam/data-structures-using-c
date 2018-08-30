#include<stdio.h>
#include<conio.h>
#define size 5
int arr[size],top =-1;
void push()
  {
   int ele;
   printf("enter the element to enter in stack");
   scanf("%d",&ele);
   if(top == size-1)
   {
     printf("\nstack overflow");
   }
   else
   {
     top++;
     arr[top]=ele;
   }
   printf("element added");
  }
void pop()
 {
  if(top==-1)
   printf("stack underflow");
  else
  {
    printf("the deleted element is %d",arr[top]);
    top--;
  }
 }
void display()
 {
  int i;
  if(top == -1)
  printf("stack is empty");
  else
  {
   for(i=top;i>=0;i--)
   {
     printf("\n%d",arr[i]);
   }
  }
 }
void main()
{
 int opt;
 clrscr();
 do
 {
  printf("\n1.) push");
  printf("\n2.) pop");
  printf("\n3.) display");
  printf("\n4.) exit");
  printf("\nenter your option");
  scanf("%d",&opt);
  switch(opt)
   {
    case 1: push();
	    break;
    case 2: pop();
	    break;
    case 3: display();
	    break;
   }
 }while(opt != 4);
getch();
}
