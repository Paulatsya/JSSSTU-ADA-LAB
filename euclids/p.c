void analysis(int ch)
{
    int m, n, i, j, k;
    float count, maxcount, mincount;
    FILE *fp1, *fp2;
    for (i = x; i <= y; i += 10)
    {
        maxcount = 0;
        mincount = 10000;
        for (j = 2; j <= i; j++) // To generate the data
        {
            for (k = 2; k <= i; k++)
            {
                count = 0;
                m = j;
                n = k;
                switch (ch)
                {
                case 1:
                    count = euclid(m, n);
                    break;
                case 2:
                    count = consec(m, n);
                    break;
                case 3:
                    count = modified(m, n);
                    break;
                }
                if (count > maxcount) //  To  find  the  maximum  basic  operations  among  all  the
                    combinations between 2 to n
                        maxcount = count;
                if (count < mincount)
                    // To find the minimum basic operations among all the combinations between 2
                    to n
                        mincount = count;
            }
        }
        switch (ch)
        {
        case 1:
            fp2 = fopen("e_b.txt", "a");
            fp1 = fopen("e_w.txt", "a");
            break;
        case 2:
            fp2 = fopen("c_b.txt", "a");
            fp1 = fopen("c_w.txt", "a");
            break;
        case 3:
            fp2 = fopen("m_b.txt", "a");
            fp1 = fopen("m_w.txt", "a");
            break;
        }
        fprintf(fp2, "%d %.2f\n", i, mincount);
        fclose(fp2);
        fprintf(fp1, "%d %.2f\n", i, maxcount);
        fclose(fp1);
    }
}