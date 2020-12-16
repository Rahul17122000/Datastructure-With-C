#include<stdio.h>
int linear_search(int [],int,int);
int main()
{
    int a[20],n,item,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of array : ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element for searching : ");
    scanf("%d",&item);
    i=linear_search(a,n,item);
    if(i!=-1)
        printf("%d is present at index number %d",item,i);
    else
        printf("%d is not present in the given array.",item);
    return 0;
}
int linear_search(int a[],int n,int item)
{
    for(int i=0;i<n;i++)
        if(a[i]==item)
            return i;
    return -1;
}
