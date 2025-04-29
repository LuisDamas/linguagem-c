CC=gcc
CFLAGS=-Wall  -g
OBJ=stack.o

prog2202: prog2202.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f prog????
	rm -f *.swp

