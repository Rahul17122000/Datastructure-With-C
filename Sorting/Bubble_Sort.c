#include<stdio.h>
//Taking max size=10
#define MAX 10
int main()
{
    int arr[MAX],n;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Entered elements are: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    //Implementing Bubble sort(In ascending order
    int end=n-1,i,j,check,temp;
    for(i=n-1;i>0;i--)//for(i=0;i<n-1;i++)
    {
        check=0;
        for(j=0;j<i;j++)//for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                check++;
            }
        }
        if(check==0)
            break;
    }

    //Display sorted order
    printf("Sorted Order: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
