chess: main.o functions.o
	gcc main.o functions.o -o chess

main.o:	main.c
	gcc -std=c99 -Wall -c main.c

functions.o: functions.c
	gcc -std=c99 -Wall -c functions.c

clean:
	del *.o 
	del chess.exe