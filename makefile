all: main.o
	gcc -o main.out main.o

main.o: main.c
	gcc -c main.c

clean:
	rm *.o
	rm *.out
	rm exit_file.txt

run:
	./main.out

comprun: all
	./main.out
