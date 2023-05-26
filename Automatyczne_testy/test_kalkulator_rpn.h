#ifndef TEST_KALKULATOR_RPN_H
#define TEST_KALKULATOR_RPN_H
#include <stdio.h>
#include <stdlib.h>

/*Autor: Kacper Wiącek
  Data utworzenia pliu: 22.01.2021r. godz. 16:00
  Wersja do testów*/

/***************************************************/
/* Plik test_kalkulator_rpn.h identyczny niemal jak*/
/* plik kalkulator_rpn.h lecz do testów została    */
/* dokonana zamiana funkcji wykonaj_program na     */
/* funckje automatyczne_testy                      */
/***************************************************/

typedef struct stos {
    int dane; 
    struct stos *nastepny; 
}t_stos; 

/*Nagłówek funkcji automatyczne_testy*/
void automatyczne_testy(t_stos *,FILE *);

int size(t_stos *);
void init(t_stos **); 
void push(t_stos **,int );
void pop(t_stos **);


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