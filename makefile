all: shmegegge.o
	gcc shmegegge.o

run:
	./a.out

shmegegge.o: shmegegge.c
	gcc -c shmegegge.c

clean:
	rm ./a.out
	rm *.o
