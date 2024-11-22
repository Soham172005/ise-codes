#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    int numVertices;
    GraphNode* adjList[MAX_VERTICES];
} Graph;

GraphNode* createNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void DFS(Graph* graph, int vertex, int visited[]) {
    printf("%d ", vertex);  
    visited[vertex] = 1;   

    GraphNode* temp = graph->adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited); 
        }
        temp = temp->next;
    }
}

void printGraph(Graph* graph) {
    printf("Adjacency List representation of the graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        GraphNode* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u, v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    int visited[MAX_VERTICES] = {0}; 
    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(graph, start, visited);
    printf("\n");

    return 0;
}