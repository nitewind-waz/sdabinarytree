
#include "BinSTree.h"
#include "Convertor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Kamus Lokal */
    BinTree Tree = BuildMorseTree();
    List Test;
    int selector, decision;
    char input, search1, search2;

    
    /* Program */
    CreateList(&Test);
    
    while (selector != 12 ){
        printf("\n===== MENU BINARY TREE =====\n");
        printf("1. Insert node\n2. Print Tree\n3. Transversal PreOrder\n4. Transversal InOrder\n5. Transversal PostOrder\n6. Transversal LevelOrder\n");
        printf("7. Search Node Tree\n8. Jumlah Daun / Leaf\n9. Mencari Kedalaman Node Tree\n10. Membandingkan 2 Node Tree\n11. Char to Morse\n12. Exit\n");
        printf("Pilih menu: ");
        scanf(" %d", &selector);

        switch (selector) {
            case 1:
                SistemInput (&Tree);
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 2:
              if (IsEmpty(Tree)) {
                    printf("Tree masih kosong.\n");
                } else {
                    PrintTree(Tree, 0);

                }
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 3:
                printf("PreOrder: ");
                PreOrder(Tree);
                printf("\n");
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 4:
                printf("InOrder: ");
                InOrder(Tree);
                printf("\n");
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 5:
                printf("PostOrder: ");
                PostOrder(Tree);
                printf("\n");
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 6:
                if (IsEmpty(Tree)) {
                    printf("Tree masih kosong.\n");
                } else {
                    // Level Order //
                }
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 7:
                printf("Masukkan info node yang dicari: ");
                scanf(" %c", &input);
                if (Search(Tree, input))
                    printf("Node '%c' ditemukan.\n", input);
                else
                    printf("Node '%c' tidak ditemukan.\n", input);
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 8:
                printf("Jumlah daun (leaf): %d\n", nbDaun(Tree));
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 9:
                printf("Masukkan node yang ingin dicari kedalamannya: ");
                scanf(" %c", &input);
                if (Search(Tree, input)) {
                    int lvl = Level(Tree, input);
                    printf("Node '%c' berada di level %d\n", input, lvl);
                } else {
                    printf("Node '%c' tidak ditemukan.\n", input);
                }
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
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
                            printf("\n1.kembali\nMasukkan Pilihan : ");
            scanf("%d", &decision);
            if(decision == 1){
                break;
            }
            case 11:
                char yangdikonvert[100];
                printf("Masukkan string yang mau dikonvert: ");
                scanf("%s", yangdikonvert);  // baca string dari input

                for (int i = 0; yangdikonvert[i] != '\0'; i++) {
                    Test.first = NULL; // reset list sebelum mengisi morse baru

                    if (StringToMorse(Tree, yangdikonvert[i], &Test)) {
                        PrintList(Test);
                        printf(" ");
                    } else {
                        printf("Huruf '%c' tidak ditemukan di pohon.\n", yangdikonvert[i]);
                    }
                }
                getchar(); getchar();
            break;
                
            default:
                printf("Menu tidak valid.\n");
            return 0;
        }
    }

    return 0;

}