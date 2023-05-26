#ifndef KALKULATOR_RPN_H
#define KALKULATOR_RPN_H

/*Struktura stosu*/
typedef struct stos {
    int dane;  /*przechowuje wartość elementu*/
    struct stos *nastepny;  /*wskaznik na następny element stosu*/
}t_stos; /*zmienna typu t_stos*/
 
/*Nagłówki funkcji do operacji na stosie*/

void init(t_stos **); 
void push(t_stos **,int );
int pop(t_stos **);
void empty(t_stos *);
void print(t_stos *);
int size(t_stos *);

#endif 