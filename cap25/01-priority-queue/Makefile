CC=gcc
CFLAGS=-Wall  -g

prog2501: prog2501.o my-list.o grade.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog25??
	rm -f *.gch
	rm -f *.swp

