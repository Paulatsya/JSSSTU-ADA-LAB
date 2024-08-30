#include <stdio.h>

int cost[40][40], n, visited[40] = {0},dist[40];

void createGraph() {
    printf("No. of vertices>> ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}
int findMinVertex(){
    int min=9999,minVertex;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i]<min)
        {
            min=dist[i];
            minVertex=i;
        }
        
    }
    return minVertex;
}
void dijkstra(int source){
    for (int i = 0; i < n; i++)
    {
        dist[i]=9999;
        visited[i]=0;
    }
    dist[source]=0;
    for (int i = 0; i < n-1; i++)
    {
        int unvisitedV = findMinVertex(); //finding the vertext which is unvisited and also has the smallest distance from source
        visited[unvisitedV]=1;
        for (int v = 0; v < n; v++)
        {
            if (cost[unvisitedV][v] && !visited[v] && (dist[unvisitedV] + cost[unvisitedV][v]) < dist[v] )
            {
                dist[v] = dist[unvisitedV] + cost[unvisitedV][v];
            }
            
        }
        
    }
    printf("Vertex>>Distance from Source\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d>>%d\n",i,dist[i]);
    }
    
    
}
int main(int argc, char const *argv[])
{
    createGraph();
    int source;
    printf("Enter the source vertex>> ");
    scanf("%d",&source);
    dijkstra(source);
    return 0;
}
