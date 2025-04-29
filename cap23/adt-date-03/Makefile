CC=gcc
CFLAGS=-Wall  -g

main-struct: main.o mydate.o
	$(CC) $(CFLAGS) $^ -o $@

main-string: main.o mydate_str.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f main-struct main-string
	rm -f *.gch
	rm -f *.swp

