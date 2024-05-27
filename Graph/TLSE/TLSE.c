#include "TLSE.h"

TLSE *TLSE_start() {
	return NULL;
}

TLSE *TLSE_insert(TLSE *current, int info) {
	TLSE *new = (TLSE*) malloc(sizeof(TLSE));
	new->info = info;
	new->next = current;
	return new;
}

TLSE *TLSE_insertMiddle(TLSE *current, int info, int position) {
	if (!current || position == 0) {
		TLSE *new = insertStart(current, info);
		return new;
	}

	if (position > 1) {
		current->next = insertMiddle(current->next, info, position - 1);
	}

	return current;
}

Logic TLSE_in(TLSE *current, int info) {
	if (!current) return FALSE;
	while (current != NULL) {
		if (current->info == info) return TRUE;
		current = current->next;
	}
	return FALSE;
}

void TLSE_free(TLSE *current) {
	while (current) {
		TLSE *aux = current;
		current = current->next;
		free(aux);
	}
}
