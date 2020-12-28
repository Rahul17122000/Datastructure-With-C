#include<stdio.h>
//Taking max size=10
#define MAX 10
int main()
{
    int arr[MAX],n;

    printf("Number of elements: ");
    scanf("%d",&n);
    fflush(stdin);
    printf("Entered elements are: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    //Implementing selection sort(In ascending order)
    int min,temp,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

    //Display sorted order
    printf("Sorted Order: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
