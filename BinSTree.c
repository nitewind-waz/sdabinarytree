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

/*Search*/

boolean Search (BinTree P, infotype X) {
    /* Mencari X pada BinTree P */
    /* Mengirimkan true jika ada node dari P yang bernilai X */
    boolean found = false;
    if (P != Nil) {
        if (GetAkar(P) == X) {
            found = true;
        } else {
            found = Search(GetLeft(P), X);
            if (!found) {
                found = Search(GetRight(P), X);
            }
        }
    }
    return found;
} /* Search */


/*Fungsi Lain*/
int nbElmt (BinTree P) {
    /* Mengirimkan banyak elemen (node) pohon biner P */
    int count = 0;
    if (P != Nil) {
        count = 1 + nbElmt(GetLeft(P)) + nbElmt(GetRight(P));
    }
    return count;
} /* nbElmt */

int nbDaun (BinTree P) {
    /* Mengirimkan banyak daun (node) pohon biner P */
    
} /* nbDaun */