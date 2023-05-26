#include "kalkulator_rpn.h"
#include <stdio.h>
#include <stdlib.h>
/**********************************************************************************************/
/*Autor: Kacper Wiącek                                                                        */
/*Data utworzenia pliku kalkulator_rpn.c : 19.01.2021r.                                       */
/*Data ukończenia pliku : 21.01.2021r.                                                        */
/*Wersja ostateczna,                                                                          */
/*Modyfikacje: 1.Przygotowanie -> 19.01.2021r. około 17:00                                    */
/*             2.Praca nad funckjami kalkulatora -> 20.01.2021r. około 23:00                  */
/*             3.Poprawki,ulepszenia -> 21.01.2021r. około 20                                  */
/**********************************************************************************************/

/**********************************************************************************************/
/* Funkcja init iniciuje pusty stos -> ustawia wskaznik na NULL                               */
/* \param[in] wsk_stos -> wskaznik na wskaznik, który wskazuje na stos                        */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void init(t_stos **wsk_stos){
    *wsk_stos=NULL;  
}               
/**********************************************************************************************/
/* Funkcja push dodaje liczby na szczyt stosu                                                 */
/* \param[in] wsk_stos -> wskaznik na wskaznik, który wskazuje na początek stosu              */
/* \param[in] liczba -> liczba, którą mamy zamiar dodać do stosu                              */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void push(t_stos **wsk_stos, int liczba){
    if(*wsk_stos==NULL){    /*Gdy lista jest pusta nie potrzebujemy zmiennej pomocniczej*/
        *wsk_stos= (t_stos *) malloc (sizeof(t_stos));  
        if(*wsk_stos==NULL){ /*Jeżeli malloc zwróći NULL -> błąd przydzielenia pamięci*/
            fprintf(stderr,"Blad przydziału pamięci!!\n");
            free(*wsk_stos);
        } else { /*DOdajemy liczbę do stosu na sam szczyt*/
        (*wsk_stos)->dane=liczba;   
        (*wsk_stos)->nastepny=NULL;  /*Ustawiamy wskaznik na NULL WAŻNE!!*/
        }                           
    }else {  /*Gdy lista nie jest pusta inicujemy pomocniczą zmienną pom*/
        t_stos *pom = (t_stos *) malloc (sizeof(t_stos)); /*Alokacja nowej pamięci*/
        if(pom==NULL){  /*Zwrócenie błędu w przypadku niepowodzenia*/
            fprintf(stderr,"Błąd przydziału pamięci\n");
            free(pom);
        }else{ /*DOdawanie liczby*/
        pom->dane=liczba;  /*Ustawianie wskaznika następny na element poprzedni*/
        pom->nastepny=*wsk_stos; 
        *wsk_stos=pom;  /*LIsta(stos) teraz pokzauje na nową liczbę*/
        }
    }
}
/**********************************************************************************************/
/* Funkcja pop usuwa liczbę ze szczytu stosu                                                  */
/* \param[in] wsk_stos -> wskaznik na wskaznik, który wskazuje na początek stosu              */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void pop(t_stos **wsk_stos){ 
    if(*wsk_stos!=NULL){  /*SPrawdzamy czy stos nie jest pusty*/
        t_stos *pom = (*wsk_stos)->nastepny; /*Jeżeli nie -> usuwamy liczbę ze szczytu*/
        free(*wsk_stos); /*Zwalnianie pamięci "usuniętego" elementu*/
        *wsk_stos=pom;   /*Lista pokazuje na poprzedni element*/ /*pom zmienna pomocnicza*/
    }else{  /*Stos pusty? -> nie ma czego usuwać*/
        fprintf(stderr,"Stos jest pusty!\n ");
    }
}
/**********************************************************************************************/
/* Funkcja print wydruk liczby ze szczytu stosu                                               */
/* \param[in] wsk_stos ->  wskaznik, który wskazuje na początek stosu                         */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void print(t_stos *wsk_stos){ /*SPrawdzamy czy lista nie jest pusta*/
    if(wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!!\n");
    else printf("%d\n", wsk_stos->dane); /*Wypisujemy licizbę, na którą poakzuje wsk_stos */
}
/**********************************************************************************************/
/* Funkcja full_print wydruk wszystkich liczb ze stosu                                        */
/* \param[in] wsk_stos ->  wskaznik, który wskazuje na początek stosu                         */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void full_print(t_stos *wsk_stos){ /*Sprawdzenie czy stos nie jest pusty*/
    if(wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!!\n");
    else {  /*Zmienna pomocnicza */
        t_stos *pom = wsk_stos; 
        do{ /*Dopoki nie napotkamy NULL -> koniec stosu to drukujemy liczby, które są w stosie*/
            printf("%d", pom->dane);
            printf("\n");
            pom=pom->nastepny; /*Przechodzimy między kolenymi elementami stosu*/
        }while(pom != NULL); 
    }
}
/**********************************************************************************************/
/* Funkcja clear czyści wszytskie liczby ze stosu                                             */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void clear(t_stos **wsk_stos){ 
    if(*wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!\n"); /*SPrawdzenie czy stos pusty*/
    else {
        int liczba_elementow = size(*wsk_stos); /*Wywołanie funcji size, która zlicza wszystkie liczby na stosie*/
        while(liczba_elementow>0){   /*Tyle ile liczb -> tyle wywołaj funkcje pop -> usuwanie każdego elementu*/
            pop(wsk_stos);
            liczba_elementow--;
        }   /*PO zakończeniu stos jest pusty, wskaznik ma wartość NULL*/
    }
}
/**********************************************************************************************/
/* Funkcja riverse zamienia miejscami dwie pierwsze liczby ze stosu                           */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void reverse(t_stos **wsk_stos){
    if(*wsk_stos==NULL) fprintf(stderr,"Stos jest pusty\n"); /*Czy stos pusty?*/
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n"); 
    else {                                         /*Muszą być conajmniej dwie liczby w stosie*/
        t_stos *pom= (*wsk_stos)->nastepny; /*Zmienna pomocnicza*/
        int liczba1 = (*wsk_stos)->dane; /*Liczba1 zapisuje pierwszą liczbę ze stosu*/
        int liczba2= pom->dane;          /*Liczba2 zapisuje drugą liczbę ze stosu*/
        pop(wsk_stos);                 /*Usuwanie chwilowe tych dwóch elementów*/
        pop(wsk_stos); 
        push(wsk_stos,liczba1);      /*Dodanie najpierw liczba1 potem liczba2*/
        push(wsk_stos,liczba2);}    /*Tak nastąpiła "zamiana" miejscami*/
}
/**********************************************************************************************/
/* Funkcja duplication robi duplikat liczby ze szczytu stosu i dodaje na sam szczyt           */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/
void duplication(t_stos **wsk_stos){ /*Czy stos pusty?*/
    if(*wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!\n");
    else {  /*Duplikat -> tworzenie i dodanie do stosu*/
        int duplikat = (*wsk_stos)->dane;
        push(wsk_stos,duplikat);
    }
}
/**********************************************************************************************/
/* Funkcja addition dodaje dwa ostatnio dodane elementy do stosu, i zamiast nich zwraca       */
/* wynik dodawania na sam szczyt                                                              */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void addition(t_stos **wsk_stos){ /*Brak liczb brak wyniku*/
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                     /*Muszą być conajmniej dwie liczby w stosie*/
        t_stos *pom = (*wsk_stos)->nastepny;  /*Zmienna pomocnicza*/
        int liczba1 = (*wsk_stos)->dane;   /*liczba1 zapisuje element ze szczytu*/
        int liczba2= pom->dane;          /*Liczba2 zapisuje drugi element*/
        pop(wsk_stos);   /*Usuwanie liczb ze stosu*/
        pop(wsk_stos);
        push(wsk_stos,liczba1+liczba2);   /*DOdanie wyniku sumy dwóch liczb na sam szczyt*/
    }
}
/**********************************************************************************************/
/* Funkcja subtraction odejmuje dwa ostatnio dodane elementy do stosu(drugi od pierwszego)    */
/* i zamiast nich zwraca wynik różnicy na sam szczyt                                          */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void subtraction(t_stos **wsk_stos){  /*Brak liczb brak wyniku*/
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                      /*Muszą być conajmniej dwie liczby w stosie*/
        t_stos *pom = (*wsk_stos)->nastepny;  /*Zmienna pomocnicza*/
        int liczba1 = (*wsk_stos)->dane;  /*liczba1 zapisuje element ze szczytu*/
        int liczba2= pom->dane;  /*Liczba2 zapisuje drugi element*/
        pop(wsk_stos); /*Usuwanie liczb ze stosu*/
        pop(wsk_stos);
        push(wsk_stos,liczba2-liczba1); /*Dodanie wyniku różnicy dwóch liczb na sam szczyt*/
    }
}
/**********************************************************************************************/
/* Funkcja multiplication mnoży dwa ostatnio dodane elementy do stosu i zamiast nich          */
/* zwraca wynik iloczynu na sam szczyt                                                        */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void multiplication(t_stos **wsk_stos){  /*Brak liczb brak wyniku*/
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                          /*Muszą być conajmniej dwie liczby w stosie*/
        t_stos *pom = (*wsk_stos)->nastepny; /*Zmienna pomocnicza*/
        int liczba1 = (*wsk_stos)->dane; /*liczba1 zapisuje element ze szczytu*/
        int liczba2= pom->dane; /*Liczba2 zapisuje drugi element*/
        pop(wsk_stos); /*Usuwanie liczb ze stosu*/
        pop(wsk_stos);
        push(wsk_stos,liczba1*liczba2); /*Dodanie wyniku iloczynu dwóch liczb na sam szczyt*/
    }
}
/**********************************************************************************************/
/* Funkcja division dzieli dwa ostatnio dodane elementy(drugi przez pierwszy) do stosu        */
/* i zamiast nich zwraca wynik ilorazu na sam szczyt                                          */
/* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu             */
/* \param[out] brak -> funckja void nic nie zwraca                                            */
/**********************************************************************************************/

void division(t_stos **wsk_stos){  /*Brak liczb brak wyniku*/
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                       /*Muszą być conajmniej dwie liczby w stosie*/
        t_stos *pom = (*wsk_stos)->nastepny; /*Zmienna pomocnicza*/
        int liczba1 = (*wsk_stos)->dane; /*liczba1 zapisuje element ze szczytu*/
        int liczba2= pom->dane; /*Liczba2 zapisuje drugi element*/
        if(liczba1==0) fprintf(stderr,"Nie dzielimy przez zero!\n");/*MIanownik nie może się zerować*/
        else {
        pop(wsk_stos); /*Usuwanie liczb ze stosu*/
        pop(wsk_stos);
        push(wsk_stos,liczba2/liczba1);} /*Dodanie wyniku ilorazu dwóch liczb na sam szczyt*/
    }
}
/**********************************************************************************************/
/* Funkcja size pomocnicza funckja do zliczania ilości liczb w stosie                         */
/* \param[in] wsk_stos -> wskaznik, który wskazuje na początek stosu                          */
/* \param[out] licznik -> funckja int zwraca liczbę całkowitą -> ilość elementów w stosie     */                                            
/**********************************************************************************************/

