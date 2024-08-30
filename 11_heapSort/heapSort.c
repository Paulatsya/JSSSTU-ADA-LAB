// Program to implement HEAPSORT to sort an array
// Question 11
#include <stdio.h>
#include <stdlib.h>
int count;
int arr[] = {2, 4, 5, 1, 5, 6, 7, 8, -1, -23};
void swap(int *a, int *b)
{ // funtion to swap two elements in list
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *arr, int n, int i)
{
    int largest = i;                          // initializing index of largest value
    int left = 2 * i + 1;                     // left child
    int right = 2 * i + 2;                    // right child
    if (left < n && arr[left] > arr[largest]) // check wheter left child is greater than largest value
        largest = left;
    if (right < n && arr[right] > arr[largest]) // check wheter right child is greater than largest value
        largest = right;
    if (largest != i)
    { // if the largest value is changed then we swap it and heapify till we find largest value
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int *arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--) // (n/2)-1 is to determine last non leaf node in heap
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main(int argc, char const *argv[])
{
    heapSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
