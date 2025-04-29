CC=gcc
CFLAGS=-Wall  -g

prog2401: prog2401.o static-queue.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog24??
	rm -f *.gch
	rm -f *.swp

