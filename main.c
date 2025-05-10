#include <stdio.h>
#include "BinSTree.h"
#include "BinSTree.c"

int main() {
    BinTree T, L, R;
    int info;
    // Buat subtree kiri dan kanan
    MakeTree(2, Nil, Nil, &L);  // node kiri
    MakeTree(3, Nil, Nil, &R);  // node kanan
    MakeTree(4, Nil, Nil, &L->right);
    MakeTree(5, Nil, Nil, &L->left);
    MakeTree(6, Nil, Nil, &R->right);
    MakeTree(7, Nil, Nil, &R->left);
    MakeTree(8, Nil, Nil, &L->left->left);

    // Buat pohon utama
    MakeTree(1, L, R, &T);

    // Cek hasil pohon dengan preorder traversal
    printf("Hasil traversal preorder:\n");
    PrintTree(T, 0);  // Output: 1 2 3
    
    // PreOrder(T);
    // InOrder(T);
    // PostOrder(T);    
    return 0;
}

