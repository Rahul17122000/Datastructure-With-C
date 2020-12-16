
//Circular Queue operations using arrays.
//It follows FIFO order(that is first in first out).
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cqueue_arr[MAX];
int front=-1;
int rear=-1;
void insert();
int delet();
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
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                item=delet();
                printf("\t\t\tDeleted element(i.e, first inserted element) is %d.\n",item);
                break;
            case 3:
                item=peek();
                printf("\t\t\tFirst Inserted Element is: %d\n",item);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice.\n");
        }/*End of switch*/
    }/*End of while*/
}/*end of main*/

void insert(int x)
{
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    if(rear==MAX-1)
        rear=0;
    else
        rear=rear+1;
    cqueue_arr[rear]=x;
    return;
}//End of insert function

int delet()
{
    int item;
    if(front==-1)
    {
        printf("QueueUnderflow\n");
        exit(1);
    }
    item=cqueue_arr[front];
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

int peek()
{
    if(front==-1)
    {
        printf("QueueUnderflow\n");
        exit(1);
    }
    return cqueue_arr[front];
}//End of peek function

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
            printf("%d ",cqueue_arr[i++]);
    }
    else{
        while(i<=MAX-1)
            printf("%d ",cqueue_arr[i++]);
        i=0;
        while(i<=rear)
            printf("%d ",cqueue_arr[i++]);
    }
    printf("\n");
    return;
}//End of display function
