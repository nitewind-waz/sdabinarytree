#include "Convertor.h"



void CreateList (List *L) {
    /* I.S. L sembarang */
    /* F.S. L terdefinisi, dengan elemen pertama = Nil */
    L->first = NULL;
}

void InsVFirst (List *L, char X) {
    /* I.S. L terdefinisi, X terdefinisi */
    /* F.S. elemen pertama L adalah X */
    address2 P = (address2) malloc(sizeof(Nodestack));
    if (P != NULL) {
        P->info = X;
        P->next = L->first;
        L->first = P;
    }
}

boolean StringToMorse(BinTree P, char target, List *L) {
    if (P == Nil) return false;

    if (GetAkar(P) == target) {
        return true;
    }

    // Rekursi ke kiri: morse '.'
    if (StringToMorse(Left(P), target, L)) {
        InsVFirst(L, '.'); 
        return true;
    }

    // Rekursi ke kanan: morse '-'
    if (StringToMorse(Right(P), target, L)) {
        InsVFirst(L, '-'); 
        return true;
    }

    return false; 
}

void PrintList(List L) {
    address2 P = L.first;
    while (P != NULL) {
        printf("%c", P->info); 
        P = P->next;
    }
}

char MorseToChar(BinTree Tree, const char *morse) {
    BinTree current = Tree;
    int i = 0;
    while(morse[i] != '\0'){
        if (morse[i] == '.') {
            current = current->left;
        } else if (morse[i] == '-') {
            current = current->right;
        } else {
            return '?'; 
        }
        if (current == Nil) {
            return '?'; 
        }
        i++;
    }
    return current->info;
}

void MorseToString(BinTree Tree, const char *morseInput, char *output) {
    char morseLetter[10];
    int idx = 0, outIdx = 0;
    int i = 0;
    int len = strlen(morseInput); // Panjang array input
    int spaceCount = 0; // Hitungan menekan spasi
    while ( i <= len) {
        if (morseInput[i] == ' ' || morseInput[i] == '\0') {
            if (idx > 0) {  // Jika morseLetter sudah ada isinya
                morseLetter[idx] = '\0';
                char letter = MorseToChar(Tree, morseLetter);
                output[outIdx++] = letter;
                idx = 0;
            }

            // Hitung jumlah spasi berturut-turut
            spaceCount++;
            if (spaceCount == 3) {
                output[outIdx++] = ' ';  // Tambahkan spasi antar kata
                spaceCount = 0;          // Reset
            }
        } else {
            morseLetter[idx++] = morseInput[i];
            spaceCount = 0;
        }
        i++;
    }
    output[outIdx] = '\0';  // Akhiri string output
}