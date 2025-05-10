#include "BinSTree.h"
#include <stdlib.h>
#include <stdio.h>

/*Primitf*/

infotype GetAkar (BinTree P) {
    /* Mengirimkan informasi yang tersimpan di akar dari pohon Biner yg tdk kosong*/
    return Info(P);
} 

BinTree GetLeft (BinTree P) {
    /* Mengirimkan anak kiri pohon biner P yang TIDAK kosong */
    return Left(P);
} 

BinTree GetRight (BinTree P) {
    return Right(P);
}

/*Konstruktor*/

address Alokasi (infotype X) {
    address P = (address) malloc(sizeof(Node));
    if (P != Nil) {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
} 

BinTree Tree (infotype Akar, BinTree L, BinTree R) {
   
    address P = Alokasi(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
} /* Tree */
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P) {
    
    address Q = Alokasi(Akar);
    if (Q != Nil) {
        Left(Q) = L;
        Right(Q) = R;
        *P = Q;
    } else {
        *P = Nil;
    }
} /* MakeTree */



/** Predikat Penting */
boolean IsUnerLeft (BinTree P) {
   
    return ((P != Nil) && (Right(P) == Nil));
} /* IsUnerLeft */

boolean IsUnerRight (BinTree P) {
   
    return ((P != Nil) && (Left(P) == Nil));
} /* IsUnerRight */

boolean IsBiner (BinTree P) {
    
    return ((P != Nil) && (Left(P) != Nil) && (Right(P) != Nil));
} /* IsBiner */

boolean IsEmpty (BinTree P) {
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
