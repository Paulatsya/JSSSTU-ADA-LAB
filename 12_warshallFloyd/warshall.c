#include <stdio.h>
#include <stdlib.h>

int n=3, count = 0, path[10][10], adjMat[10][10]={
        {0,1,0},
        {0,0,1},
        {0,0,0}
    };
void createGraph()
{
    printf("Enter number of nodes>> ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix>>");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d][%d]>> ", i, j);
            scanf("%d", &adjMat[i][j]);
        }
    }
}
void warshall()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = adjMat[i][j]; // cloning adjacency matrix to path(basically copying all direct paths)
        }
    }
    for (int k = 0; k < n; k++) // generating intermeditate node
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (path[i][k]) // code optimisation to reduce unnecessary iterations as path will exist only if INTERMEDIATE path exists
                {
                    // if path exists between i,j, then there must be a direct path hence logical OR
                    // to check for indirect path, we check if there exists a path between i,k and k,j hence logical AND
                    path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    
    //add createGraph() if want to use custom testcase  
    warshall();
    for ( int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t",path[i][j]);
            
        }
        printf("\n");
        
    }
    
    return 0;
}
