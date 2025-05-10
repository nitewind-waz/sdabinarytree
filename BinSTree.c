#include "BinSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Konstruktor //
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

// Predikat Penting //
boolean IsEmpty (BinTree P) {
    return (P == Nil);
}

// Transversal //
void PreOrder (BinTree P) {
    if (P != NULL) {
        printf("%c ", P->info);       
        PreOrder(P->left);            
        PreOrder(P->right);           
    }
}

void InOrder (BinTree P) {
    if (P != NULL) {
        InOrder(P->left);
        printf("%c ", P->info);
        InOrder(P->right);
    }
}

void PostOrder (BinTree P) {
    if (P != NULL) {
        PostOrder(P->left);
        PostOrder(P->right);
        printf("%c ", P->info);
    }
}
void PrintTree (BinTree P, int h) {

}

// Lain-Lain //
boolean Search (BinTree P, infotype X) {
    if (P == NULL) {
        return false;
    } else if (P->info == X) {
        return true;
    } else {
        return Search(P->left, X) || Search(P->right, X);
    }
}
int nbElmt (BinTree P) {

}
int nbDaun (BinTree P) {

}
int Level (BinTree P, infotype X) {
    if (P == NULL) {
        return 0;
    } else if (P->info == X) {
        return 1;
    } else {
        int leftLevel = Level(P->left, X);
        if (leftLevel > 0) {
            return leftLevel + 1;
        }
        int rightLevel = Level(P->right, X);
        if (rightLevel > 0) {
            return rightLevel + 1;
        }
        return 0;
    }
}
int Depth (BinTree P) {

}