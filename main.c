#include "BinSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char A = 'A';
    char B = 'B';
    char C = 'C';

    // Modul Tree //
    address p = Tree(C, Nil, Nil);
    address q = Tree(B, Nil, Nil);
    BinTree tree1 = Tree(A, q, p);
    printf("%c ", tree1->info);           
    printf("%c ", tree1->left->info);     
    printf("%c \n\n", tree1->right->info);    

    // Modul MakeTree //
    BinTree T, L, R;
    MakeTree('B', Nil, Nil, &L);
    MakeTree('C', Nil, Nil, &R);
    MakeTree('A', L, R, &T);
    printf("%c ", T->info);       
    printf("%c ", T->left->info); 
    printf("%c \n", T->right->info);

    // Implementasi (penggabungan keduanya) //
    BinTree akar, kiri, kanan;
    MakeTree(B, Nil, Nil, &kiri);
    MakeTree(C, Nil, Nil, &kanan);
    akar = Tree(A, kiri, kanan);
    printf("\n %c \n", akar->info);
    printf("/ \\");;
    printf("\n%c ", akar->left->info);
    printf("%c \n", akar->right->info);
    
    // Implementasi transversal //
    PreOrder(tree1);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(akar);
    printf("\n");

    // Lain-lain //
    if (Search(tree1, A))
    {
        printf("Ada\n");
    } else {
        printf("Tidak ada\n");
    }
    printf("%d", Level(akar, C));

    free(tree1);
    free(T);
    free(akar);
    return 0;
}