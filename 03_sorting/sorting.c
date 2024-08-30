#include <stdio.h>
#include <stdlib.h>
void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);    
    }
    printf("\n");
}
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int *arr, int n)
{

    int i, j, cur;
    for (int i = 1; i < n; i++)
    {
        cur = arr[i];
        j = i - 1;
        while (arr[j] > cur && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
}
void selectionSort(int *arr, int n)
{
    int small;
    for (int i = 0; i < n - 1; i++)
    {
        small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[small])
                small = j;
        }
        if (small != i)
        {
            int temp = arr[small];
            arr[small] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    //taking random testcase
    int arr[6]={3,2,7,-4,6,1};
    printf("Before sorting\n");
    printArr(arr,6);

    bubbleSort(arr,6);
    printf("Bubble sort>>\n");
    printArr(arr,6);
    
    int arrI[6]={3,2,7,-4,6,1};
    insertionSort(arrI,6);
    printf("Insertion sort>>\n");
    printArr(arrI,6);
    
    int arrS[6]={3,2,7,-4,6,1};
    selectionSort(arrS,6);
    printf("Selection sort>>\n");
    printArr(arrS,6);
    
    return 0;
}
