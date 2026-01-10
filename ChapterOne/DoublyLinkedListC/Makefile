test: main.o linkedlist.o
	gcc main.o linkedlist.o -o test

main.o: src/main.c src/linkedlist.h
	gcc -c src/main.c

linkedlist.o: src/linkedlist.c src/linkedlist.h
	gcc -c src/linkedlist.c

clean:
	rm main.o 
	rm linkedlist.o

purge:
	rm main.o
	rm linkedlist.o
	rm main
