#include "Convertor.h"
#include "BinSTree.h"

int main(){
    /* Kamus Lokal */
    BinTree Tree;
    int selector;
    
    /* Program */
    MakeTree('-', Nil, Nil, &Tree);
    for (;;) {
        system("cls");
        printf("1. Input datan\n2. Preorder\n3. Selesai\n====>");scanf("%d", &selector);
        switch (selector) {
            case 1:
                SistemInput (&Tree);
                break;
            case 2:
                PreOrder(Tree);
                getchar();getchar();
                break;
            case 3:
            break;
            return 0;
        }        
    }

    return 0;
}