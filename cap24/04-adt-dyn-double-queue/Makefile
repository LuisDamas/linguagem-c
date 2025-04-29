CC=gcc
CFLAGS=-Wall  -g

prog2404: prog2404.o queue.o item.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog24??
	rm -f *.gch
	rm -f *.swp

