#include "kalkulator_rpn.h"
#include <stdio.h>
#include <stdlib.h>

/*Funkcja iniciuj -> Iniciuje pusty stos*/
void init(t_stos **wsk_stos){
    *wsk_stos=NULL; /*Ustawiamy wskaznik na stos = NULL*/
}                   /*Lsta pusta*/


/*Funkcja push -> dodaje element na szczyt stosu*/
void push(t_stos **wsk_stos, int elem){
    if(*wsk_stos==NULL){    /*Sprawdzamy czy lista nie jest pusta*/
        *wsk_stos= (t_stos *) malloc (sizeof(t_stos));   /*Alokujemy pamięć aby dodać nowy element*/
        if(*wsk_stos!=NULL){   /*Jeżeli malloc zwróci pamięć prawidłowo*/
        (*wsk_stos)->dane=elem;   /*Dodajemy element do zmiennej dane*/
        (*wsk_stos)->nastepny=NULL; /*Wskaznik na następny element stosu = NULL*/
        }                           /*STos się tutaj kończy*/
    }else {  /*Gdy stos nie jest pusty potrzebujemy pomocniczej zmiennej*/
        t_stos *pom = (t_stos *) malloc (sizeof(t_stos)); /*Alokacja nowej pamięci do zmiennej pomocniczej*/
        if(pom!=NULL){  /*Jeżeli pamięć przydzielono prawidłowo -> malloc nie zwróci NULL*/  
        pom->dane=elem; /*Dodajemy nowy element */
        pom->nastepny=*wsk_stos; /*Wskaznik ustawiamy na poprzedni element stosu*/
        *wsk_stos=pom;  /*Początek listy wskazuje na nowy element stosu*/
        }
    }
}

/*Funkcja pop - > Usuwanie elementu ze szczytu stosu*/
int pop(t_stos **wsk_stos){
       int result = -1; /*Zmienna zwraca blad -1 badz wartość usniętego elementu*/
    if(*wsk_stos!=NULL){  /*Jeżeli lista nie jest pusta element zostanie usnięty*/
        result = (*wsk_stos)->dane;  
        t_stos *pom = (*wsk_stos)->nastepny; /*Inicjacja zmiennej pomocniczej,wskaznik pokazuje na element drugi licząc od szczytu stosu*/
        free(*wsk_stos); /*Zwalnianie pamięci, ktora przechowuje usuniety element*/
        *wsk_stos=pom;   /*Stos pokazuje teraz na element drugi, który jest teraz na szczycie*/
        return result;   /*Zwróc element usunięty*/
    }else{ /*Gdy lista jest pusta nue ma czego usuwać*/
        printf("Stos jest pusty! Nie mozna niczego usunac!\n ");
        return result;
    }
}

/*Funckja empty -> Sprawdza czy stos jest pusty lub nie*/
void empty(t_stos *wsk_stos){
    if(wsk_stos==NULL){
        printf("Stos jest pusty!\n");
    }
    else printf("STos nie jest pusty!\n");
}

/*Funkcja print -> Wyświetla elementy stosu na standardowe wyjście*/
void print(t_stos *wsk_stos){
    /*Gdy nie ma elementów -> wyświetla się komunikat*/
    if(wsk_stos==NULL) printf("Stos jest pusty!!");
    else {
        t_stos *pom = wsk_stos; /*Inicjacja zmiennej pomoczniczej*/
        do{
            printf("%d", pom->dane);
            printf("\n");
            pom=pom->nastepny;
        }while(pom != NULL); /*Wyświetlanie elementów od początku, do napotkania końca listy*/
    }
}

/*Funkcja size -> zwraca liczbę elementów znajdujących się na stosie*/
int size(t_stos *wsk_stos){
    int licznik=0;  /*Zmienna licznik zlicza elementy*/
    t_stos *pom = wsk_stos; /*Zmienna pomocnicza*/
    while(pom!=NULL){     
        licznik++;   /*Zliczanie tak długo, aż napotkamy koniec stosu*/
        pom=pom->nastepny;
    }
    return licznik; 
}