//Double ended queue operations using arrays.
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int deque_arr[MAX];
int front=-1;
int rear=-1;
void insert_front();
void insert_rear();
int delete_front();
int delete_rear();
int peek();
void display();

/*Start of main function*/
int main()
{
    int item,choice;
    printf("\n\t\t\tMENU DRIVEN PROGRAM\n");
    while(1)
    {
        printf("\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                insert_front(item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                insert_rear(item);
                break;
            case 3:
                item=delete_front();
                printf("\t\t\tDeleted element is %d.\n",item);
                break;
            case 4:
                item=delete_rear();
                printf("\t\t\tDeleted element is %d.\n",item);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice.\n");
        }/*End of switch*/
    }/*End of while*/
}/*end of main*/

void insert_front(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(front==0)
            front=MAX-1;
        else
            front=front-1;;
    }
    deque_arr[front]=x;
    return;

}//End of insert_front function

void insert_rear(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(rear==MAX-1)
            rear=0;
        else
            rear=rear+1;
    }

    deque_arr[rear]=x;
    return;

}//End of insert_rear function

int delete_front()
{
    int item;
    if(front==-1)
    {
        printf("QueueUnderflow\n");
        exit(1);
    }
    item=deque_arr[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1)
        front=0;
    else
        front=front+1;
    return item;
}//End of delete function

int delete_rear()
{
    int item;
    if(front==-1)
    {
        printf("QueueUnderflow\n");
        exit(1);
    }
    item=deque_arr[rear];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=MAX-1;
    else
        rear=rear-1;
    return item;
}//End of delete_rear function

void display(){
    if(front==-1)
    {
        printf("QueueUnderflow\n");
        return;
    }
    printf("\t\t\tElements in the queue are: ");
    int i=front;
    if(front<=rear)
    {
        while(i<=rear)
            printf("%d ",deque_arr[i++]);
    }
    else{
        while(i<=MAX-1)
            printf("%d ",deque_arr[i++]);
        i=0;
        while(i<=rear)
            printf("%d ",deque_arr[i++]);
    }
    printf("\n");
    return;
}//End of display function

