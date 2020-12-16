//Recursive Binary Search
#include<stdio.h>
int binary_search(int [],int,int,int);
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
    i=binary_search(a,item,0,n-1);
    if(i!=-1)
        printf("%d is present at index number %d",item,i);
    else
        printf("%d is not present in the given array.",item);
    return 0;
}
int binary_search(int a[],int item,int l,int r)
{
    int mid;
    if(l>r)
        return -1;
    mid=(l+r)/2;
    if(a[mid]<item)
       binary_search(a,item,mid+1,r);
    else if(a[mid]>item)
        binary_search(a,item,l,mid-1);
    else
        return mid;
}
