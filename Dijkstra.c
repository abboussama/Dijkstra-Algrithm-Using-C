#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int num_vertices;
    struct AdjList* array;
};

struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    graph->array = (struct AdjList*) malloc(num_vertices * sizeof(struct AdjList));

    for (int i = 0; i < num_vertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

int minDistance(int dist[], int visited[], int num_vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < num_vertices; ++v)
        if (visited[v] == 0 && dist[v] < min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int destination) {
    if (parent[destination] == -1)
        return;

    printPath(parent, parent[destination]);
    printf(" -> %d", destination);
}

void printSolution(int dist[], int parent[], int source, int num_vertices) {
    for (int i = 0; i < num_vertices; ++i) {
        printf("Distance from %d to %d is %d, path: %d", source, i, dist[i], source);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(struct Graph* graph, int source) {
    int num_vertices = graph->num_vertices;
    // Initialize distance and visited arrays
    int dist[num_vertices];
    int visited[num_vertices];
    int parent[num_vertices];

    for (int i = 0; i < num_vertices; ++i) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Distance from source vertex to itself is 0
    dist[source] = 0;

    // Find the shortest path to all the vertices
    for (int count = 0; count < num_vertices - 1; ++count) {
        // Find the vertex with the minimum distance value
        int u = minDistance(dist, visited, num_vertices);

        // Mark the vertex as visited
        visited[u] = 1;

        // Update the distance value of the adjacent vertices of the visited vertex
        // Update the distance value of all adjacent vertices of the visited vertex
        struct Node *temp = graph->array[u].head;
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }

            temp = temp->next;
        }
    }

    // Print the distance from the source to all the vertices
    printSolution(dist, parent, source, num_vertices);
}
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->num_vertices; ++i) {
        struct Node* temp = graph->array[i].head;
        while (temp != NULL) {
            struct Node* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph->array);
    free(graph);
}

void TestDijkstra() {
    int num_vertices = 5;
    struct Graph* graph = createGraph(num_vertices);

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 10);
    addEdge(graph, 1, 4, 6);
    addEdge(graph, 2, 4, 8);
    addEdge(graph, 3, 4, 2);

    dijkstra(graph, 0);

    freeGraph(graph);
}

int main() {
    TestDijkstra();
    return 0;
}
