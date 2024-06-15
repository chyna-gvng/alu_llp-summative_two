#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int line;
    struct Node* next;
} Node;

typedef struct {
    int numNodes;
    Node** adjLists;
    int* visited;
} Graph;

Node* createNode(int line) {
    Node* newNode = malloc(sizeof(Node));
    newNode->line = line;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    graph->adjLists = malloc(numNodes * sizeof(Node*));
    graph->visited = malloc(numNodes * sizeof(int));
    
    for (int i = 0; i < numNodes; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->line;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int numNodes = 59;  // Adjusting the number of nodes
    Graph* graph = createGraph(numNodes);

    // Adding edges based on the connections defined in the graph.dot file
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 10);
    addEdge(graph, 10, 11);
    addEdge(graph, 11, 12);
    addEdge(graph, 12, 13);
    addEdge(graph, 13, 14);
    addEdge(graph, 14, 15);
    addEdge(graph, 15, 16);
    addEdge(graph, 16, 17);
    addEdge(graph, 17, 18);
    addEdge(graph, 18, 19);
    addEdge(graph, 19, 20);
    addEdge(graph, 20, 21);
    addEdge(graph, 21, 22);
    addEdge(graph, 22, 23);
    addEdge(graph, 23, 24);
    addEdge(graph, 24, 25);
    addEdge(graph, 25, 26);
    addEdge(graph, 26, 27);
    addEdge(graph, 27, 28);
    addEdge(graph, 28, 29);
    addEdge(graph, 29, 30);
    addEdge(graph, 30, 31);
    addEdge(graph, 31, 32);
    addEdge(graph, 32, 33);
    addEdge(graph, 33, 34);
    addEdge(graph, 34, 35);
    addEdge(graph, 35, 36);
    addEdge(graph, 36, 37);
    addEdge(graph, 37, 38);
    addEdge(graph, 38, 39);
    addEdge(graph, 39, 40);
    addEdge(graph, 40, 41);
    addEdge(graph, 41, 42);
    addEdge(graph, 42, 43);
    addEdge(graph, 43, 44);
    addEdge(graph, 44, 45);
    addEdge(graph, 45, 46);
    addEdge(graph, 46, 47);
    addEdge(graph, 47, 48);
    addEdge(graph, 48, 49);
    addEdge(graph, 49, 50);
    addEdge(graph, 50, 51);
    addEdge(graph, 51, 52);
    addEdge(graph, 52, 53);
    addEdge(graph, 53, 54);
    addEdge(graph, 54, 55);
    addEdge(graph, 55, 56);
    addEdge(graph, 56, 57);
    addEdge(graph, 57, 58);
    addEdge(graph, 58, 59);

    DFS(graph, 1);  // Starting the DFS from node 1

    for (int i = 0; i < numNodes; i++) {
        free(graph->adjLists[i]);
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return 0;
}
