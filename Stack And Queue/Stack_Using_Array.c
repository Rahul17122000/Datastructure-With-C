#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;
void push();
int pop();
int peek();
void display();
/*Start of main function*/
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
                printf("Last Pushed Element is: %d\n",item);
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
void push(int item)
{
    if(top==MAX-1){
        printf("StackOverflow.\n");
        return;
    }
    else{
        top++;
        stack_arr[top]=item;
        return;
    }
}
int pop()
{
    int x;
    if(top==-1){
        printf("StackUnderflow.\n");
        exit(1);
    }
    else{
        x=stack_arr[top];
        top--;
        return x;
    }
}
int peek()
{
    int x;
    if(top==-1){
        printf("StackUnderflow.\n");
        return 0;
    }
    else{
        x=stack_arr[top];
        return x;
    }
}
void display()
{
    if(top==-1)
    {
        printf("StackUnderflow\n");
        return;
    }
    printf("Elements in the stack are: ");
    for(int i=top;i>=0;i--)
        printf("%d ",stack_arr[i]);
    printf("\n");
    return;
}
