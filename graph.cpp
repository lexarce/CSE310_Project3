/* Alexis Arce
ASU ID: 1230700200*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include "graph.h"
#include "heap.h"
#include "data_structures.h"

void PrintADJ(NODE **adjacencyList, int numVertices) {
    for (int i = 1; i <= numVertices; ++i) {
        printf("ADJ[%d]:", i);
        NODE *current = adjacencyList[i];
        while (current != nullptr) {
            printf("-->[%d %d: %4.2lf]", current->index, current->endV, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

void InitializeSingleSource(VERTEX **vertices, int numVertices, int source) {
    for (int i = 1; i <= numVertices; ++i) {
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = 0; // Assuming 0 is used to represent NIL
        vertices[i]->position = i; // Position in the heap array if needed
    }
    vertices[source]->key = 0;
}

void Relax(VERTEX *u, VERTEX *v, double weight, HEAP *minHeap) {
    if (v->key > u->key + weight) {
        v->key = u->key + weight;
        v->pi = u->index;
        DecreaseKey(minHeap, v->position, v->key); // Update the vertex's position in the heap
    }
}

// Dijkstra's algorithm for a single pair (source to destination)
void DijkstraSP(VERTEX **vertices, NODE **adjacencyList, HEAP *minHeap, int numVertices, int source, int destination) {
    InitializeSingleSource(vertices, numVertices, source);
    BuildMinHeap(minHeap, vertices, numVertices); // Build the initial min heap

    while (minHeap->size > 0) {
        VERTEX *u = ExtractMin(minHeap); // Extract vertex with smallest key value
        if (u->index == destination) {
            break; // If the destination is reached, the shortest path is found
        }

        NODE *node = adjacencyList[u->index];
        while (node != nullptr) {
            VERTEX *v = vertices[node->endV];
            Relax(u, v, node->weight, minHeap);
            node = node->next;
        }
    }
}

// Dijkstra's algorithm for a single source to all other vertices
void DijkstraST(VERTEX **vertices, NODE **adjacencyList, HEAP *minHeap, int numVertices, int source) {
    InitializeSingleSource(vertices, numVertices, source);
    BuildMinHeap(minHeap, vertices, numVertices); // Build the initial min heap

    while (minHeap->size > 0) {
        VERTEX *u = ExtractMin(minHeap); // Extract vertex with smallest key value

        NODE *node = adjacencyList[u->index];
        while (node != nullptr) {
            VERTEX *v = vertices[node->endV];
            Relax(u, v, node->weight, minHeap);
            node = node->next;
        }
    }
}

void PrintLength(VERTEX **vertices, int s, int t) {
    if (vertices[s]->key != DBL_MAX && vertices[t]->pi != 0) {
        printf("The shortest path from %d to %d is: %8.2lf\n", s, t, vertices[t]->key);
    } else {
        printf("There is no path from %d to %d.\n", s, t);
    }
}

void PrintPath(VERTEX **vertices, int s, int t) {
    if (vertices[t]->pi == 0) {
        printf("There is no path from %d to %d.\n", s, t);
    } else {
        std::stack<int> path;
        int current = t;
        while (current != s && current != 0) {
            path.push(current);
            current = vertices[current]->pi;
        }
        if (current == 0) {
            printf("There is no path from %d to %d.\n", s, t);
        } else {
            printf("The shortest path from %d to %d is: ", s, t);
            printf("%d", s); // Start with the source
            while (!path.empty()) {
                printf("-->%d", path.top());
                path.pop();
            }
            printf("\n");
        }
    }
}