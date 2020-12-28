//In open addressing there are 3 ways to implement hashing.
//I used linear probing here but u can easily implement quadratic and double hashing technique.
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
enum type_record{
    EMPTY,DELETED,OCCUPIED
};
struct employee{
    int empid;
    char name[20];
    int age;
};
struct record{
    struct employee info;
    enum type_record status;
};

//Hash function
int hash(int key)
{
    return key%50;
}

//Insert function
void insert(struct record table[],struct employee emprec)
{
    int key,loc;
    //key=emprec.empid;
    //h=hash(key);
    //loc=h;
    loc=hash(emprec.empid);
    for(int i=1;i<MAX-1;i++)
    {
        if(table[loc].status==EMPTY || table[loc].status==DELETED)
        {
            table[loc].info=emprec;
            table[loc].status=OCCUPIED;
            printf("Record inserted.\n");
            return;
        }
        if(table[loc].info.empid==emprec.empid)
        {
            printf("Duplicate key.\n");
            return;
        }
        loc=hash(emprec.empid+i);
    }
}

//Search Function
int search(struct record table[],int key)
{
    int loc;
    int h=hash(key);
    //loc=hash(key);
    loc=h;
    for(int i=1;i<MAX-1;i++)
    {
        if(table[loc].status==EMPTY)
            return -1;
        if(table[loc].info.empid==key && table[loc].status==OCCUPIED)
            return loc;
        loc=(h+i)%MAX;
    }
    return -1;
}

//Delete Function
void del(struct record table[],int key)
{
    int loc=search(table,key);
    if(loc==-1)
        printf("Record not found\n");
    else
        table[loc].status=DELETED;
    return ;
}
//Display function
void display(struct record table[])
{
    for(int i=0;i<MAX;i++)
    {
        printf("%d\t: ",i);
        if(table[i].status==OCCUPIED)
        {
            printf("Occupied: %d  %s",table[i].info.empid,table[i].info.name);
            printf(" %d\n",table[i].info.age);
        }
        else if(table[i].status==DELETED)
            printf("Deleted\n");
        else
            printf("Empty.\n");
    }
}
int main()
{
    int choice,key;
    struct record table[MAX];
    struct employee emprec;
    for(int i=0;i<MAX;i++)
        table[i].status=EMPTY;
    while(1)
    {
        printf("\n1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.SEARCH\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter empid,name,age: ");
                scanf("%d%s%d",&emprec.empid,emprec.name,&emprec.age);
                insert(table,emprec);
                break;
            case 2:
                printf("Enter a key to be deleted: ");
                scanf("%d",&key);
                del(table,key);
                break;
            case 3:
                printf("Enter a key to be searched: ");
                scanf("%d",&key);
                int i=search(table,key);
                if(i==-1)
                    printf("Key not found\n");
                else
                    printf("Key found at index %d\n",i);
                break;
            case 4:
                display(table);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("INVALID CHOICE\n");
        }//End of switch
    }//End of while
}//End of main

