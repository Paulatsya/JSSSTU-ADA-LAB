#include <stdio.h>
#include <stdlib.h>
int linearSearch(int *a, int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            return i;
    }
    return -1;
}
int binarySearch(int *a, int k, int h, int l)
{
    if (l <= h)
    {
        int mid = l + (h + l) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] > k)
        {
            return binarySearch(a, k, mid - 1, l);
        }
        else
        {
            return binarySearch(a, k, h, mid + 1);
        }
    }
    return -1;
}
int main()
{
    int a[10];
    int n, k;
    while(1)
    {
        printf("ENTER 1. TO LINEAR SEARCH\n2. TO BINARY SEARCH\n3. TO EXIT\n");
        int ch,i;
        scanf("%d", &ch);
        printf("ENTER THE NUMBER OF ELEMENTS\n");
        scanf("%d", &n);
        printf("ENTER THE ELEMENTS OF THE ARRAY\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Enter key:");
        scanf("%d", &k);
        switch (ch)
        {
        case 1:
            i = linearSearch(a, k, n);
            if (n == -1)
            {
                printf("Value not found\n");
            }
            else
                printf("Value found at %d", k);
            break;
        case 2:
            i = binarySearch(a, k, n - 1, 0);
            if (n == -1)
            {
                printf("Value not found\n");
            }
            else
                printf("Value found at %d", k);
            break;

        default:
            break;
        }
    }
    return 0;
}
