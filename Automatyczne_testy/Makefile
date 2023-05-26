#Makefile
#Wywołanie komendą "make"
CFLAGS = -std=c99 -pedantic -Wall  #Inne flagi kompilatora

main: testy.o test_kalkulator_rpn.o
	gcc $(CFLAGS) testy.o test_kalkulator_rpn.o -o prog
	
main.o: testy.c test_kalkulator_rpn.h
	gcc -c testy.c 

test_kalkulator_rpn.o: test_kalkulator_rpn.c test_kalkulator_rpn.h
	gcc -c test_kalkulator_rpn.c
# KOmenda "make clean" czyści pliki z rozszerzeniem .o oraz utworzony plik prog
clean:
	rm *.o prog

