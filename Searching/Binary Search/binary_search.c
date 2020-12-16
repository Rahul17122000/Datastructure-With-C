#include<stdio.h>
int binary_search(int [],int,int);
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
    i=binary_search(a,n,item);
    if(i!=-1)
        printf("%d is present at index number %d",item,i);
    else
        printf("%d is not present in the given array.",item);
    return 0;
}
int binary_search(int a[],int n,int item)
{
    int l=0,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]<item)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}
