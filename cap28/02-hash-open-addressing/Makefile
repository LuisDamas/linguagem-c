CC=gcc
CFLAGS=-Wall  -g

prog2802: prog2802.o hash.o item.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog28??
	rm -f *.gch
	rm -f *.swp

