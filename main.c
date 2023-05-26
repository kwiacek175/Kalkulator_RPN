#include <stdio.h>
#include <stdlib.h>
#include "kalkulator_rpn.h"

/**********************************************************************************************/
/*Autor: Kacper Wiącek                                                                        */
/*Data utworzenia pliku main.c : 19.01.2021r.                                                 */
/*Data ukończenia pliku : 21.01.2021r.                                                        */
/*Wersja ostateczna,                                                                          */
/*Modyfikacje: 1.Przygotowanie -> 19.01.2021r. około 17:00                                    */
/*             2.Praca nad interfejsem -> 20.01.2021r. około 20:00                            */
/*             3.Poprawki,ulepszenia -> 21.01.2021r. około 22                                 */
/**********************************************************************************************/

/***********************************************************************************************/
/* PLik main.c jest głównym plikiem programu, w którym iniciujemy strukturę stosu oraz         */
/* wywołujemy funkcję wykonaj program, która wczytuje dane ze standardowego wejścia, oraz      */
/* wykonuje operacje na stosie,kalkulatorze do momentu napotkania znaku 'q'                    */
/* Poza podstawowymi operacjami matematycznymi program operuje na stosie.                      */
/* Możemy duplikować(d), drukować(p),usuwać(P), liczbę ze szczytu stosu. Ponadto jest opcja    */
/* wyczyszczenia całej zawartości(c) ze stosu bądź jej wydrukowanie(f).Operacja reverse        */
/* zamienia dwa pierwsze elementy miejsacmi.                                                   */
/*                                                                                             */
/* Program działa na zasadzie pobierania zanków ze stdin i na ich podstawie wykonuje określone */
/* działania.Wyrzuca błędy z każdym niepożądanym przypadkiem, Korzystamy z dynamicznej alokacji*/
/* pamięci, podziału na moduły w celu uporządkowania kodu źródłowego.                          */                                                                                  
/*                                                                                             */                                                                                                                                                                            
/* Dane wejściowe: liczby całkowite, bądź następujące znaki:'q','r','d','p','P','f','c','+','-'*/
/*'*','/'                                                                                      */
/*Dane wyjściowe: Wynik operacji dodawania,odejmowania,mnożenia,dzielenia dla liczb pobranych z*/ 
/* stdin,Program zwraca wartość zero na zakończenie (return 0)                                 */
/***********************************************************************************************/

int main(){
    t_stos *stos; /*Inicjacja zmiennej typu wskaznik na stos*/
    wykonaj_program(stos); /*Wywoływanie funkcji wykonaj_program jak i wywoływanie całego programu*/
    return 0; /*Gdy wszystko dobrze zwróć kod 0 brak błędów*/
}