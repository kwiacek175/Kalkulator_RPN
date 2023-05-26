#include "test_kalkulator_rpn.h"
#include <stdio.h>
#include <stdlib.h>
#define DL_KOMENTARZY 100 /*Na potrzebę testów, do wczytywania komentarzy z pliku testowego*/

/*Autor: Kacper Wiącek*/
/*Data utworzenia pliku: 22.01.2021r. godz. 15:00*/
/*Wersja do testów*/

/*******************************************************************************************************************/
/*PLik test_kalkulator_rpn.c został utworzony i zmodyfikowany z pliku kalkulator_rpn.c na potrzeby testów          */
/*FUnckje nie zostały zmienione, lecz zamiast funkcji wykonaj_program, który pobierał dane z standardowego wejścia,*/
/*mamy funckje automatyczne_testy, która  wczytuje i sprawdza działanie kalkulatora z wcześniej przygtowanego pliku*/
/*plik_testowy.txt                                                                                                 */
/*******************************************************************************************************************/

void init(t_stos **wsk_stos){
    *wsk_stos=NULL;  
}               

void push(t_stos **wsk_stos, int liczba){
    if(*wsk_stos==NULL){    
        *wsk_stos= (t_stos *) malloc (sizeof(t_stos));  
        if(*wsk_stos==NULL){ 
            fprintf(stderr,"Blad przydziału pamięci!!\n");
            free(*wsk_stos);
        } else { 
        (*wsk_stos)->dane=liczba;   
        (*wsk_stos)->nastepny=NULL;  
        }                           
    }else {  
        t_stos *pom = (t_stos *) malloc (sizeof(t_stos)); 
        if(pom==NULL){  
            fprintf(stderr,"Błąd przydziału pamięci\n");
            free(pom);
        }else{
        pom->dane=liczba; 
        pom->nastepny=*wsk_stos; 
        *wsk_stos=pom;  
        }
    }
}
void pop(t_stos **wsk_stos){ 
    if(*wsk_stos!=NULL){  
        t_stos *pom = (*wsk_stos)->nastepny; 
        free(*wsk_stos); 
        *wsk_stos=pom;  
    }else{  
        fprintf(stderr,"Stos jest pusty!\n ");
    }
}

void print(t_stos *wsk_stos){ 
    if(wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!!\n");
    else printf("%d\n", wsk_stos->dane); 
}

void full_print(t_stos *wsk_stos){
    if(wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!!\n");
    else { 
        t_stos *pom = wsk_stos; 
        do{ 
            printf("%d", pom->dane);
            printf("\n");
            pom=pom->nastepny; 
        }while(pom != NULL); 
    }
}

void clear(t_stos **wsk_stos){ 
    if(*wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!\n"); 
    else {
        int liczba_elementow = size(*wsk_stos); 
        while(liczba_elementow>0){   
            pop(wsk_stos);
            liczba_elementow--;
        }   
    }
}
void reverse(t_stos **wsk_stos){
    if(*wsk_stos==NULL) fprintf(stderr,"Stos jest pusty\n"); 
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n"); 
    else {                                         
        t_stos *pom= (*wsk_stos)->nastepny; 
        int liczba1 = (*wsk_stos)->dane; 
        int liczba2= pom->dane;         
        pop(wsk_stos);               
        pop(wsk_stos); 
        push(wsk_stos,liczba1);      
        push(wsk_stos,liczba2);}    
}

void duplication(t_stos **wsk_stos){ 
    if(*wsk_stos==NULL) fprintf(stderr,"Stos jest pusty!\n");
    else { 
        int duplikat = (*wsk_stos)->dane;
        push(wsk_stos,duplikat);
    }
}

void addition(t_stos **wsk_stos){ 
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                     
        t_stos *pom = (*wsk_stos)->nastepny;  
        int liczba1 = (*wsk_stos)->dane;  
        int liczba2= pom->dane;         
        pop(wsk_stos);   
        pop(wsk_stos);
        push(wsk_stos,liczba1+liczba2);   
    }
}

void subtraction(t_stos **wsk_stos){  
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                     
        t_stos *pom = (*wsk_stos)->nastepny; 
        int liczba1 = (*wsk_stos)->dane;  
        int liczba2= pom->dane;  
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba2-liczba1); 
    }
}

void multiplication(t_stos **wsk_stos){  
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                          
        t_stos *pom = (*wsk_stos)->nastepny; 
        int liczba1 = (*wsk_stos)->dane; 
        int liczba2= pom->dane; 
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba1*liczba2);
    }
}

void division(t_stos **wsk_stos){  
    if(*wsk_stos==NULL) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {                                       
        t_stos *pom = (*wsk_stos)->nastepny; 
        int liczba1 = (*wsk_stos)->dane; 
        int liczba2= pom->dane; 
        if(liczba1==0) fprintf(stderr,"Nie dzielimy przez zero!\n");
        else {
        pop(wsk_stos); 
        pop(wsk_stos);
        push(wsk_stos,liczba2/liczba1);} 
    }
}

