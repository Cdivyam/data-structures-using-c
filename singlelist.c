#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* head;
void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Insertt(int dat, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = dat;
    temp1->next = NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
        }
    struct Node* temp2 = head;
    for(int i=0; i<n-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Print()
{
    struct Node* temp ;
    temp = head;
    printf("list is:");
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp= temp->next;
    }
    printf("\n");
}
void delte(int n){
    int i;
    struct Node* temp1 = head;

    if(n == 1){
        head =temp1->next;
        free(temp1);
        return;
        }
    for(i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
void searchh(int n){
    struct Node* temp3 = head;
    int i=1;
    if(head == NULL){
        printf("linked list is empty");
        return;
    }
    while(temp3!=NULL){
        if((temp3->data)==n){

            printf("element found at %d position",i++);
            break;
        }
        else{
            temp3=temp3->next;
        }
        i++;
    }

}
int main()
 {
     head = NULL;
     printf("how many numbers?\n");
     int n,i,x,a,x1,s;
     scanf("%d",&n);
     for(i=0;i<n;i++){
        printf("enter the number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
     }
     printf("\n************delete a list at nth position****************\n");
     printf("enter the position you want to get deleted\n ");
     scanf("%d",&x1);
     delte(x1);
     Print();
     printf("\n************insert a list at nth position****************");
     printf("\nhow much elements do you want to insert?");
     scanf("%d",&n);
     for(i=0;i<n;i++){

      printf("\nenter the element");
      scanf("%d",&x1);
      printf("\nenter the position");
      scanf("%d",&a);
      Insertt(x1,a);
      Print();
     }
     printf("now search an element\n enter the element to be searched");
     scanf("%d",&s);
     searchh(s);
     printf("closes");
 }
