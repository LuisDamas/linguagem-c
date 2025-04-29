CC=gcc
CFLAGS=-Wall  -g

main: main.o mydate.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f main
	rm -f *.gch
	rm -f *.swp

