#include "BinSTree.h"
#include <malloc.h>

address Alokasi (infotype X){
    address P = (address)malloc(sizeof(Node));
    if(P != Nil){
        P->info = X;
        P->left = Nil;
        P->right = Nil;
    }else{
        printf("Alokasi gagal!!");
        return Nil;
    }
    return P;
}

BinTree Tree (infotype Akar, BinTree L, BinTree R){
    address P = Alokasi(Akar);
    if(P != Nil){
        P->right = R;
        P->left = L;
    }else{
        printf("Alokasi gagal!!!");
        return Nil;
    }
    return P;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P){
    address X = Tree(Akar, L, R);
    if(X != Nil){
        (*P) = X;
    }else{
        printf("Alokasi gagal!!!");
    }
}

void PrintTree(BinTree P, int h) {
    if (P != Nil) {
        PrintTree(Right(P), h + 1);
        for (int i = 0; i < h; i++) {
            printf("   ");  
        }
        printf("%d\n", Info(P));
        PrintTree(Left(P), h + 1);
    }
}

void PreOrder (BinTree P){
    // Jenis Penelusuran : Pre Order
    // Kunjungan : Parent, Left, Right 
    if(P != Nil){
        printf("%d ", P->info);
        PreOrder(P->left);
        PreOrder(P->right);
    }
}


void InOrder (BinTree P){
    // Jenis Penelusuran : In Order
    // Kunjungan : Left, Parent, Right
    if(P != Nil){
        if(P->left != Nil){
            InOrder(P->left);
            printf("%d ", P->info);
            InOrder(P->right);
        }else{
            printf("%d ",P->info);
        }
    }
}

void PostOrder (BinTree P){
    // Jenis Penelusuran : Post Order
    // Kunjungan : Left, Right, Parent
    if(P != Nil){
        if(P->left != Nil){
            PostOrder(P->left);
            PostOrder(P->right);
            printf("%d ",P->info);
        }else{
            printf("%d ",P->info);
        }
    }
}

boolean Search (BinTree P, infotype X) {
    if (P == Nil) return false;
    if (P->info == X) return true;
    return Search(P->left, X) || Search(P->right, X);
}

int nbElmt (BinTree P){
    if (P == Nil) {
        return 0;
    } else {
        return 1 + nbElmt(P->left) + nbElmt(P->right);
    }
}

int nbDaun(BinTree P) {
    if (P == Nil) {
        return 0;
    } else if (P->left == Nil && P->right == Nil) {
        return 1;
    } else {
        return nbDaun(P->left) + nbDaun(P->right);
    }
}

int Depth(BinTree P) {
    if (P == Nil) {
        return 0;
    } else {
        int leftDepth = Depth(P->left);
        int rightDepth = Depth(P->right);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
}

int Level(BinTree P, infotype X) {
    if (P == Nil) {
        return 0; 
    }

    if (P->info == X) {
        return 1; 
    }

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
