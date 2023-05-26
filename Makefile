#Makefile
#Wywołanie komendą "make"
CFLAGS = -std=c99 -pedantic -Wall  #Inne flagi kompilatora

main: main.o kalkulator_rpn.o
	gcc $(CFLAGS) main.o kalkulator_rpn.o -o prog
	
main.o: main.c kalkulator_rpn.h
	gcc -c main.c 

kalkulator_rpn.o: kalkulator_rpn.c kalkulator_rpn.h
	gcc -c kalkulator_rpn.c
# KOmenda "make clean" czyści pliki z rozszerzeniem .o oraz utworzony plik prog
clean:
	rm *.o prog

