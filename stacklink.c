#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* link;
};
struct Node* top ;
void push(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=top;
    top=temp;
}
void pop(){
    struct Node *temp;

    temp = top;
    top = top->link;
    free(temp);
}
void Print()
{
    struct Node* temp ;
    temp = top;
    printf("list is:");
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp= temp->link;
    }
    printf("\n");
}
int main()
{
    top=NULL;
    push(5);
    push(4);
    push(3);
    push(2);
    pop();
    pop();
    Print();

}
