#include <stdio.h>
#include <stdlib.h>
#include "test_kalkulator_rpn.h"

/* Autor Wiącek Kacper 
 Data utworzenia pliku: 22.01.2021r. godz. 17:00
 Wersja do testowania funkcji programu i przypadków szczególnych */

/*********************************************************************/
/* Plik testy.c zawiera główną funkcje main, która wywoływuje funkcje*/
/* automatyczne_testy w pętli 10 razy(mamy 10 testów). PLik powstał  */
/* tylko i wyłącznie na potrzeby testów programu.                    */
/*                                                                   */
/*********************************************************************/

int main(){
    t_stos *stos; 
    FILE *plik=fopen("plik_testowy.txt","r"); /*Zmienna plikowa, czyta z pliku plik_testowy.txt*/
    init(&stos); 
   
    for(int i=1; i<=10; i++){ /*Wywołanie 10 razy funkcji -> 10 testów*/
    automatyczne_testy(stos,plik);
    }

   fclose(plik); /*Zamykamy plik, kończymy testy*/
   return 0;
}