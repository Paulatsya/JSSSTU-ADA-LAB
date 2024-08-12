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
void merge(int *a, int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;
    int b[100];
    while (i <= mid && j <= high)
    {

        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void mergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int *a, len;

    printf("Enter number of elements");
    scanf("%d", &len);
    a = (int *)malloc(sizeof(int *) * len);
    printf("Enter elements\n");
    a = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("array before sort\n");
    printArray(a, len);
    mergeSort(a, 0, len - 1);
    printf("Elements afet sort\n");
    printArray(a, len);
    return 0;
}
