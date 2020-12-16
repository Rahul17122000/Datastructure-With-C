#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL;

void create_node(int);
void display();

void count_nodes();
void search(int);

//void insert_beg(int);
//void insert_specific(int,int);
//void insert_end(int);

void del_beg();
void del_by_value(int);
void del_by_pos(int);

void reverse();
int main()
{
    int num,n,choice,val,del_pos,del_val;
    printf("\n\t\t\tMENU DRIVEN PROGRAM\n");
    while(1)
    {
        printf("\n1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.COUNT NODES\n");
        printf("4.SEARCH A VALUE\n");
        //printf("3.INSERT AT BEGINNING\n");
        //printf("4. INSERT AT SPECIFIC POSITION\n");
        //printf("5. INSERT AT END\n");
        printf("5.DELETE AT BEGINNING\n");
        printf("6.DELETE A NODE BY VALUE\n");
        printf("7.DELETE A NODE BY POSITION\n");
        printf("8.REVERSE\n");
        printf("9.EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the initial population: ");
            scanf("%d",&num);
            for(int i=1;i<=num;i++)
            {
                printf("Enter the value of node%d: ",i);
                scanf("%d",&n);
                create_node(n);
            }
            break;
            case 2:display();
            break;
            case 3:count_nodes();
            break;
            case 4:printf("Enter the value for searching: ");
            scanf("%d",&val);
            search(val);
            break;
            case 5:del_beg();
            break;
            case 6:printf("Enter the value of node for deletion: ");
            scanf("%d",&del_val);
            del_by_value(del_val);
            break;
            case 7:printf("Enter the position: ");
            scanf("%d",&del_pos);
            del_by_pos(del_pos);
            break;
            case 8:reverse();
            break;
            case 9:exit(0);
            break;
            default:printf("Invalid Choice!\n");
            break;
        }
    }
    return 0;
}
void create_node(int n)
{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        temp->prev=q;
        q->next=temp;
    }
    return;
}
void display()
{
    struct node *q;
    if(start==NULL)
    {
        printf("\t\t\t\tList is empty.\n");
        return;
    }
    printf("\t\t\tElements in the list are: ");
    q=start;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    return;
}
void search(int val)
{
    struct node *q;
    if(start==NULL)
    {
        printf("\t\t\t\tList is empty");
        return;
    }
    q=start;
    int count=0;
    while(q!=NULL)
    {
        if(q->data==val)
        {
            printf("\n\t\t\t\t%d is present at index %d",val,count);
            return;
        }
        q=q->next;
        count++;
    }
    printf("\n\t\t\t\tData is not present.");
    return;
}
void count_nodes()
{
    struct node *q=start;
    if(start==NULL )
    {
        printf("\t\t\t\tList is empty.\n");
        return;
    }
    int count=0;
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    printf("\t\t\tNumber of nodes in the list are: %d\n",count);
    return;
}

void del_beg()
{
    struct node *temp;
    if(start==NULL)
        printf("List is empty.\n");
    temp=start;
    start=start->next;
    start->prev=NULL;
    free(temp);
    return;
}

void del_by_value(int val)
{
    struct node *q,*temp;
    if(start==NULL)
    {
        printf("\t\t\t\tList is empty\n");
        return;
    }
    if(start->data!=val && start->next==NULL)
    {
        printf("\t\t\tData is not present\n");
        return;
    }
    if(start->data==val)
    {
        temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        free(temp);
        return;
    }
    q=start;
    while(q->next->next!=NULL)
    {
        if(q->next->data==val)
        {
            temp=q->next;
            q->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            return;
        }
        q=q->next;
    }
    if(q->next->data==val)
    {
        temp=q->next;
        q->next=NULL;
        free(temp);
        return;
    }
    printf("\t\t\tData is not present.\n");
}
//Taking position starting from 0.
void del_by_pos(int pos)
{
    struct node *temp,*q;
    if(start==NULL)
    {
        printf("\t\t\tList is empty.\n");
        return;
    }
    if(pos==0)
    {
        temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        free(temp);
        return;
    }
    q=start;
    int count=0;
    while(count<pos && q!=NULL)
    {
        q=q->next;
        count++;
    }
    if(q==NULL || pos<0)
    {
        printf("Enter a valid position.\n");
        return;
    }
    temp=q;
    q->prev->next=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);
    return;
}

void reverse()
{
    if(start==NULL)
    {
        printf("\t\t\t\tList is empty.\n");
        return;
    }
    struct node *p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    start=p1;
    return;
}
