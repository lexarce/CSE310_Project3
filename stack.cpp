/* Alexis Arce
ASU ID: 1230700200*/

#include <cstdio>
#include <cstdlib>
#include "stack.h"

// Create new stack node
pSTACK_NODE createStackNode(pVERTEX vertex) {
    pSTACK_NODE newNode;
    newNode = (pSTACK_NODE) malloc(sizeof(STACK_NODE));
    if (newNode) {
        newNode->vertex = vertex;
        newNode->next = nullptr;
    }
    return newNode;
}

// Push vertex onto stack
void push(pSTACK_NODE *top, pVERTEX vertex) {
    pSTACK_NODE newNode = createStackNode(vertex);
    if (newNode) {
        newNode->next = *top;
        *top = newNode;
    }
}

// Pop vertex from stack
pVERTEX pop(pSTACK_NODE *top) {
    if (*top == nullptr) return nullptr;
    pSTACK_NODE tempNode = *top;
    pVERTEX vertex = tempNode->vertex;
    *top = tempNode->next;
    free(tempNode);
    return vertex;
}