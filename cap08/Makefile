CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog08??
	rm -f prog08??a
	rm -f prog08??b
	rm -f prog08??c
	rm -f prog08??d
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
	rm -f lixo*
