#include <stdio.h>
#include <stdlib.h>

int graph[10][10], visited[10] = {0}, indegree[10] = {0}, n;

void createGraph()
{
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
}

void calculateIndegree()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            indegree[i] += graph[j][i];
        }
    }
}

void topologicalSort()
{
    int count = 0;

    printf("Topologically sorted order:\n");

    while (count < n)
    {
        int found = 0; // To check if a vertex with 0 indegree was found

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && indegree[i] == 0)
            {
                printf("%d  ", i);
                visited[i] = 1;
                count++;
                found = 1;

                // Decrease indegree of adjacent vertices
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][j])
                    {
                        graph[i][j] = 0;
                        indegree[j]--;
                    }
                }
                break; // Break to restart the loop from the first vertex
            }
        }

        if (!found)
        {
            printf("\nError: The graph might contain a cycle or the input is incorrect.\n");
            return;
        }
    }

    printf("\n");
}

void main()
{
    createGraph();
    calculateIndegree();

    printf("Indegree array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", indegree[i]);
    }

    topologicalSort();
}
