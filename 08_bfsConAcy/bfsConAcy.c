#include <stdio.h>
#include <stdlib.h>
int adjMat[10][10], visited[10] = {0}, queue[10], n, isAcyclic = 1, f = 0, r = -1;
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
void bfs(int start) {
    
    visited[start] = 1; // Mark start node as visited
    queue[++r] = start; // Enqueue the start node
    printf("%d-->",start);
    while (f <= r) {
        int current = queue[f++]; // Dequeue front node
        for (int i = 0; i < n; i++) {
            if (adjMat[current][i]) { // If there's an edge
                if (!visited[i]) {
                    // If the node hasn't been visited, mark it and enqueue
                    visited[i] = 1;
                    printf("%d-->",i);
                    queue[++r] = i;
                } else{
                    // If an adjacent node is visited and isn't the parent, we found a cycle
                    isAcyclic = 0;
                    
                }
            }
        }
    }
}
int main()
{
    int i, count = 0;

    createGraph();

    bfs(0);

    for (i = 0; i < n; i++)
    {
        if (visited[i])
            count++;
    }

    (count == n) ? printf("\nConnected Graph\n") : printf("\nGraph not connected!\n");
    (isAcyclic) ? printf("Acyclic Graph\n") : printf("Graph not acyclic!\n");

    // Printing connected components

    if (count != n)
    {
        for (i = 0; i < n; i++)
            visited[i] = 0;

        for (i = 0; i < n; i++)
        {
            bfs1(i);
            printf("\n");
        }
    }
    return 0;
}