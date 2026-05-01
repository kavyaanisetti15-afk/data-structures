#include <stdio.h> 
#define MAX 10 
int adjMatrix[MAX][MAX]; 
int visited[MAX]; 
int n; // Number of vertices 
 
// DFS Function 
void DFS(int vertex) { 
    printf("Visited %d\n", vertex); 
    visited[vertex] = 1; 
 
    for (int i = 0; i < n; i++) { 
        if (adjMatrix[vertex][i] == 1 && !visited[i]) { 
            DFS(i); 
        } 
    } 
} 
 
int main() { 
    int edges, src, dest; 
 
    printf("Enter the number of vertices: "); 
    scanf("%d", &n); 
 
    // Initialize adjacency matrix and visited array 
    for (int i = 0; i < n; i++) { 
        visited[i] = 0; 
        for (int j = 0; j < n; j++) { 
            adjMatrix[i][j] = 0; 
        } 
    } 
 
    printf("Enter the number of edges: "); 
    scanf("%d", &edges); 
 
    printf("Enter edges (source and destination):\n"); 
    for (int i = 0; i < edges; i++) { 
        scanf("%d%d", &src, &dest); 
        adjMatrix[src][dest] = 1; 
        adjMatrix[dest][src] = 1;  // For undirected graph 
    }
    int startVertex; 
    printf("Enter the starting vertex for DFS: "); 
    scanf("%d", &startVertex); 
 
    printf("DFS Traversal:\n"); 
    DFS(startVertex); 
 
    return 0; 
} 