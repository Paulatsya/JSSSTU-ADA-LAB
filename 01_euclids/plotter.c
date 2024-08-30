#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int count;
int euclid(int m, int n)
{
    int r;
    count = 0;
    while ((n > 0))
    {
        r = m % n;
        m = n;
        n = r;
        count++;
    }
    return count;
}
int modified(int m, int n)
{
    count = 0;
    while (n > 0)
    {
        if (n > m)
        {
            int temp = n;
            n = m;
            m = temp;
        }
        m = m - n;
        count++;
    }
    return count;
}
int consec(int m, int n)
{
    int min = (m < n) ? m : n;
    count = 0;
    while (min > 0)
    {
        if (++count && m % min == 0 && n % min == 0)
        {
            break;
        }
        min--;
    }
    
    return count;
}
void plotter()
{
    FILE *f1 = fopen("euclidBest.txt", "w");
    FILE *f2 = fopen("euclidWorst.txt", "w");
    FILE *f3 = fopen("consecBest.txt", "w");
    FILE *f4 = fopen("consecWorst.txt", "w");
    FILE *f5 = fopen("modifiedBest.txt", "w");
    FILE *f6 = fopen("modifiedWorst.txt", "w");

    for (int i = 10; i <= 100; i += 10)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                euclid(j, k);
                if (count < min)
                    min = count;
                if (count > max)
                    max = count;
            }
        }
        fprintf(f1, "%d\t%d\n", i, min);
        fprintf(f2, "%d\t%d\n", i, max);
    }

    for (int i = 10; i <= 100; i += 10)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                consec(j, k);
                if (count < min)
                    min = count;
                if (count > max)
                    max = count;
            }
        }
        fprintf(f3, "%d\t%d\n", i, min);
        fprintf(f4, "%d\t%d\n", i, max);
    }

    for (int i = 10; i <= 100; i += 10)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int j = 2; j <= i; j++)
        {
            for (int k = 2; k <= i; k++)
            {
                modified(j, k);
                if (count < min)
                    min = count;
                if (count > max)
                    max = count;
            }
        }
        fprintf(f5, "%d\t%d\n", i, min);
        fprintf(f6, "%d\t%d\n", i, max);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
}
int main()
{
    plotter();
    return 0;
}
