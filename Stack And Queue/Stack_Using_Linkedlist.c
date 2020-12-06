/*Menu driven program*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;

//Push
void push(int item)
{
    struct node *temp;
    temp=malloc(sizeof(struct node*));
    if(temp==NULL)
    {
        printf("StackOverflow.\n");
        return;
    }
    temp->data=item;
    temp->next=top;
    top=temp;
    return;
}/*End of push*/

//Pop
int pop()
{
    struct node*temp;
    int item;
    if(top==NULL)
    {
        printf("StackOverflow.\n");
        exit(1);
    }
    temp=top;
    item=temp->data;
    top=temp->next;
    free(temp);
    return item;
}/*End of pop*/

//Peek
int peek()
{
    int item;
    if(top==NULL)
    {
        printf("StackOverflow.\n");
        exit(1);
    }
    return top->data;
}/*End of peek*/

void display()
{
    struct node *q;
    if(top==NULL)
    {
        printf("StackUnderflow.\n");
        exit(1);
    }
    printf("Element in the stack are: ");
    q=top;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
    return;
}

int main()
{
    int item,choice;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter yor choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item=pop();
                printf("Popped element is %d.\n",item);
                break;
            case 3:
                item=peek();
                printf("Peek element of the stack is: %d\n",item);
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
}/*End of main*/
