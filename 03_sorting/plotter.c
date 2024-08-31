#include <stdio.h>
#include <stdlib.h>
int count;
int bubbleSort(int *arr, int n)
{
    count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (++count && arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return count;
}
int insertionSort(int *arr, int n)
{
    int i, j, cur;
    count = 0;
    for (int i = 1; i < n; i++)
    {
        cur = arr[i];
        j = i - 1;
        while (++count && arr[j] > arr[i] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
    return count;
}
int selectionSort(int *arr, int n)
{
    int small;
    count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        small = i;
        for (int j = i+1; j < n; j++)
        {
            if (++count && arr[j] < arr[small])
            {
                small = j;
            }
        }
        if (small != i)
        {
            int temp = arr[small];
            arr[small] = arr[i];
            arr[i] = temp;
        }
    }
    return count;
}
void plotterB()
{ // plotting for bubble sort
    int n, c;
    FILE *f1, *f2, *f3;
    f1 = fopen("bubbleBest.txt", "w");
    f2 = fopen("bubbleAvg.txt", "w");
    f3 = fopen("bubbleWorst.txt", "w");
    n = 10;
    while (n <= 1000)
    {
        int *arr=(int *)malloc(sizeof(int)*n);
        // best case bubble--> sorted array
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        c = bubbleSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, c);
        // avg case bubble--> random order
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        c = bubbleSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, c);
        // worst case bubble--> descending order
        for (int i = 0; i < n; i++)
        {
            arr[i] = n-i;
        }
        c = bubbleSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, c);
        n += 10;
        free(arr);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}
// insertion and bubble sort have same testcases for best/worst/avg cases
void plotterI()
{ // plotting for insertion sort
    int n, c;
    FILE *f1, *f2, *f3;
    f1 = fopen("insertionBest.txt", "w");
    f2 = fopen("insertionAvg.txt", "w");
    f3 = fopen("insertionWorst.txt", "w");
    n = 10;
    while (n <= 1000)
    {
        int *arr=(int *)malloc(sizeof(int)*n);
        // best case insertion--> sorted array
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        c = insertionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, c);
        // avg case insertion--> random order
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % n;
        }
        c = insertionSort(arr, n);
        fprintf(f2, "%d\t%d\n", n, c);
        // worst case insertion--> descending order
        for (int i = 0; i < n; i++)
        {
            arr[i] = n-i;
        }
        c = insertionSort(arr, n);
        fprintf(f3, "%d\t%d\n", n, c);
        n += 10;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
// time complexity is same regardless of best/worst case
void plotterS()
{ // plotting for insertion sort
    FILE *f1;
    f1 = fopen("selection.txt", "w");
    int n = 10, c;
    while (n <= 1000)
    {
        int *arr=(int *)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1; /// does not need to be sorted can be any testcase
        }
        c = selectionSort(arr, n);
        fprintf(f1, "%d\t%d\n", n, c);
        n += 10;
        free(arr);
    }
    fclose(f1);
}

int main()
{
    plotterB();
    plotterI();
    plotterS();
    return 0;
}
