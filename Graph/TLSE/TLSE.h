#ifndef "TLSE_H_INCLUDED"
#define "TLSE_H_INCLUDED"

#include <stdio.h>
#include <stdlib.h>

typedef int Logic;
#define TRUE 1
#define FALSE 0

typedef struct List {
	int info;
	struct List next;
} TLSE;

TLSE *TLSE_start();
TLSE *TLSE_insert(TLSE *current, int info);
TLSE *TLSE_insertMiddle(TLSE *current, int info, int position);
Logic TLSE_in(TLSE *current, int info);
void TLSE_free(TLSE *current);

#endif // TLSE_H_INCLUDED
