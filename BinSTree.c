#include "BinSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

address Alokasi (infotype X) {
    address P = (Node *)malloc(sizeof(Node));
    if (P != NULL)
    {
        P->info = X;
        P->left = Nil;
        P->right = Nil;
    } else {
        printf("ALokasi gagal.");
    }
    
    return P;
}
BinTree Tree (infotype Akar, BinTree L, BinTree R) {
    address P = Alokasi(Akar);
    if (P != Nil)
    {
        P->info = Akar;
        P->left = L;
        P->right = R;
    } else {
        printf("Tidak bisa membuat tree.\n");
    }
    
}
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Alokasi(Akar);
    if (*P != Nil)
    {
        (*P)->info = Akar;
        (*P)->left = L;
        (*P)->right = R;
    } else {
        printf("Tidak bisa membuat tree.\n");
    }
}
void BuildTree (BinTree *P) {

}