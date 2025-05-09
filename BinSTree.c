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
    int selector;
    char root, input;
    boolean broot;
    if (GetLeft(P) == Nil && GetRight(P) == Nil){
        printf("L/R?"); scanf("%c", input);
        if (input = 'l'){
            printf("Masukkan info dari left: "); scanf("%c", &input);
        }
        else if (input = 'r') {
            printf("Masukkan info dari right: "); scanf("%c", &input);
        }
        else {
            printf("inputan tidak valid\n");
            return;
        }
    } 
    else {
        printf("Masukkan root yang akan diinput r/l nya! ");scanf("%c", &root);
        broot =  Search(P, root);
        if (broot == true) {
            for (;;) {
                printf("1. Kanan\n2. Kiri\n3. Ga Jadi\n-->" ); scanf("%d", &selector);
                switch (selector) {
                    case 1:
                        printf("Masukkan info: "); scanf("%c", &input);
                        (*P)->right->info = input;
                        break;
                    case 2:
                        printf("Masukkan info: "); scanf("%c", &input);
                        (*P)->left->info = input;
                        break;
                    case 3 
                }
            }
        }
    }
}