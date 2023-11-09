/* Alexis Arce
ASU ID: 1230700200*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "data_structures.h"
#include "heap.h"
#include "stack.h"
#include "graph.h"
#include "util.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <InputFile> <GraphType> <Flag>\n", argv[0]);
        exit(0);
    }

    int returnV, numVertices, numEdges, startU, endV, edgeIndex, flag;
    double weight, key;
    char Word[100];
    flag = atoi(argv[3]);

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
        exit(0);
    }

    fscanf(file, "%d %d", &numVertices, &numEdges);
    VERTEX **V = (VERTEX **)(calloc(numVertices + 1, sizeof(VERTEX *)));
    NODE **ADJ = (NODE **)(calloc(numVertices + 1, sizeof(NODE *)));

    // Initialize vertices and adjacency lists
    for (int i = 1; i <= numVertices; ++i) {
        V[i] = (VERTEX *)(calloc(1, sizeof(VERTEX)));
        ADJ[i] = nullptr;
    }

    // Read edges and populate adjacency lists
    for (int i = 0; i < numEdges; ++i) {
        fscanf(file, "%d %d %d %lf", &edgeIndex, &startU, &endV, &weight);
        NODE *newNodeU = (NODE *)(calloc(1, sizeof(NODE)));
        newNodeU->index = edgeIndex;
        newNodeU->startU = startU;
        newNodeU->endV = endV;
        newNodeU->weight = weight;
        // For directed graph or undirected graph with flag 1, insert at front
        if (flag == 1) {
            newNodeU->next = ADJ[startU];
            ADJ[startU] = newNodeU;
            if (strcmp(argv[2], "undirected") == 0) {
                NODE *newNodeV = (NODE *)calloc(1, sizeof(NODE));
                *newNodeV = *newNodeU;
                newNodeV->startU = endV;
                newNodeV->endV = startU;
                newNodeV->next = ADJ[endV];
                ADJ[endV] = newNodeV;
            }
        } else {
            // Insert at the rear for directed graph or undirected graph with flag 2
            NODE **ptr = &ADJ[startU];
            while (*ptr) {
                ptr = &((*ptr)->next);
            }
            *ptr = newNodeU;
            if (strcmp(argv[2], "undirected") == 0) {
                NODE *newNodeV = (NODE *)calloc(1, sizeof(NODE));
                *newNodeV = *newNodeU;
                newNodeV->startU = endV;
                newNodeV->endV = startU;
                ptr = &ADJ[endV];
                while (*ptr) {
                    ptr = &((*ptr)->next);
                }
                *ptr = newNodeV;
            }
        }
    }
    fclose(file);

    // Initialize min-heap and stack
    HEAP *minHeap = (HEAP *)(calloc(1, sizeof(HEAP)));
    minHeap->capacity = numVertices;
    minHeap->size = 0;
    minHeap->H = (pELEMENT *)(calloc(numVertices + 1, sizeof(VERTEX *)));

    STACK *stack = calloc(1, sizeof(STACK));
    stack->capacity = numVertices;
    stack->top = NULL;

    // Instructions loop
    while (1) {
        returnV = nextInstruction(Word, &key);

        if (returnV == 0) {
            fprintf(stderr, "Invalid instruction.\n");
            continue;
        }

        if (strcmp(Word, "Stop") == 0) {
            return 0;
        }

        if (strcmp(Word, "PrintADJ") == 0) {
            PrintADJ(ADJ, numVertices);
            continue;
        }

        if (strcmp(Word, "SinglePair") == 0) {
            int source, destination;
            // You would need to capture source and destination from stdin or another input
            DijkstraSP(V, ADJ, minHeap, numVertices, source, destination);
            continue;
        }

        if (strcmp(Word, "SingleSource") == 0) {
            int source;
            // Capture source from stdin or another input
            DijkstraST(V, ADJ, minHeap, numVertices, source);
            continue;
        }

        if (strcmp(Word, "PrintLength") == 0) {
            int s, t;
            // Capture s and t from stdin or another input
            PrintLength(V, s, t);
            continue;
        }

        if (strcmp(Word, "PrintPath") == 0) {
            int s, t;
            // Capture s and t from stdin or another input
            PrintPath(V, s, t);
            continue;
        }
    }
    // Free the allocated memory before exiting
    for (int i = 1; i <= numVertices; ++i) {
        free(V[i]);
        NODE *current = ADJ[i];
        while (current) {
            NODE *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(V);
    free(ADJ);
    free(minHeap->H);
    free(minHeap);
    while (stack->top) {
        NODE *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    free(stack);

    return 1;
}
