#include<stdio.h>
int graph[10][10],isAcyclic=1,visited[10]={0},n,count;

void createGraph(){
	printf("No. of vertices>> ");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}

void dfs(int start,int parent){
    visited[start]=1;
    count++;
    printf("%d-->",start);
    for(int i=0;i<n;i++){
        if(graph[start][i] && visited[i] && i!=parent)
            isAcyclic=0;
        if(graph[start][i] && !visited[i])
            dfs(i,start);
    }
}

int main()
{
    createGraph();
    dfs(0,-1);
    (count==n)?printf("Connected yes\n"):printf("Connected no\n");
    (isAcyclic)?printf("ACyclic"):printf("Cyclic");
    if(count<n){
        for (int i = 0; i < n; i++)
        {
            visited[i]=0;
        }
        for (int i = 0; i < n; i++)
        {
            dfs(i,-1);
            printf("\n");
        }
        
    }

    return 0;
}
