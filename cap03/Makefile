CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog03??
	rm -f prog03??a
	rm -f prog03??b
	rm -f prog03??c
	rm -f prog03??d
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
