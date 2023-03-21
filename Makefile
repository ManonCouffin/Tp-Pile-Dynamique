test: element.c element.h pile_dynamique.c pile_dynamique.h application.c
	gcc -c element.c
	gcc -c pile_dynamique.c
	gcc -c application.c
	gcc -o test.out element.o pile_dynamique.o application.o
	./test.out
	
	
	
	
