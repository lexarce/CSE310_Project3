/* Alexis Arce
ASU ID: 1230700200*/

#include <cstdio>
#include <cstring>
#include "util.h"

int nextInstruction(char Word, double key) {
    int returnV;

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop") == 0) return 1;
    if (strcmp(Word, "PrintADJ") == 0) return 1;
    if (strcmp(Word, "SinglePair") == 0) {
        returnV = fscanf(stdin);
        if (returnV == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    if (strcmp(Word, "SingleSource") == 0) {
        returnV = fscanf(stdin);
        if (returnV == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    if (strcmp(Word, "PrintLength") == 0) {
        returnV = fscanf(stdin);
        if (returnV == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    if (strcmp(Word, "SinglePath") == 0) {
        returnV = fscanf(stdin);
        if (returnV == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    return 0;
}