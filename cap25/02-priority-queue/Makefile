CC=gcc
CFLAGS=-Wall  -g

prog2502: prog2502.o list.o person.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog25??
	rm -f *.gch
	rm -f *.swp

