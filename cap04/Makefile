CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog04??
	rm -f prog04??a
	rm -f prog04??b
	rm -f prog04??c
	rm -f prog04??d
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
