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
    if (P != Nil) {
        InOrder(GetLeft(P));
        printf("%c ", GetAkar(P));
        InOrder(GetRight(P));
    }
}

void PostOrder (BinTree P) {
    if (P != Nil) {
        PostOrder(GetLeft(P));
        PostOrder(GetRight(P));
        printf("%c ", GetAkar(P));
    }
}

void PrintTree (BinTree P, int h) {
    if (P != Nil) {
        PrintTree(Right(P), h + 1);
        for (int i = 0; i < h; i++) {
            printf("   ");  
        }
        printf("%c\n", Info(P));
        PrintTree(Left(P),h+1);
    }
}
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
    if (P == Nil)
        return 0;
    if (Left(P) == Nil && Right(P) == Nil)
        return 1;
    return nbDaun(Left(P)) + nbDaun(Right(P));
} /* nbDaun */

int Level (BinTree P, infotype X) {
    if (P == Nil) {
        return 0;
    }
    if (Info(P) == X) {
        return 1;
    }
    int leftLevel = Level(Left(P), X);
    if (leftLevel != 0) {
        return leftLevel + 1;
    }
    int rightLevel = Level(Right(P), X);
    if (rightLevel != 0) {
        return rightLevel + 1;
    }
    return 0;
}

void SistemInput (BinTree *P){
    char root, input, arah;
    boolean broot;

    for (;;) {
        if ((*P) == Nil) {
            // Jika pohon masih kosong, buat root
            printf("Masukkan info untuk root: ");
            scanf(" %c", &input);
            *P = Tree(input, Nil, Nil);
            continue; // kembali ke awal loop untuk input berikutnya
        }

        printf("\nMasukkan node yang ingin ditambahkan anaknya (atau ketik 0 untuk keluar): ");
        scanf(" %c", &root);

        if (root == '0') {
            printf("Selesai menginput.\n");
            break;
        }

        broot = Search(*P, root);
        if (broot == true) {
            BinTree curr = *P;

            while (curr != Nil && GetAkar(curr) != root) {
                if (Search(GetLeft(curr), root))
                    curr = GetLeft(curr);
                else
                    curr = GetRight(curr);
            }

            printf("Tambah anak ke kiri (l) atau kanan (r)? ");
            scanf(" %c", &arah);

            printf("Masukkan info anak baru: ");
            scanf(" %c", &input);

            if (arah == 'l') {
                if (Left(curr) == Nil) {
                    Left(curr) = Tree(input, Nil, Nil);
                } else {
                    printf("Node '%c' sudah punya anak kiri.\n", root);
                }
            } else if (arah == 'r') {
                if (Right(curr) == Nil) {
                    Right(curr) = Tree(input, Nil, Nil);
                } else {
                    printf("Node '%c' sudah punya anak kanan.\n", root);
                }
            } else {
                printf("Input arah tidak valid.\n");
            }
        } else {
            printf("Node '%c' tidak ditemukan di pohon.\n", root);
        }
    }
}