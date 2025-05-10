
#include "BinSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Kamus Lokal */
    BinTree Tree;
    int selector;
    char input, search1, search2;

    
    /* Program */
    MakeTree('-', Nil, Nil, &Tree);
    while (selector != 11 ){
        printf("\n===== MENU BINARY TREE =====\n");
        printf("1. Insert node\n2. Print Tree\n3. Transversal PreOrder\n4. Transversal InOrder\n5. Transversal PostOrder\n6. Transversal LevelOrder\n");
        printf("7. Search Node Tree\n8. Jumlah Daun / Leaf\n9. Mencari Kedalaman Node Tree\n10. Membandingkan 2 Node Tree\n11. Exit\n");
        printf("Pilih menu: ");
        scanf(" %d", &selector);

        switch (selector) {
            case 1:
                SistemInput (&Tree);
                break;
            case 2:
              if (IsEmpty(Tree)) {
                    printf("Tree masih kosong.\n");
                } else {
                    PrintTree(Tree, 2);
                }
                break;
            case 3:
                printf("PreOrder: ");
                PreOrder(Tree);
                printf("\n");
                break;
            case 4:
                printf("InOrder: ");
                InOrder(Tree);
                printf("\n");
                break;
            case 5:
                printf("PostOrder: ");
                PostOrder(Tree);
                printf("\n");
                break;
            case 6:
                if (IsEmpty(Tree)) {
                    printf("Tree masih kosong.\n");
                } else {
                    // Level Order //
                }
                break;
            case 7:
                printf("Masukkan info node yang dicari: ");
                scanf(" %c", &input);
                if (Search(Tree, input))
                    printf("Node '%c' ditemukan.\n", input);
                else
                    printf("Node '%c' tidak ditemukan.\n", input);
                break;
            case 8:
                printf("Jumlah daun (leaf): %d\n", nbDaun(Tree));
                break;
            case 9:
                printf("Masukkan node yang ingin dicari kedalamannya: ");
                scanf(" %c", &input);
                if (Search(Tree, input)) {
                    int lvl = Level(Tree, input);
                    printf("Node '%c' berada di level %d\n", input, lvl);
                } else {
                    printf("Node '%c' tidak ditemukan.\n", input);
                }
                break;
                case 10:
                printf("Masukkan node pertama: ");
                scanf(" %c", &search1);
                printf("Masukkan node kedua: ");
                scanf(" %c", &search2);
                if (!Search(Tree, search1) || !Search(Tree, search2)) {
                    printf("Salah satu atau kedua node tidak ditemukan.\n");
                } else {
                    int l1 = Level(Tree, search1);
                    int l2 = Level(Tree, search2);
                    if (l1 < l2)
                        printf("Node '%c' lebih dekat ke akar daripada '%c'\n", search1, search2);
                    else if (l2 < l1)
                        printf("Node '%c' lebih dekat ke akar daripada '%c'\n", search2, search1);
                    else
                        printf("Kedua node berada di level yang sama (%d)\n", l1);
                }
                break;
            case 11:
                break;
            default:
                printf("Menu tidak valid.\n");
            return 0;
        }
    }

    return 0;

}