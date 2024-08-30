#include <stdio.h>
#include <stdlib.h>
int count;
int linearSearch(int *arr, int n, int k)
{
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (++count && arr[i] == k)
        {
            return count;
        }
    }
    return count;
}
int binarySearch(int *arr, int l, int h, int k)
{
    count++;
    if (l < h)
    { /// high>low indicates key not found
        int mid = (h + l) / 2;
        if (k == arr[mid])
        {

            return count;
        }
        else if (arr[mid] > k)
        {
            return binarySearch(arr, l, mid - 1, k);
        }
        else
        {
            return binarySearch(arr, mid + 1, h, k);
        }
    }
    return count;
}
void lsplotter()
{
    FILE *f1, *f2, *f3;
    int i, j, c, key;
    f1 = fopen("linearBest.txt", "w");
    f2 = fopen("linearAvg.txt", "w");
    f3 = fopen("linearWorst.txt", "w");
    for (i = 2; i < 1000; i += 10)
    {
        int arr[i];
        for (j = 0; j < i; j++)
        {
            arr[j] = 1; // best case-->first element in list is key
        }
        c = linearSearch(arr, i, 1);
        fprintf(f1, "%d\t%d\n", i, c);
        for (j = 0; j < i; j++)
        {
            arr[j] = rand() % i; // avg case-->random numbers in list
        }
        key = rand() % i;
        c = linearSearch(arr, i, key);
        fprintf(f2, "%d\t%d\n", i, c);
        for (j = 0; j < i; j++)
        {
            arr[j] = 0; // worst case-->key not in list
        }
        c = linearSearch(arr, i, 1);
        fprintf(f3, "%d\t%d\n", i, c);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void bsplotter()
{
    FILE *f1, *f2, *f3;
    int i, j, c, mid, key;
    f1 = fopen("binaryBest.txt", "w");
    f2 = fopen("binaryAvg.txt", "w");
    f3 = fopen("binaryWorst.txt", "w");
    for (i = 2; i < 1000; i += 10)
    {
        int arr[i];
        for (j = 0; j < i; j++)
        {
            arr[j] = 1;
        }
        mid = (i - 1) / 2; // best case --> middle element in list is the key(found at first iteration)
        arr[mid] = 0;
        count = 0;
        c = binarySearch(arr, 0, i - 1, 0);
        fprintf(f1, "%d\t%d\n", i, c);
        for (j = 0; j < i; j++)
        {
            arr[j] = j + 1; // avg case-->sorted list, random key
        }
        key = rand() % i + 1;
        count = 0;
        c = binarySearch(arr, 0, i - 1, key);
        fprintf(f2, "%d\t%d\n", i, c);
        for (j = 0; j < i; j++)
        {
            arr[j] = j; // worst case--> sorted list,key not found
        }
        count = 0;
        key = i + 1;
        c = binarySearch(arr, 0, i - 1, key);
        fprintf(f3, "%d\t%d\n", i, c);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main(int argc, char const *argv[])
{
    lsplotter();
    bsplotter();
    return 0;
}
