chess: main.o functions.o
	gcc main.o functions.o -o bin/chess.exe

main.o:	src/main.c
	gcc -std=c99 -Wall -I include -c src/main.c

functions.o: src/functions.c
	gcc -std=c99 -Wall -I include -c src/functions.c

clean:
	del *.o 
	del chess.exe