int size(t_stos *wsk_stos){
    int licznik=0; 
    t_stos *pom = wsk_stos;
    while(pom!=NULL){     
        licznik++;       
        pom=pom->nastepny;  
    }
    return licznik; 
}
/******************************************************************************************/
/* Funkcja automatyczne_testy jest zastąpieniem funkcji wykonaj_program. Różnica polega   */
/* na tym, że funkcja wczytuje dane z przygotowanego pliku testowego. Użytkownik nie musi */
/* wprowadzać dane z klawiatury, Program wczyta je z pliku automatycznie i wykona na ich  */
/* podstawie wszystkie operacje,testy aby sprawdzić poprawność działania programu.        */   
/* /param[in] wskaznik na stos, zainiciowany w funkcji głównej main                       */
/* /param[in] zmienna plikowa plik, do odczytu danych                                     */
/* /param[out] funkcja void nic nie musi zwracać, w przypadku błędów wyświetla komunikat  */
/* i wykonuje się dalej, aż do napotkania znaku kończącego w pliku ('q') bądź,aż wczyta   */
/* wszystkie dane z pliku(while(znak!=EOF)).                                              */
/*                                                                                        */
/* UWAGA Komentarze są dołączone tylko obok nowego kodu zaimplementowanego do sprawnej    */
/* obsługi pliku "plik_testowy.txt", z którego wykonywane są automatyczne testy.          */
/* Reszta kodu jest identyczna jak poprzednio w pliku kalkulator_rpn.c więc komentarze są */
/* w tym przypadku zbędne!                                                                */
/******************************************************************************************/

void automatyczne_testy(t_stos *stos,FILE *plik){
    char znak,znak2; 
    int liczba;
    char komentarze[DL_KOMENTARZY]; /*Tablica znaków do pobierania komentarzy z pliku testowego*/

    do{   
        do{
            znak=getc(plik);
            if(znak=='#'){
                fgets(komentarze,DL_KOMENTARZY,plik);
                printf("%s",komentarze);
            }
            else ungetc(znak,plik);
        }while(znak=='#');
        
        znak=getc(plik);
        if(znak==EOF) exit(0);  /*Na wszelki wypadek,aby pętla nie wykonywała się w niekończoność*/
        if((znak!=' ')&&(znak!='\t')&&(znak!='\n')){ 
            switch(znak){  
                case '+': {  
                    addition(&stos); 
                    break;
                }
                case '-': {  
                    znak=getc(plik); 
                    if((znak<48)||(znak>57)) { 
                        ungetc(znak,plik); 
                        subtraction(&stos); 
                    }
                    else { 
                        ungetc(znak,plik);
                        fscanf(plik,"%d",&liczba); 
                        znak=getc(plik);   
                            switch(znak) {
                                case '.': { 
                                    znak2=getc(plik);
                                    if((znak2>=48)&&(znak2<=57)) {  
                                        fprintf(stderr,"Błąd! Należy wczytać tylko liczby całkowite!\n"); 
                                        ungetc(znak2,plik); 
                                        fscanf(plik,"%d",&liczba); 
                                    }
                                    else { 
                                        ungetc(znak2,plik); 
                                        ungetc(znak,plik); 
                                        push(&stos,(-1)*liczba); 
                                    }
                                    break;
                                }
                                default: { 
                                    ungetc(znak,plik);
                                    push(&stos,(-1)*liczba);
                                    break;
                                }
                            }
                    }
                    break;
                }
                case '*': {
                    multiplication(&stos); 
                    break;
                }
                case '/': {
                    division(&stos);  
                    break;
                }                        
                case 'P': {
                    pop(&stos);   
                    break;
                }
                case 'c': {
                    clear(&stos); 
                    break;
                }
                case 'r': {
                    reverse(&stos);
                    break;
                }
                case 'd': {
                    duplication(&stos);  
                    break;
                }
                case 'p': {
                    print(stos);  
                    break;
                }
                case 'f': {
                    full_print(stos);
                    break; 
                }
                case 'q': {
                    free(stos); 
                    stos=NULL;
                    break;
                }
                default: {  
                    if((znak>=48)&&(znak<=57)) { 
                        ungetc(znak,plik); 
                        fscanf(plik,"%d",&liczba); 
                        znak=getc(plik); 
                            switch(znak){
                                case '.': { 
                                    znak2=getc(plik);
                                    if((znak2>=48)&&(znak2<=57)) { 
                                        fprintf(stderr,"Błąd! Należy wczytać tylko liczby całkowite!\n");
                                        ungetc(znak2,plik);
                                        fscanf(plik,"%d",&liczba); 
                                    }
                                    else { 
                                        ungetc(znak2,plik); 
                                        ungetc(znak,plik); 
                                        push(&stos,liczba); 
                                    }
                                    break;
                                }
                                default: { 
                                   ungetc(znak,plik);
                                   push(&stos,liczba); 
                                   break;
                                }
                            } 
                    }else fprintf(stderr,"Niepoprawna opcja!!\n");
                    break;
                }
            }
        }
    }while(znak!='q');
}



