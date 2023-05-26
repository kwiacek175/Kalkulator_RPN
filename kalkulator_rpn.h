#ifndef KALKULATOR_RPN_H
#define KALKULATOR_RPN_H

/**********************************************************************************************/
/*Autor: Kacper Wiącek                                                                        */
/*Data utworzenia pliku kalkulator_rpn.h : 19.01.2021r.                                       */
/*Data ukończenia pliku : 21.01.2021r.                                                        */
/*Wersja ostateczna,                                                                          */
/*Modyfikacje: 1.Przygotowanie -> 19.01.2021r. około 17:00                                    */
/*             2.Dodanie nagłówek funkcji dla obsługi kalkulatora -> 20.01.2021r. około 19:00 */
/*             3.Poprawki -> 21.01.2021r. około 21                                            */
/**********************************************************************************************/

/**********************************************************************************************/
/* Plik kalkulator_rpn.h zawiera nagłówki do wszystkich funkcji w programie oraz istotną      */
/* strukturę stosu w postaci dynamicznej listy jednokoierunkowej. Każda funkcja zostaje       */
/* wywoływana z argumentem w postaci albo wskaznikna na wskażnik, który wskazuje na listę,    */
/* bądź odrazu ze wskaznikiem na listę (funckja size, print, full_print).PLik został dołączony*/          
/* do dwóch plików main.c oraz kalkulator_rpn.c, aby kompilacja zachodziła prawidłowo.        */
/**********************************************************************************************/

/*Struktura stosu dla kalkulatora*/
typedef struct stos {
    int dane;  /*Przechowujemy tutaj liczbę całkowitą*/
    struct stos *nastepny;  /*Wskaznik na następną strukturę stos*/
}t_stos; /*Zmienna typu t_stos*/

/*Nagłówek funkcji, która jest główną funkcją w programie*/
/*Wczytuje dane i wywołuje wszystkie inne funkcje programu*/
void wykonaj_program(t_stos *);

/*Nagłówki funkcji do operacji na stosie*/
int size(t_stos *);
void init(t_stos **); 
void push(t_stos **,int );
void pop(t_stos **);

/*Nagłówki funkcji do operacji na kalkulatorze(stosie)*/
void clear(t_stos **);
void reverse(t_stos **);
void duplication(t_stos **);
void full_print(t_stos *);
void print(t_stos *);
void addition(t_stos **);
void subtraction(t_stos **);
void multiplication(t_stos **);
void division(t_stos **);

#endif 