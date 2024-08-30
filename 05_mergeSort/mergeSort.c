#include <stdio.h>
#include <stdlib.h>
void printArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int *a, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[high +1]; // creates temp array which then will be entered later into main array after sorting
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}
void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main(int argc, char const *argv[])
{
    int *arr, len;
    printf("Enter number of elements");
    scanf("%d", &len);
    arr = (int *)malloc(sizeof(int) * len); // a[len];
    for (int i = 0; i < len; i++)
    {
        printf("a[%d]>>", i);
        scanf("%d", &arr[i]);
    }
    printf("Printing Array Before Sort\n");
    printArray(arr, len);
    printf("Printing Array After Sort\n");
    mergeSort(arr, 0, len - 1);
    printArray(arr, len);

    return 0;
}
