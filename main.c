#include "Convertor.h"
#include "BinSTree.h"

int main(){
    /* Kamus Lokal */
    BinTree P;
    List L;
    char oneofinput;
    
    /* Program */
    CreateList(&L);
    BuildTree(&P);
    
    printf("Masukkan karakter yang ingin dicari: ");
    scanf("%c", &oneofinput);
    
    StringToMorse(P, oneofinput, &L);
    
    
    
    return 0;
}