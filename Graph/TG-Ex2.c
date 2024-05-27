Logic DFS(TG *graph, int x, int y, TLSE **visited, TLSE **path) {
    if (x == y) {
        *path = TLSE_insert(*path, y);
        return TRUE;
    }

    *visited = TLSE_insert(*visited, x);

    TG *vertex = TG_vertexSearch(graph, x);
    if (vertex == NULL) return FALSE;

    NB *neighbor = vertex->firstNB;
    while (neighbor != NULL) {
        if (!TLSE_search(*visited, neighbor->id) {
            if (DFS(graph, neighbor->id, y, *visited, *path) {
                *path = TLSE_insert(*path, neighbor->id);
                return TRUE;
            }
        }
        neighbor = neighbor->next;
    }

    return FALSE;
}

TLSE *TG_findPath(TG *graph, int x, int y) {
    TLSE *visited = TLSE_start();
    TLSE *path = TLSE_start();
    if (DFS(graph, x, y, &visited, &path)) {
        TLSE_free(visited);
        return path;
    } else {
        TLSE_free(visited);
        TLSE_free(path);
    }
    return NULL;
}
