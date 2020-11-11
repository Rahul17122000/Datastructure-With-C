//For concatenation of two linked list.
//Create first linked list and display
//create second linked list and display
//Concatenation of the two created linked list and finally display it.
#include<stdio.h>
#include<stdlib.h>
struct node *create(struct node *,int);
void display(struct node *);
struct node *concatenation(struct node *,struct node *);
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int n1,val1,n2,val2;//,choice;
    struct node *start1=NULL,*start2=NULL,*start3;
    //printf("1.CREATE FIRST LINKED LIST");
    //printf("2.CREATE SECOND LINKED LIST");
    while(1)
    {
        printf("Enter the no of elements in the first linked list: ");
        scanf("%d",&n1);
        for(int i=1;i<=n1;i++)
        {
            printf("VAL%d: ",i);
            scanf("%d",&val1);
            start1=create(start1,val1);
        }
        printf("\nElements in the first linked list are: ");
        display(start1);
        printf("\nEnter the no of elements in the second linked list: ");
        scanf("%d",&n2);
        for(int i=1;i<=n2;i++)
        {
            printf("VAL%d: ",i);
            scanf("%d",&val2);
            start2=create(start2,val2);
        }
        printf("\nElements in the second linked list are: ");
        display(start2);
        start3=concatenation(start1,start2);
        printf("\nAFTER CONCATENATION OF TWO CREATED LINKED LIST: ");
        display(start3);
    }
    return 0;
}
struct node *create(struct node *ptr,int val)
{
    struct node *q,*temp;
    temp = malloc(sizeof(struct node));
    temp->data=val;
    if(ptr==NULL)
    {
        ptr=temp;
        temp->next=NULL;
        return ptr;
    }
    else
    {
        q=ptr;
        while(q->next!=NULL)
            q=q->next;
        temp->next=q->next;
        q->next=temp;
        return ptr;
    }
}
void display(struct node *ptr)
{
    struct node *q;
    if(ptr==NULL)
    {
        printf("LIST IS EMPTY.");
        return;
    }
    q=ptr;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    return;
}
struct node *concatenation(struct node *ptr1,struct node *ptr2)
{
    struct node *q;
    if(ptr1==NULL)
    {
        ptr1=ptr2;
        return ptr1;
    }
    if(ptr2==NULL)
        return ptr1;
    q=ptr1;
    while(q->next!=NULL)
        q=q->next;
    q->next=ptr2;
    return ptr1;
}
