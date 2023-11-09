/* Alexis Arce
ASU ID: 1230700200*/

#ifndef PROJECT3_DATA_STRUCTURES_H
#define PROJECT3_DATA_STRUCTURES_H

// Data structure for graph vertices
enum COLOR { WHITE, GRAY, BLACK};

typedef struct TAG_VERTEX {
    int index;
    COLOR color;
    double key;
    int pi;
    int position;
}VERTEX;
typedef VERTEX *pVERTEX;

// Data structure for nodes on adjacency list of graph
typedef struct TAG_NODE {
    int index;
    int startU;
    int endV;
    double weight;
    TAG_NODE *next;
}NODE;
typedef NODE *pNODE;

// Data structure for min-heap
typedef VERTEX ELEMENT;
typedef ELEMENT *pELEMENT;
typedef struct TAG_HEAP {
    int capacity;
    int size;
    pELEMENT *H;
}HEAP;
typedef HEAP *pHeap;

// Data structure for stack
typedef struct TAG_STACK_NODE {
    pVERTEX vertex;
    struct TAG_STACK_NODE *next;
}STACK_NODE, *pSTACK_NODE;

#endif //PROJECT3_DATA_STRUCTURES_H
