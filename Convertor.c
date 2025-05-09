#include "Convertor.h"

#include <stdio.h>

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

void StringToMorse (BinTree P, char oneofinput, List * L) {
    if (P != Nil) {
        if (oneofinput == GetAkar(P)){

        } else {
            InsVFirst(L, '-');
            StringToMorse (Left(P), oneofinput, L);
            InsVFirst(L, '.');
            StringToMorse (Right(P), oneofinput, L);
        }
    }
}

void SearchInTraversal (BinTree P, char oneofinput){
    if (P != NULL){
        
    }
}