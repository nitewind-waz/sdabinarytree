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
    BinTree akar, pki, liberal;
    MakeTree(B, Nil, Nil, &pki);
    MakeTree(C, Nil, Nil, &liberal);
    akar = Tree(A, pki, liberal);
    printf("\n %c \n", akar->info);
    printf("/ \\");;
    printf("\n%c ", akar->left->info);
    printf("%c ", akar->right->info);    
    return 0;
}