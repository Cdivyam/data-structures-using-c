#include<conio.h>
#include<stdio.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
	{printf("\n Underflow");return '\0'; }
    else
	return stack[top--];
}

int priority(char x)
{
    if(x == '('|| x==')')
	return 0;
    if(x == '+' || x == '-')
	return 1;
    if(x == '*' || x == '/')
	return 2;
return 0;
}

main()
{
    char exp[20];
    char x;int i=0;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    
    while(exp[i]!= '\0')
    {
	if(exp[i]>='a'&& exp[i]<='z'||exp[i]>='A'&& exp[i]<='Z')
		    printf("%c",exp[i]);
	else if(exp[i] == '(')
	    push(exp[i]);
	else if(exp[i] == ')')
	{
	    while((x = pop()) != '(')
		printf("%c", x);
	}
	else
	{
	    while(priority(stack[top]) >= priority(exp[i]))
		printf("%c",pop());
	    push(exp[i]);
	}
	i++;
    }
    while(top != -1)
    {
	printf("%c",pop());
    }
getch();
}