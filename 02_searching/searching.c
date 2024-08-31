#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linearSearch(int *arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int *arr, int k, int l, int h)
{
    if (l < h)
    {
        int mid = (h + l) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            return binarySearch(arr, k, l, mid - 1);
        }
        else
        {
            return binarySearch(arr, k, mid + 1, h);
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[10];
    int n, k, ch,i;
    printf("ENTER THE NUMBER OF ELEMENTS\n");
    scanf("%d", &n);
    printf("ENTER THE ELEMENTS OF THE ARRAY\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key:");
    scanf("%d", &k);
    while (1)
    {
        printf("1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. TO EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            i=linearSearch(arr,n,k);
            if (i==-1)
            {
                printf("Value not found!!\n");
            }
            else
                printf("Value found at index>> %d\n",i);
            
            break;
        case 2:
            i=binarySearch(arr,k,0,n-1);
            if (i == -1)
            {
                printf("Value not found\n");
            }
            else
                printf("Value found at index %d\n", i);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}

