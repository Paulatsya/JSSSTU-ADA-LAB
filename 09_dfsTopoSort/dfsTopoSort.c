 #include<stdio.h>
int graph[10][10],stack[10],top=-1,visited[10]={0},count=0,n,isAcyclic=1;

 void createGraph(){
    printf("Enter number of nodes>>");
    scanf("%d",&n);
    printf("Enter adjacency Matrix>>");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d][%d]>> ",i,j);
            scanf("%d",&graph[i][j]);
        }
        
    }
    
}
void dfs(int start,int parent){
    visited[start]=1;
    for (int i = 0; i < n; i++)
    {
        if(graph[start][i]){
            if(!visited[i]){
                dfs(i,start);
            }
            if(visited[i] && i!=parent){
                isAcyclic=0;
            }
        }
    }
    stack[++top]=start;
}
int main(){
    createGraph();
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            dfs(i,-1);
        }
    }
    if(!isAcyclic){
        printf("Error!! Can't Topological sort cyclic graphs");
        return -1;
    }
    printf("Topologically sorted order\n");
    while(top!=-1){
        printf("%d-->",stack[top--]);
    }
    return 0;
}