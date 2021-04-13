
output: main.o checkalgo.o
	g++ main.o checkalgo.o -o output

main.o: main.c
	g++ -c main.c

checkalgo.o: checkalgo.c checkalgo.h
	g++ -c checkalgo.c

clean:
	rm *.o output