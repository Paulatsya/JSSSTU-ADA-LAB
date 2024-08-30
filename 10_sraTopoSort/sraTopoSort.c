
#include <stdio.h>
#include <stdlib.h>

int adjMat[10][10], visited[10] = {0}, indegree[10] = {0}, n,count;

void createGraph()
{
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);
    }
}
void calculateIndegree(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            indegree[i] += adjMat[j][i];
        }
        
    }
    
}
void topologicalSort(){
    count=0;
    while (count<n)
    {
        int found=0;//flag to check if any vertext with indegree 0 ws founfd(checks for cycles)
        for (int i = 0; i < n; i++)
        {
            if(!visited[i] && indegree[i]==0){
                printf("%d-->",i);
                visited[i]=1;//removing one source
                count++;
                found=1;

                //decrease indegree by 1 of the discarded source
                for (int j = 0; j < n; j++)
                {
                    if (adjMat[i][j])
                    {
                        adjMat[i][j]=0;
                        indegree[j]--;
                    }
                    
                }
                break; //restart loop from first vertex
                
            }
        }
        if(!found){
            printf("\nError!!Graph might contain a cycle\n");
            return;
        }
    }
    
}
int main(int argc, char const *argv[])
{
    createGraph();
    calculateIndegree();
    //indegree array
    printf("Indegree array(Node Value)>>\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n",i,indegree[i]);
    }
    
    topologicalSort();
    return 0;
}
