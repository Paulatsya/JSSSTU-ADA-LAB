#include <stdio.h>
#include <stdlib.h>
int adjMat[10][10], visited[10] = {0}, queue[10], f = 0, r = -1, n, isAcyclic = 1, count = 0, bcount = 0;
void bfs(int start, int parent)
{
    visited[start] = 1;
    queue[++r] = start;
    while (f <= r)
    {
        int current = queue[f++];
        for (int i = 0; i < n; i++)
        {
            bcount++;
            if (adjMat[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[++r] = i;
                
            }
            if (adjMat[current][i] && visited[i])
            {
                isAcyclic = 0;
                
            }
        }
    }
}
void reset(){
    bcount=0;
    f=0;
    r=-1;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}
void plotter()
{
    FILE *f1 = fopen("bfs.txt", "w");
    for (int i = 1; i <= 10; i++)
    {
        n=i;
        reset();
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
        
        bfs(0, -1);
        fprintf(f1, "%d\t%d\n", n, bcount);
    }
}
int main()
{
    plotter();
    return 0;
}