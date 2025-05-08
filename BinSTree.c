#include "BinSTree.h"
#include <stdlib.h>
#include <stdio.h>


/** Predikat Penting */
boolean IsUnerLeft (BinTree P) {
    /* Mengirimkan true jika BinTree tidak kosong */
    /* P adalah pohon UnerLeft (hanya mempunyai sub pohon kiri */
    return ((P != Nil) && (Right(P) == Nil));
} /* IsUnerLeft */

boolean IsUnerRight (BinTree P) {
    /* Mengirimkan true jika BinTree tidak kosong */
    /* P adalah pohon UnerRight (hanya mempunyai sub pohon kanan */
    return ((P != Nil) && (Left(P) == Nil));
} /* IsUnerRight */

boolean IsBiner (BinTree P) {
    /* Mengirimkan true jika BinTree tidak kosong */
    /* P adalah pohon Biner (mempunyai sub pohon kiri dan sub pohon kanan */
    return ((P != Nil) && (Left(P) != Nil) && (Right(P) != Nil));
} /* IsBiner */

boolean IsEmpty (BinTree P) {
    /* Mengirimkan true jika BinTree KOSONG */
    return (P == Nil);
} /* IsEmpty */

/*Traversal*/

void PreOrder (BinTree P) {
    if (P != Nil) {
        printf("%c ", GetAkar(P));
        PreOrder(GetLeft(P));
        PreOrder(GetRight(P));
    }
}

void InOrder (BinTree P) {
    if (P != Nil) {
        InOrder(GetLeft(P));
        printf("%c ", GetAkar(P));
        InOrder(GetRight(P));
    }
} /* InOrder */

void PostOrder (BinTree P) {
    if (P != Nil) {
        PostOrder(GetLeft(P));
        PostOrder(GetRight(P));
        printf("%c ", GetAkar(P));
    }
} /* PostOrder */