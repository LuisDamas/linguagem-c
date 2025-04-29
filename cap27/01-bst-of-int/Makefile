CC=gcc
CFLAGS=-Wall  -g

prog2701: prog2701.o bst.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog27??
	rm -f *.gch
	rm -f *.swp

