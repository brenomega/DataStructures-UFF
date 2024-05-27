#ifndef TG_H_INCLUDED
#define TG_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"

typedef struct Neighbor {
    int id;
    struct Neighbor *next;
} NB;

typedef struct Graph {
    int id;
    struct NB *firstNB;
    struct Graph *next;
} TG;

TG *TG_start();
TG *TG_vertexSearch(TG *graph, int id);
NB *TG_edgeSearch(TG *graph, int v1, int v2);
TG *TG_vertexInsert(TG *graph, int id);
TG *TG_edgeInsert(TG *graph, int v1, int v2);
TG *TG_vertexRemove(TG *graph, int id);
TG *TG_edgeRemove(TG *graph, int v1, int v2);
TG *TG_print(TG *graph);

#endif // TG_H_INCLUDED
