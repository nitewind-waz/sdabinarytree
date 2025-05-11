#include "BinSTree.h"


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


/*Primitif*/

infotype GetAkar (BinTree P) {
    return Info(P);
}

BinTree GetLeft (BinTree P) {
    return Left(P);
} 

BinTree GetRight (BinTree P) {
    return Right(P);
}

/*Konstruktor*/

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
}



/** Predikat Penting */
boolean IsUnerLeft (BinTree P) {
   
    return ((P != Nil) && (Right(P) == Nil));
} /* IsUnerLeft */

boolean IsUnerRight (BinTree P) {
   
    return ((P != Nil) && (Left(P) == Nil));
} /* IsUnerRight */

boolean IsBiner (BinTree P) {
    
    return ((P != Nil) && (Left(P) != Nil) && (Right(P) != Nil));
} 

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

void LevelOrder(BinTree P) {
    int d = Depth(P);
    for (int i = 1; i <= d; i++) {
        PrintLevel(P, 1, i);
    }
    printf("\n");
}

void PrintLevel(BinTree P, int currentLevel, int targetLevel) {
    if (P == Nil) return;

    if (currentLevel == targetLevel) {
        printf("%c ", Info(P));
    } else {
        PrintLevel(Left(P), currentLevel + 1, targetLevel);
        PrintLevel(Right(P), currentLevel + 1, targetLevel);
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

boolean Search (BinTree P, infotype X) {
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
} 


/*Fungsi Lain*/
int nbElmt (BinTree P) {
    int count = 0;
    if (P != Nil) {
        count = 1 + nbElmt(GetLeft(P)) + nbElmt(GetRight(P));
    }
    return count;
} 

int nbDaun (BinTree P) {
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

int Depth (BinTree P) {
    if (P == Nil) {
        return 0;
    }
    int dL = Depth(Left(P));
    int dR = Depth(Right(P));
    if (dL > dR) {
        return 1 + dL;
    } else {
        return 1 + dR;
    }
}

void SistemInput (BinTree *P){
    char root, input, arah;
    boolean broot;

    for (;;) {
        if ((*P) == Nil) {
            printf("Masukkan info untuk root: ");
            scanf(" %c", &input);
            *P = Tree(input, Nil, Nil);
            continue; 
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

BinTree BuildMorseTree() {
    // Level 6
    BinTree lima = Tree('5', Nil, Nil);
    BinTree empat = Tree('4', Nil, Nil);
    BinTree tiga = Tree('3', Nil, Nil);
    BinTree dua = Tree('2', Nil, Nil);
    BinTree spasi = Tree(' ', Nil, Nil);
    BinTree satu = Tree('1', Nil, Nil);
    BinTree enam = Tree('6', Nil, Nil);
    BinTree tujuh = Tree('7', Nil, Nil);
    BinTree delapan = Tree('8', Nil, Nil);
    BinTree sembilan = Tree('9', Nil, Nil);

    // Level 5
    BinTree H = Tree('H', lima, empat);
    BinTree V = Tree('V', Nil, tiga);
    BinTree F = Tree('F', Nil, Nil);
    BinTree kosong1 = Tree('\0', Nil, dua);
    BinTree L = Tree('L', Nil, Nil);
    BinTree kosong2 = Tree('\0', spasi, Nil);
    BinTree P = Tree('P', Nil, Nil);
    BinTree J = Tree('J', Nil, satu);
    BinTree B = Tree('B', Nil, enam);
    BinTree X = Tree('X', Nil, Nil);
    BinTree C = Tree('C', Nil, Nil);
    BinTree Y = Tree('Y', Nil, Nil);
    BinTree Z = Tree('Z', tujuh, Nil);
    BinTree Q = Tree('Q', Nil, Nil);
    BinTree nol = Tree('0', delapan, Nil);
    BinTree kosong3 = Tree('\0', sembilan, Nil);

    // Level 4
    BinTree S = Tree('S', H, V);
    BinTree U = Tree('U', F, kosong1);
    BinTree R = Tree('R', L, kosong2);
    BinTree W = Tree('W', P, J);
    BinTree D = Tree('D', B, X);
    BinTree K = Tree('K', C, Y);
    BinTree G = Tree('G', Z, Q);
    BinTree O = Tree('O', nol, kosong3);

    // Level 3
    BinTree I = Tree('I', S, U);
    BinTree A = Tree('A', R, W);
    BinTree N = Tree('N', D, K);
    BinTree M = Tree('M', G, O);

    // Level 2
    BinTree E = Tree('E', I, A);
    BinTree T = Tree('T', N, M);

    // Root
    return Tree('\0', E, T);
}



