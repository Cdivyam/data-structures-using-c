#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *end =NULL;
void Create();
void Display();
void InsertBefore();
void InsertAfter();
void InsertAtPosition();
void DeleteElement();
void DeleteAtPosition();
void main()
{
    int n;
    do
    {
        printf("\n\n******MENU******");
        printf("\n1 : Create Linked List");
        printf("\n2 : Insert Before");
        printf("\n3 : Insert After");
        printf("\n4 : Insert At Position");
        printf("\n5 : Delete Element");
        printf("\n6 : Delete At Position");
        printf("\n7 : Display");
        printf("\n8 : Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&n);

        switch(n)
        {
            case 1 : Create();
                     break;
            case 2 : InsertBefore();
                     break;
            case 3 : InsertAfter();
                     break;
            case 4 : InsertAtPosition();
                     break;
            case 5 : DeleteElement();
                     break;
            case 6 : DeleteAtPosition();
                     break;
            case 7 : Display();
                     break;
            case 8 : printf("\nExiting.....");
                     break;
            default : printf("\nInvalid Input...");
        }
    }
    while(n!=8);

}
void Create()
{
    char ch;
    struct node *temp;
    do
    {
        temp = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data : ");
        scanf("%d",&temp->data);

        if(start == NULL)
        {
            start=temp;
        }
        else
        {
            end->next=temp;
        }
        end=temp;
        temp->next=start;

        count++;
        printf("\nDO you want to add more?? Y/N");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}

void InsertBefore()
{
    if(count==0)
    {
        printf("\nCreate linked list first....");
        return;
    }
    struct node *ptr;
    ptr=start;

    int n,flag=0;
    printf("\nEnter Element Before which you want to Insert Data : ");
    scanf("%d",&n);

    if(ptr->data==n)
    {
        struct node *temp;
        temp= (struct node * )malloc(sizeof(struct node));

        printf("\nEnter data : ");
        scanf("%d",&temp->data);

        temp->next=start;
        start= temp;
        end->next=start;
        count++;
        flag++;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            if(ptr->next->data==n)
            {
                struct node *temp;
                temp= (struct node * )malloc(sizeof(struct node));

                printf("\nEnter data : ");
                scanf("%d",&temp->data);

                temp->next=ptr->next;
                ptr->next=temp;
                count++;
                flag++;
                break;
            }
            ptr=ptr->next;

        }
    }

    if(flag==0)
    {
        printf("\nNumber Not Found.....");
    }

}
void InsertAfter()
{
    if(count==0)
    {
        printf("\nCreate linked list first....");
        return;
    }
    struct node *ptr;
    ptr=start;

    int n,flag=0;
    printf("\nEnter Element After which you want to Insert Data : ");
    scanf("%d",&n);

    while(ptr!=NULL)
    {
        if(ptr->data==n)
        {
            struct node *temp;
            temp= (struct node * )malloc(sizeof(struct node));

            printf("\nEnter data : ");
            scanf("%d",&temp->data);

            temp->next=ptr->next;
            ptr->next=temp;
            if(ptr==end)
            {
                end= temp;
            }
            count++;
            flag++;
            break;
        }
        ptr=ptr->next;

    }
}

void InsertAtPosition()
{
    if(count==0)
    {
        printf("\nCreate linked list first....");
        return;
    }
    struct node *ptr=NULL;
    int i,n;

    printf("\nEnter position At Which you Want to Insert Data : ");
    scanf("%d",&n);


    if(n>count)
    {
        printf("Invalid Choice.....");
        return;
    }

    if(n==1)
    {
        struct node *temp;
        temp= (struct node * )malloc(sizeof(struct node));

        printf("\nEnter data : ");
        scanf("%d",&temp->data);

        temp->next=start;
        start= temp;
        end->next=start;
        count++;
        return;
    }

    for(i=1;i<n;i++)
    {
        if(ptr==NULL)
        {
            ptr=start;
        }
        else
        {
            ptr= ptr->next;
        }
    }

    struct node *temp;
    temp= (struct node * )malloc(sizeof(struct node));

    printf("\nEnter data : ");
    scanf("%d",&temp->data);

    temp->next=ptr->next;
    ptr->next=temp;
    count++;
}
void DeleteElement()
{
    if(count==0)
    {
        printf("\nLinked List is Empty....");
        return;
    }
    int n,flag=0;
    printf("\nEnter Element that is to be Deleted : ");
    scanf("%d",&n);

    struct node *ptr1,*ptr;
    ptr1=start;

    if(ptr1->data==n)
    {
        start=start->next;
        end->next=start;
        ptr1->next=NULL;
        free(ptr1);
        count--;
        flag++;
        return;
    }

    ptr1=ptr1->next;
    ptr=start;

    while(ptr1!=NULL)
    {
        if(ptr1->data==n)
        {
            ptr->next=ptr1->next;
            if(ptr1==end)
            {
                end=ptr;
            }
            free(ptr1);
            count--;
            flag++;
            break;

        }
        ptr1=ptr1->next;
        ptr=ptr->next;
    }

    if(flag==0)
    {
        printf("\nInvalid Input....");
    }
}
void DeleteAtPosition()
{
if(count==0)
    {
        printf("\nLinked List is Empty....");
        return;
    }

    int n,i;
    printf("\nEnter Position of element that is to be Deleted : ");
    scanf("%d",&n);
    if(n>count)
    {
        printf("\nInvalid input....");
        return;
    }
    struct node *ptr1,*ptr=NULL;
    ptr1=start;

    if(n==1)
    {
        start=start->next;
        end->next=start;
        ptr1->next=NULL;
        free(ptr1);
        count--;
        return;
    }

    for(i=1;i<n;i++)
    {
        if(ptr==NULL)
        {
            ptr=start;
        }
        else
        {
            ptr= ptr->next;
        }
        ptr1=ptr1->next;
    }

    ptr->next=ptr1->next;
    if(ptr1==end)
    {
        end=ptr;
    }
    free(ptr1);
    count--;
}


void Display()
{
    if(count==0)
    {
        printf("\nLinked List Is Empty....");
        return;
    }
    printf("\n");
    struct node *ptr;
    ptr= start;
    while(ptr!=end)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}

