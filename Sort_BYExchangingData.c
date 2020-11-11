#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void create(int);
void display();
void selection_sort();
void bubble_sort();
struct node
{
    int data;
    struct node *next;
}*start=NULL;
int main()
{
    int choice,n,val;
    while(1)
    {
        printf ("Press 1 to create the list\n");
        printf("Press 2 to display the list\n");
        printf("Press 3 to sort the linked list using selection sort\n");
        printf("Press 4 to sort the linked list using bubble sort\n");
        printf("Press 5 to exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the number of elements: ");
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
            {
                printf("VAL%d = ",i);
                scanf("%d",&val);
                create(val);
            }
            break;
            case 2:display();
            break;
            case 3:selection_sort();
            break;
            case 4:bubble_sort();
            break;
            case 5:exit(0);
            break;
            default:printf("INVALID CHOICE.");
            break;
        }
    }
    return 0;
}
void create(int num)
{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    if(start==NULL)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
            q=q->next;
        temp->next=q->next;
        q->next=temp;
    }
}
void display()
{
    struct node *q;
    if(start==NULL)
        printf("LIST IS EMPTY\n");
    q=start;
    while (q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}
void selection_sort()
{
    struct node *p,*q;
    int temp;
    for(p=start;p->next!=NULL;p=p->next)
    {
        for(q=p;q!=NULL;q=q->next)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}
void bubble_sort()
{
    struct node *end,*p,*q;
    int temp;
    for(end=NULL;end!=start->next;end=q)
    {
        for(p=start;p->next!=end;p=p->next)
        {
            q=p->next;
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}
