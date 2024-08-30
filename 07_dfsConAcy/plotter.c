#include <stdio.h>
#include <stdlib.h>

int adjMat[10][10], visited[10] = {0}, n, isAcyclic = 1, count = 0, dcount = 0;

void dfs(int start, int parent)
{
    visited[start] = 1;
    count++;

    for (int i = 0; i < n; i++)
    {   
        dcount++;
        if (adjMat[start][i]) // If there's an edge from start to i
        {
            if (!visited[i])
            {
                dfs(i, start);
            }
            else if (visited[i] && i != parent)
            {

                isAcyclic = 0;
                
            }
        }
    }
}
void plotter()
{
    FILE *f1;

    f1 = fopen("dfs.txt", "w");

    for (int i = 1; i <= 10; i++)
    {
        n = i;
        // Worst case: Complete graph
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (j != k)
                {
                    adjMat[j][k] = 1;
                }
                else
                {
                    adjMat[j][k] = 0;
                }
            }
        }
        dfs(0, -1);
        fprintf(f1, "%d\t%d\n", n, dcount);
    }

    fclose(f1);
}

int main()
{
    plotter();
    return 0;
}
