#include "binstree.h"
#include <stdlib.h>

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

void StringToMorse (BinTree P, char oneofinput, List * L);

void SearchInTraversal (BinTree P, char oneofinput);

