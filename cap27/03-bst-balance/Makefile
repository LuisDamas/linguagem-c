CC=gcc
CFLAGS=-Wall  -g

prog2704: prog2704.o bst.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

prog2703: prog2703.o bst.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog27??
	rm -f *.gch
	rm -f *.swp

