#include<stdio.h>
#include<stdlib.h>


#define large 9999 
int path[10][10],wtMat[10][10],n;

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
            scanf("%d", &wtMat[i][j]);
            if (wtMat[i][j]==0 && i!=j)
            {
                wtMat[i][j]=large;
            }
            
        }
    }
}
void floyd(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j]=wtMat[i][j];
        }
        
    }
    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (path[i][k]!=large && path[k][j]!=large)
                {
                    if ((path[i][k] + path[k][j]) < path[i][j])
                    {
                        path[i][j]=path[i][k] + path[k][j];
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
}
void pathPrint(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(path[i][j]==large){
                printf("-1\t");
            }else
            {
                printf("%d\t",path[i][j]);
            }
            
        }
        printf("\n");
        
    }
    
}
int main(int argc, char const *argv[])
{
    createGraph();
    floyd();
    pathPrint();
    return 0;
}
