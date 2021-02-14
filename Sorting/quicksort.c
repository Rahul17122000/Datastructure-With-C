#include<stdio.h>
#include<stdlib.h>
const int max=20;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[], int l, int h)
{
    int pivot=a[h];
    int i=(l - 1);

    for (int j=l; j <= h- 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return (i + 1);
}
void quicksort(int a[], int l, int h)
{
    int j;
    if(l<h)
    {
        j=partition(a, l, h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}
int main()
{
    int a[max];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a, 0, n-1);
    printf("Required array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
