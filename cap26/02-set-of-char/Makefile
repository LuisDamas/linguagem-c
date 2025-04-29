CC=gcc
CFLAGS=-Wall  -g

prog2602: prog2602.o set.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog26??
	rm -f *.gch
	rm -f *.swp

