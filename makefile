all: a+.exe

a+.exe: a+.o
	gcc -o a+.exe *.o

a+.o: clean
	gcc -c *.c

clean:
	rm -f a+.exe *.o