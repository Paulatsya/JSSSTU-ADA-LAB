#include <stdio.h>
#include <stdlib.h>
int adjMat[10][10], visited[10] = {0}, n, isAcyclic = 1, count;
void createGraph()
{
    printf("Enter no. of vertices>> ");
    scanf("%d", &n);
    printf("Enter adjacency matrix>>\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d][%d]>> ", i, j);
            scanf("%d", &adjMat[i][j]);
        }
    }
}
void dfs(int start, int parent)
{
    visited[start] = 1;
    count++;
    printf("%d-->", start);
    for (int i = 0; i < n; i++)
    {
        if (adjMat[start][i])
        { // checking for edge between two nodes
            if (visited[i] && i != parent)
            {
                isAcyclic = 0; // if node previously visited,cycle exisits
            }
            else if (!visited[i])
            {
                dfs(i, start); // if node not visited perform dfs from that node
            }
        }
    }
}
int main()
{
    createGraph();
    dfs(0, -1);
    (count == n) ? printf("Connected Graph\n") : printf("Graph not connected\n");
    (isAcyclic) ? printf("Graph is Acyclic\n") : printf("Graph is Cyclic\n");
    if (count < n)
    {
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i, -1);
            printf("\n");
        }
    }
    return 0;
}
