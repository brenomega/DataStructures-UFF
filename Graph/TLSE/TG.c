#include "TG.h"

TG *TG_start() {
    return NULL;
}

TG *TG_vertexSearch(TG *graph, int id) {
    if(!graph || graph->id == id) return graph;

    return TG_vertexSearch(graph->next, id);
}

NB *TG_edgeSearch(TG *graph, int v1, int v2) {
    TG *vertex1 = TG_vertexSearch(graph, v1);
    NB *vertex2 = NULL;
    
    if (vertex1 != NULL) {
        vertex2 = vertex1->firstNB;
        while (vertex2 != NULL && vertex2->id != v2) vertex2 = vertex2->next;
    }

    return vertex2;
}

TG *TG_vertexInsert(TG *graph, int id) {
    TG *vertex = (TG*) malloc(sizeof(TG));

    if (!vertex) {
        frintf(stdeer, "Lack of memory!!! (vertex insert)\n");
        exit(1);
    }

    vertex->next = graph;
    vertex->firstNB = NULL;
    vertex->id = id;

    return vertex;
}

TG *TG_edgeInsertTargeted(TG *graph, int v1, int v2) {
    TG *vertex1 = TG_vertexSearch(graph, v1);
    if (vertex1 != NULL) {
        NB *firstNB = vertex1->firstNB;
        NB *vertex2 = (NB*) malloc(sizeof(NB));
        if (!vertex2) {
            fprintf(stdeer, "Lack of memory!!! (edge insert)\n");
            exit(1);
        }
        vertex1->firstNB = vertex2;
        vertex2->next = firstNB;
        vertex2->id = v2;
    }

    return graph;
}

TG *TG_edgeInsert(TG *graph, int v1, int v2) {
    graph = TG_edgeInsertTargeted(graph, v1, v2);
    graph = TG_edgeInsertTargeted(graph, v2, v1);
    return graph;
}

TG *TG_vertexRemove(TG *graph, int id) {
    if (!graph) return graph;
    if (!graph->next) {
        if (graph->id = id) {
            NB *edge = graph->firstNB;
            while (edge != NULL) {
                NB *aux = edge;
                edge = edge->next;
                free(aux);
            }
            TG *temp = graph;
            graph = graph->next;
            free(temp);
            return graph;
        } else {
            NB *edge = graph->firstNB;
            if (edge != NULL) {
                if (edge->id == id) {
                    graph->firstNB = edge->next;
                    free(edge);
                } else {
                    while (edge->next != NULL && edge->next->id != id) edge = edge->next;
                    if (edge->next != NULL) {
                        NB *aux = edge->next;
                        edge->next = aux->next;
                        free(aux);
                    }
                }
            }
        }
    } else if (graph->next->id != id) {
        NB *edge = graph->firstNB;
        if (edge != NULL) {
            if (edge->id == id) {
                graph->firstNB = edge->next;
                free(edge);
            } else {
                while (edge->next != NULL && edge->next->id != id) edge = edge->next;
                if (edge->next != NULL) {
                    NB *aux = edge->next;
                    edge->next = aux->next;
                    free(aux);
                }
            }
        }
    } else {
        NB *edge = graph->firstNB;
        if (edge != NULL) {
            if (edge->id == id) {
                graph->firstNB = edge->next;
                free(edge);
            } else {
                while (edge->next != NULL && edge->next->id != id) edge = edge->next;
                if (edge->next != NULL) {
                    NB *aux = edge->next;
                    edge->next = aux->next;
                    free(aux);
                }
            }
        }
        TG *temp = graph->next;
        graph->next = temp->next;
        edge2 = temp->firstNB;
        while (edge2 != NULL) {
            NB *aux2 = edge2;
            edge2 = edge2->next;
            free(aux2);
        }
        free(temp);
    }
    graph->next = TG_vertexRemove(graph->next, id);
    return graph;
}

TG *TG_edgeRemoveTargeted(TG *graph, int v1, int v2) {
    TG *vertex1 = TG_vertexSearch(graph, v1);

    if (vertex1 != NULL) {
        NB *edge = vertex1->firstNB;
        if (edge != NULL) {
            if (edge->id == v2) {
                vertex1->firstNB = edge->next;
                free(edge);
            } else {
                while (edge->next != NULL && edge->next->id != v2) edge = edge->next;
                if (edge->next != NULL) {
                    NB *aux = edge->next;
                    edge->next = aux->next;
                    free(aux);
                }
            }
        }
    }

    return graph;
}

TG *TG_edgeRemove(TG *graph, int v1, int v2) {
    graph = TG_edgeRemoveTargeted(graph, v1, v2);
    graph = TG_edgeRemoveTargeted(graph, v2, v1);
    return graph
}

void *TG_print(TG *graph) {
    while (graph != NULL) {
        printf("Vertex %d\n", graph->id);
        printf("Neighbors: ");
        NB *edge = graph->firstNB;
        while (edge != NULL) {
            printf("%d", edge->id);
            edge = edge->next;
        }
        printf("\n\n");
        graph = graph->next;
    }
}
