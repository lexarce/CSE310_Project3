/* Alexis Arce
ASU ID: 1230700200*//

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H
#include "data_structures.h"

void InitializeSingleSource(VERTEX **vertices, int numVertices, int source);
void Relax(VERTEX *u, VERTEX *v, double weight, HEAP *minHeap);
void DijkstraSP(VERTEX **vertices, NODE **adjacencyList, HEAP *minHeap, int numVertices, int source, int destination);
void DijkstraST(VERTEX **vertices, NODE **adjacencyList, HEAP *minHeap, int numVertices, int source);
void PrintADJ(NODE **adjacencyList, int numVertices);
void PrintLength(VERTEX **vertices, int s, int t);
void PrintPath(VERTEX **vertices, int s, int t);

#endif //PROJECT3_GRAPH_H
