#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*last=NULL;
void createNode(int);
void display();
void insert_beg(int);
void insert_specific(int,int);
void count_nodes();
void search(int);
void insert_after_val(int,int);
void del_by_val(int);
void del_by_pos(int pos);
int main()
{
    int d,d1,d2,pos,choice,val_search,val_node,item,del_val,pos_del;
    while(1)
    {
        printf("Press 1 to create a node in the circular linked list.\n");
        printf("Press 2 to display the list.\n");
        printf("Press 3 to insert a node at the beginning of the circular linked list.\n");
        printf("Press 4 to insert a node at a specific position of the circular linked list.\n");
        printf("Press 5 to count the number of nodes present in the list.\n");
        printf("Press 6 to search an element present in the list or not.\n");
        printf("Press 7 to insert a node after a given item in the circular linked list.\n");
        printf("Press 8 to delete a node if its value is given.\n");
        printf("Press 9 to delete a node by its position.\n");
        printf("Press 10 to exit:\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value of the node: ");
            scanf("%d",&d);
            createNode(d);
            break;
            case 2:display();
            break;
            case 3:printf("Enter the value of the node: ");
            scanf("%d",&d1);
            insert_beg(d1);
            break;
            case 4:printf("Enter the value and position of the node: ");
            scanf("%d %d",&d2,&pos);
            insert_specific(d2,pos);
            break;
            case 5:count_nodes();
            break;
            case 6:printf("Enter the value of the node for searching: ");
            scanf("%d",&val_search);
            search(val_search);
            break;
            case 7:printf("Enter the value of the node and and the item after which you want to add a new node: ");
            scanf("%d %d",&val_node,&item);
            insert_after_val(val_node,item);
            break;
            case 8:printf("Enter the value of the node: ");
            scanf("%d",&del_val);
            del_by_val(del_val);
            break;
            case 9:printf("Enter the position: ");
            scanf("%d",&pos_del);
            del_by_pos(pos_del);
            break;
            case 10:exit(0);
            break;
            default:printf("Invalid Choice:\n");
            break;
        }
    }
}
void createNode(int d)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    if(last==NULL)
    {
        temp->next=temp;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
    }
    last=temp;
    return;
}
void display()
{
    struct node *q;
    if(last==NULL){
        printf("List is empty.\n");
        return;
    }
    q=last->next;
    do
    {
        printf("%d ",q->data);
        q=q->next;
    }while(q!=last->next);
    printf("\n");
    return;
}
void insert_beg(int val)
{
    struct node *temp;
    if(last==NULL){
        printf("List is empty.\n");
    }
    temp=malloc(sizeof(struct node));
    temp->data=val;
    temp->next=last->next;
    last->next=temp;
}
void insert_specific(int val,int index)
{
    struct node *temp,*q;
    int c=0;
    if(last==NULL){
        printf("List is empty.\n");
    }
    q=last->next;
    temp=malloc(sizeof(struct node));
    temp->data=val;
    while(c<index-1)
    {
        q=q->next;
        c++;
    }
    temp->next=q->next;
    q->next=temp;
    if(q==last)
    {
        last=temp;
    }
}
void count_nodes()

{
    struct node *q=last->next;
    int count=1;
    if(last==NULL){
        printf("List is empty.\n");
    }
    while(q!=last)
    {
        q=q->next;
        count++;
    }
    printf("Number of nodes present in the list = %d\n",count);
    return;
}
void search(int num)
{
    struct node *q;
    int flag=0,count=0;
    if(last==NULL){
        printf("List is empty.\n");
    }
    q=last->next;
    do
    {
        if(q->data==num)
        {
            flag=1;
            break;
        }
        count++;
        q=q->next;
    }while(q!=last->next);
    if(flag==1)
        printf("Data is present at index %d\n",count);
    else
        printf("Data is not present\n");
    return;
}
void insert_after_val(int val,int item)
{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=val;
    q=last->next;
    do{
        if(q->data==item){
            temp->next=q->next;
            q->next=temp;
            if(q==last)
                last=temp;
            return;
        }
        q=q->next;
    }while(q!=last->next);
    printf("%d is not present in the list.\n",item);
    return;
}
//There is something wrong because it will not work if youn to delete the last element.
void del_by_val(int val)
{
    struct node *temp,*q;
    if(last==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if(last->data==val && last->next==last)
    {
        temp=last;
        last=NULL;
        free(temp);
        return;
    }
    if(last->next->data==val)
    {
        temp=last->next;
        last->next=temp->next;
        free(temp);
        return;
    }
    q=last->next;
    while(q->next->next!=last->next)
    {
        if(q->next->data==val)
        {
            temp=q->next;
            q->next=temp->next;
            free(temp);
            return;
        }
        q=q->next;
    }
    if(q->next->data==val)
    {
        q->next=last->next;
        temp=last;
        last=q;
        free(temp);
        return;
    }
    printf("Data is not present in the list.Enter a valid data.\n");
    return;
}
void
