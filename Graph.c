#include<stdio.h>
#define vertex 10
//insert edge
void insertEdge(int graph[vertex][vertex], int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}
//delete edge
void deleteEdge(int graph[vertex][vertex], int u, int v){
    graph[u][v] = 0;
    graph[v][u] = 0;
}
//search edge
int searchEdge(int graph[vertex][vertex], int u, int v){
    return graph[u][v];
}
//print matrix
void printMatrix(int graph[vertex][vertex], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int graph[vertex][vertex] = {0};
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 1, 2);
    insertEdge(graph, 2, 0);
    insertEdge(graph, 2, 3);

    printMatrix(graph, 4);
}