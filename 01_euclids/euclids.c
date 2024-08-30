#include <stdio.h>
#include<stdlib.h>

int count;
int euclid(int m, int n)
{
    int r;
    count = 0;
    while (n)
    {
        r = m % n;  
        m = n;
        n = r;
        count++;
    }
    printf("GCD is %d\n", m);
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
        count++;
        m = m - n;
    }
    printf("GCD is %d\n", m);
    return count;
}
int consec(int m, int n)
{
    int min = (m < n) ? m : n;
    while (min > 0)
    {
        count++;
        if (m % min == 0 && n % min == 0)
        {
            break;
        }
        min--;
    }
    printf("GCD is %d\n", min);
    return count;
}
int main()
{
    int ch, m, n;
    while (1)
    {
        printf("GCD\n");
        printf("1.Euclid\n2.modified Euclid\n3.consecutive integer method\n0to exit\n");
        scanf("%d", &ch);
        if (ch == 0)
        {
            break;
        }
        printf("Enter the values m and n\n");
        scanf("%d", &m);
        scanf("%d", &n);
        switch (ch)
        {
        case 1:
            euclid(m, n);
            printf("%d\n", count);
            break;
        case 2:
            modified(m, n);
            printf("%d\n", count);
            break;
        case 3:
            consec(m, n);
            printf("%d\n", count);
            break;
        default:
            break;
        }
    }
    return 0;
}
