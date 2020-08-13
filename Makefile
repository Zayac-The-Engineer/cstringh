all: str.o

str.o: str.c
	gcc -c str.c

clean:
	rm -rf *.o
