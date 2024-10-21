#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// returns an array of length nV containing the shortest
// distance between src and each vertex.
// For an undirected, unweighted graph.
int *findShortestDistance(Graph g, int src) {
    Queue q = QueueNew();
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    int *distance = calloc(GraphNumVertices(g), sizeof(int));

    visited[src] = true;
    QueueEnqueue(q, src);
    while (!QueueIsEmpty(q)) {
        int v = QueueDequeue(q);

        for (int w = 0; w < GraphNumVertices(g); w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                visited[w] = true;
                distance[w] = distance[v] + 1;
                QueueEnqueue(q, w);
            }
        }
    }

    QueueFree(q);
    free(visited);

    return distance;
}
