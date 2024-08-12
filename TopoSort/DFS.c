#include<stdio.h>
int graph[10][10],stack[10],top=-1,visited[10]={0},count=0,n,path[10]={0},isAcyclic=1;

void createGraph(){
    printf("Enter number of nodes>>");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&graph[i][j]);
        }
        
    }
    
}
void dfs(int start){
    visited[start]=1;
    path[start]=1;
    for (int i = 0; i < n; i++)
    {
        if (graph[start][i])
        {
            if (!visited[i])
            {
                dfs(i);
            }
            else if (path[i])
            {
                isAcyclic=0;
            }
            
        }
        
    }
    path[start]=0;
    stack[++top]=start;
}
int main(){
    createGraph();
    
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
        
    }
    if(!isAcyclic){
        printf("Error\n");
        return -1;
    }
    printf("Topologically sorted order\n");
    while(top!=-1)
        printf("-->>%d",stack[top--]);
    return 0;
}