int size(t_stos *wsk_stos){
    int licznik=0; /*Licznik zlicza liczby na stosie*/ 
    t_stos *pom = wsk_stos; /*Zmienna pomocnicza*/
    while(pom!=NULL){     /*Dopoki nie napotkamy koniec listy*/
        licznik++;       /*ZLiczamy liczbę elementów stosu*/
        pom=pom->nastepny;  /*Poruszay się po każdym elemencie*/
    }
    return licznik;  /*Zwróć ilość liczb na stosie*/
}
/*******************************************************************************************************/
/* Funkcja wykonaj_program wykonuje cały program -> wczytuje dane z stdin oraz wywoływuje inne funkcje */
/* \param[in] wsk_stos -> wskaznik, który wskazuje na początek stosu                                   */                                        
/*******************************************************************************************************/

void wykonaj_program(t_stos *stos){
    char znak,znak2; /*Zmienna znak wczytuje znak ze stdin*/ /*znak2 pomocnicza zmienna do wczytywania znaków*/
    int liczba; /*Zmienna liczba zapisuje liczbę z stdin, aby potem ją dodać do stosu*/

    init(&stos); /*Inicjacja pustego stosu*/

    do{   /*Wykonuj się dopóki znak!='q', który kończy program*/
        znak=getc(stdin);  /*Pobierz znak ze standardowego wejścia*/
        if((znak!=' ')&&(znak!='\t')&&(znak!='\n')){ /*spacja,tabulacja,enter muszą być pomijane*/
            switch(znak){  /*W zależności od wczytanego znaku wykonamy określone zadania*/
                case '+': {  
                    addition(&stos); /*Mamy wykonać dodawanie*/
                    break;
                }
                case '-': {  /*Wczytujemy kolejny znak,aby upewnić się czy wykonać odejmowanie bądź*/
                    znak=getc(stdin); /*Czy mamy dodać ujemną liczbę do stosu*/
                    if((znak<48)||(znak>57)) { /*Sprawdzamy czy obok minusa nie ma cyfry*/
                        ungetc(znak,stdin); /*Jeżeli nie ma liczby zwróć znak z powrotem*/
                        subtraction(&stos); /*Mamy wykonać odejmowanie*/
                    }
                    else { /*Jeżeli jest cyfra zwróć znak*/
                        ungetc(znak,stdin);
                        scanf("%d",&liczba); /*Pobierz liczbę aż do napotkania innego znaku niż cyfra*/
                        znak=getc(stdin);   /*Pobieramy kolejny znak aby upewnić się czy to liczba zmiennoprzecinkowa*/
                            switch(znak) {
                                case '.': { /*Jeżeli obok liczby jest kropka sprawdzamy czy za kropką jest znowu cyfra*/
                                    znak2=getc(stdin);
                                    if((znak2>=48)&&(znak2<=57)) {  /*Jeżeli tak, mamy liczbę z przecinkiem*/
                                        fprintf(stderr,"Błąd! Należy wczytać tylko liczby całkowite!\n"); /*Zakomunikowanie błędu*/
                                        ungetc(znak2,stdin); /*Zwrócenie znaku, który jest liczbą*/
                                        scanf("%d",&liczba); /*Pobranie wszytskich znaków za kropką, aby pozbyć się tej liczby*/
                                    }
                                    else { /*Jeżeli za kropką nie ma cyfry, mamy błędną opcję programu (znak '.' nie jest opcją)*/
                                        ungetc(znak2,stdin); /*Zwracamy znak z cyfrą*/
                                        ungetc(znak,stdin); /*Zwracamy kropkę, aby potem moć znów ją pobrać i wyrzucić błąd nieprawidłowej opcji*/
                                        push(&stos,(-1)*liczba); /*Dodanie ujemnej liczby do stosu*/
                                    }
                                    break;
                                }
                                default: { /*Gdy nie ma kropki dodajemy wcześniej wczytaną liczbę ujemną do stosu oraz zwracamy znak*/
                                    ungetc(znak,stdin);
                                    push(&stos,(-1)*liczba);
                                    break;
                                }
                            }
                    }
                    break;
                }
                case '*': {
                    multiplication(&stos); /*Mamy wykonać mnożenie*/
                    break;
                }
                case '/': {
                    division(&stos);  /*Mamy wykonać dzielenie*/
                    break;
                }                        
                case 'P': {
                    pop(&stos);    /*Usuwamy liczbę ze szczytu stosu*/
                    break;
                }
                case 'c': {
                    clear(&stos); /*Czyścimy cały stos*/
                    break;
                }
                case 'r': {
                    reverse(&stos); /*Zamieniamy miejscami dwie pierwsze liczby w stosie*/
                    break;
                }
                case 'd': {
                    duplication(&stos);  /*Duplikacja liczby ze szczytu stosu*/
                    break;
                }
                case 'p': {
                    print(stos);   /*Wydrukowanie liczby ze szczytu stosu*/
                    break;
                }
                case 'f': {
                    full_print(stos); /*Wydrukowanie wszystkich liczb ze stosu*/
                    break;
                }
                case 'q': {
                    free(stos); /*Koniec programu, zwalnianie pamięci*/
                    stos=NULL;
                    break;
                }
                default: {  /*Inne opcje mogą być cyframi bądź są nieprawidłowe*/
                    if((znak>=48)&&(znak<=57)) { /*Musimy sprawdzić czy mamy do czynienia z cyfrą*/
                        ungetc(znak,stdin); /*Zwracamy cyfrę*/
                        scanf("%d",&liczba); /*Wczytujemy wszystkie cyfry do napotkania innego znaku*/
                        znak=getc(stdin); /*Wczytujemy kolejny znak -> czy jest kropka to ważne*/
                            switch(znak){
                                case '.': { /*Jeżeli tak sprawdzamy czy za kropką jest kolejna cyfra*/
                                    znak2=getc(stdin);
                                    if((znak2>=48)&&(znak2<=57)) { /*Liczba zmiennoprzecinkowa -> zwróć błąd*/
                                        fprintf(stderr,"Błąd! Należy wczytać tylko liczby całkowite!\n");
                                        ungetc(znak2,stdin); /*Zwróć cyfrę*/
                                        scanf("%d",&liczba); /*Wczytaj całą liczbę za kropką*/
                                    }
                                    else { /*Nie ma cyfry to mamy nieprawdiłową opcję programu*/
                                        ungetc(znak2,stdin); /*Zwroć cyfrę*/
                                        ungetc(znak,stdin); /*Zwróć kropkę*/
                                        push(&stos,liczba); /*Dodaj dodatnią liczbę do stosu*/
                                    }
                                    break;
                                }
                                default: { /*Nie ma kropki to zwracamy kropkę i dodajemy wcześniej wczytaną liczbę do stosu*/
                                   ungetc(znak,stdin);
                                   push(&stos,liczba); 
                                   break;
                                }
                            } /*Jeżeli znak nie jest cyfrą, musi być nieprawidłowy -> zwróć błąd*/
                    }else fprintf(stderr,"Niepoprawna opcja!!\n");
                    break;
                }
            }
        }
    }while(znak!='q');
}


        

            
                      