#include <stdio.h>
#include <stdlib.h>
void printArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int partition(int *a, int low, int high)
{   
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= pivot && i<=high)
        {
            i++;
        }
        while (a[j] > pivot && j>=low)
        {
            j--;
        }
        if (i < j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    } while (i < j);
    
    temp=a[j];
    a[j]=a[low];
    a[low]=temp;
    return j;
}
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}
int main()
{
    int *a, len;
    printf("Enter number of elements");
    scanf("%d", &len);
    printf("Enter elements\n");
    a = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        printf("a[%d]",i);
        scanf("%d", &a[i]);
    }
    printf("array before sort\n");
    printArray(a, len);
    quickSort(a, 0, len - 1);
    printf("Elements afet sort\n");
    printArray(a, len);
    return 0;
}