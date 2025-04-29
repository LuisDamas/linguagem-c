CC=gcc
CFLAGS=-Wall  -g

prog2702: prog2702.o bst.o node.o person.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog27??
	rm -f *.gch
	rm -f *.swp

