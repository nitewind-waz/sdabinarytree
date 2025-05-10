#include "Convertor.h"



void CreateList (List *L) {
    /* I.S. L sembarang */
    /* F.S. L terdefinisi, dengan elemen pertama = Nil */
    L->first = NULL;
}

void InsVFirst (List *L, char X) {
    /* I.S. L terdefinisi, X terdefinisi */
    /* F.S. elemen pertama L adalah X */
    address2 P = (address2) malloc(sizeof(Nodestack));
    if (P != NULL) {
        P->info = X;
        P->next = L->first;
        L->first = P;
    }
}

boolean StringToMorse(BinTree P, char target, List *L) {
    if (P == Nil) return false;

    if (GetAkar(P) == target) {
        return true;
    }

    // Rekursi ke kiri: morse '.'
    if (StringToMorse(Left(P), target, L)) {
        InsVFirst(L, '.'); 
        return true;
    }

    // Rekursi ke kanan: morse '-'
    if (StringToMorse(Right(P), target, L)) {
        InsVFirst(L, '-'); 
        return true;
    }

    return false; 
}

void PrintList(List L) {
    address2 P = L.first;
    while (P != NULL) {
        printf("%c", P->info); 
        P = P->next;
    }
}