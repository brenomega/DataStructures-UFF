Logic canBecomeBinaryTree(TG *graph, TLSE *list, int *span, int *length) {
    if (!graph) return TRUE;
    
    int count = 0;
    NB *neighbor = graph->firstNB;
    while (neighbor != NULL) {
        TLSE *node = list;
        if (node != NULL)
            while (node->info != neighbor->id) node = node->next;
        if (node == NULL) {
            TLSE_insert(list, neighbor->id);
            ++count;
            ++*length;
            if (count > 2) return FALSE;
            neighbor = neighbor->next;
        }
        return FALSE;
    }
    ++*span;
    
    return canBecomeBinaryTree(graph->next, nodes);
}

Logic TG_canBecomeBinaryTree(TG *graph) {
    TLSE *list = TLSE_start();
    int span = 0;
    int length = 0;
    Logic logic = canBecomeBinaryTree(graph, list, &span, &length);
    TLSE_free(list);
    if (logic && (span - length == 1)) return TRUE;
    return FALSE;
}
