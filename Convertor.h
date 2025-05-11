#include "binstree.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node *address2;
typedef struct Node {
    char info;
    address2 next;
} Nodestack;

typedef struct {
    address2 first;
} List;

/*Konstruktor*/
void CreateList (List *L);
/* I.S. L sembarang */

/* F.S. L terdefinisi, dengan elemen pertama = Nil */
void InsVFirst (List *L, char X);
/* I.S. L terdefinisi, X terdefinisi */

boolean StringToMorse (BinTree P, char target, List * L);

void SearchInTraversal (BinTree P, char oneofinput);

void PrintList (List L);

char MorseToChar(BinTree Tree, const char *morse);

void MorseToString(BinTree Tree, const char *morseInput, char *output);