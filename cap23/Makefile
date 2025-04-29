CC=gcc
CFLAGS=-Wall  -g

prog2601: prog2601.o set.o item.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog23??
	rm -f *.gch
	rm -f *.swp

