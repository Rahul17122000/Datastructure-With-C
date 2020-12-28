#include<stdio.h>
//Taking max size=10
#define MAX 10
int main()
{
    int arr[MAX],n,i,j,temp;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Entered elements are: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    //Implementing Bubble sort(In ascending order
    for(i=1;i<n;i++)//3 4 5 12 11
    {
        temp=arr[i];//3
        for(j=i-1;j>=0&&temp<arr[j];j--)
            arr[j+1]=arr[j];
        arr[j+1]=temp;
    }

    //Display sorted order
    printf("Sorted Order: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
