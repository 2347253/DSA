#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// BFT
void breadthFirstTraversal(int graph[][5], int start, int vertices) {
	int i;
    bool visited[vertices];
    for ( i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    int queue[vertices];
    int front = -1, rear = -1;

    visited[start] = true;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for ( i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

// DFT
void depthFirstTraversal(int graph[][5], int start, int vertices, bool visited[]) {
    int i;
	visited[start] = true;
    printf("%d ", start);

    for ( i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            depthFirstTraversal(graph, i, vertices, visited);
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int vertices = 5;
    int i;

    printf("Breadth-First Traversal: ");
    breadthFirstTraversal(graph, 0, vertices);

    printf("\nDepth-First Traversal: ");
    bool visited[vertices];
    for ( i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    depthFirstTraversal(graph, 0, vertices, visited);

    return 0;
}

