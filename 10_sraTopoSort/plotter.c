#include <stdio.h>
#include <stdlib.h>

int adjMat[10][10], visited[10] = {0}, indegree[10] = {0}, n, count, opcount;

// Function to perform topological sorting
void topologicalSort() {
    count = 0;
    while (count < n) {
        int found = 0; // Flag to check if any vertex with indegree 0 was found (checks for cycles)
        for (int i = 0; i < n; i++) {
            if (!visited[i] && indegree[i] == 0) {
                visited[i] = 1; // Mark vertex as visited (removing it from the graph)
                count++;
                found = 1;

                // Decrease indegree of adjacent vertices
                for (int j = 0; j < n; j++) {
                    opcount++; // Increment operation count for this loop
                    if (adjMat[i][j]) {
                        adjMat[i][j] = 0;
                        indegree[j]--;
                    }
                }

                break; // Restart loop from the first vertex
            }
        }
        if (!found) {
            printf("\nError!! Graph might contain a cycle\n");
            return;
        }
    }
    printf("End\n");
}

// Function to plot operation count for different sizes of graph
void plotter() {
    FILE *f1 = fopen("srcrmMatTopSort.txt", "w");

    for (int k = 1; k <= 10; k++) {
        n = k;

        // Reset adjacency matrix and indegree array
        for (int i = 0; i < n; i++) {
            indegree[i] = 0;
            visited[i] = 0; 
            for (int j = 0; j < n; j++) {
                adjMat[i][j] = 0; 
            }
        }

        // Create a source removal matrix (upper triangular matrix)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adjMat[i][j] = 1; 
                indegree[j]++; 
            }
        }

        opcount = 0; // Reset operation count
        topologicalSort(); 
        fprintf(f1, "%d\t%d\n", n, opcount); 
    }

    fclose(f1); 
}

int main() {
    plotter();
    return 0;
}
