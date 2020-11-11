#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void createNode(int);
void display();
void insert_beg(int);
void insert_specific(int,int);
void insert_end(int);
void count_nodes();
void del_beg();
void del_specific(int);
void del_by_value(int);
void search(int);
void reverse();
struct node
{
    int data;
    struct node *next;
}*start=NULL;
int main()
{
    int choice,n,pos,val,num,del_pos,val_search,del_val;
    while(1)
    {
        printf ("Press 1 to create the list\n");
        printf("Press 2 to display the list\n");
        printf("Press 3 to insert a node at the beginning of the list\n");
        printf("Press 4 to insert a node at a specific position of the list\n");
        printf("Press 5 to insert a node at the end of the list\n");
        printf("Press 6 to count the number of nodes in the list\n");
        printf("Press 7 to delete a node from the beginning of the list\n");
        printf("Press 8 to delete a node from a specific position of the list\n");
        printf("Press 9 to search an element present in the list or not\n");
        printf("Press 10 to reverse the linked list\n");
        printf("Press 11 to delete a node if its data is given\n");
       // printf("Press 12 to display the list in the reverse order\n");
        printf("Press 13 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the value of the node\n");
            scanf("%d",&n);
            createNode(n);
            break;
            case 2:display();
            break;
            case 3:printf("enter the value of the node: ");
            scanf ("%d",&n);
            insert_beg(n);
            break;
            case 4:printf("Enter the value of the node and its position: ");
            scanf("%d %d",&val,&pos);
            insert_specific(val,pos);
            break;
            case 5:printf("Enter the value of the node: ");
            scanf("%d",&num);
            insert_end(num);
            break;
            case 6:count_nodes();
            break;
            case 7:del_beg();
            break;
            case 8:printf("Enter the position of the node for deletion: ");
            scanf("%d",&del_pos);
            del_specific(del_pos);
            break;
            case 9:printf("Enter the value of the node for searching: ");
            scanf("%d",&val_search);
            search(val_search);
            break;
            case 10:reverse();
            break;
            case 11:printf("Enter the value of the node: ");
            scanf("%d",&del_val);
            del_by_value(del_val);
            break;
            /*case 12:reverse_print(start);
            break;*/
            case 13:exit(0);
            break;
            default:printf("Invalid choice!");
            break;
        }
    }
    return 0;
}
void createNode(int num)
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
void display ()
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
void insert_beg(int num)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->next=start;
    start=temp;
    return;
}
void insert_specific(int val,int index)
{
    struct node *temp,*q;
    int count=0;
    temp=malloc(sizeof(struct node));
    temp->data=val;
    if(start==NULL)
        printf("LIST IS EMPTY\n");
    q=start;
    while(count<index-1)
    {
        q=q->next;
        count++;
    }
    temp->next=q->next;
    q->next=temp;
}
void insert_end(int num)
{
    struct node *temp,*q=start;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    while(q->next!=NULL)
        q=q->next;
    temp->next=q->next;
    q->next=temp;
}
void count_nodes()
{
    struct node *q=start;
    int count=0;
    while(q!=NULL)
    {
        q=q->next;
        count++;
    }
    printf("Number of nodes present in the list = %d\n",count);
    return;
}
void del_beg()
{
    struct node *temp;
    if(start==NULL)
        printf("List is empty.\n");
    temp=start;
    start=start->next;
    free(temp);
}
void del_specific(int index)
{
    struct node *temp,*q;
    q=start;
    int count=0;
    while(count<index-1)
    {
        q=q->next;
        count++;
    }
    temp=q->next;
    q->next=temp->next;
    free(temp);
    return;
}
void search(int num)
{
    struct node *q;
    int flag=0,count=0;
    q=start;
    while(q!=NULL)
    {
        if(q->data==num)
        {
            flag=1;
            break;
        }
        count++;
        q=q->next;
    }
    if(flag==1)
        printf("Data is present in index %d\n",count);
    else
        printf("Data is not present\n");
    return;
}
void reverse()
{
    struct node *q1=NULL,*q2=NULL;
    while(start!=NULL)
    {
        q2=start->next;
        start->next=q1;
        q1=start;
        start=q2;
    }
    start=q1;
}
//Another way of reversing a singly linked list.
/*
void reverse()
{
    struct node *p1,*p2,*p3;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
    return;
}*/
void del_by_value(int val)
{
    struct node *q,*temp;
    temp=start;
    if(temp->data==val)
    {
        start=start->next;
        free(temp);
        return;
    }
    q=start;
    while(q->next->next!=NULL)
    {
        if(q->next->data==val)
        {
            temp=q->next;
            q->next=q->next->next;
            free(temp);
            return;
        }
        q=q->next;
    }
    if(q->next->data==val)
    {
        temp=q->next;
        q->next=temp->next;
        free(temp);
        return;
    }
    else
       printf("Entered value is not present in the linked list.\n");
}
