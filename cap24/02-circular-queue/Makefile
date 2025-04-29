CC=gcc
CFLAGS=-Wall  -g

prog2402: prog2402.o circular-queue.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog24??
	rm -f *.gch
	rm -f *.swp

