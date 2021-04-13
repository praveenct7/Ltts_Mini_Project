CC=g++

CFlags=-c -Wall
output: main.o checkalgo.o
	$(CC) main.o checkalgo.o -o output

main.o: main.c
	$(CC) $(CFlags) main.c

checkalgo.o: checkalgo.c checkalgo.h
	$(CC) $(CFlags) checkalgo.c

clean:
	rm *.o output