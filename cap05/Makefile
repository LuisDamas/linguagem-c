CC=gcc
CFLAGS=-std=c99 -Wall
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog05??
	rm -f prog05??a
	rm -f prog05??b
	rm -f prog05??c
	rm -f prog05??d
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
