CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog09??
	rm -f prog09??a
	rm -f prog09??b
	rm -f prog09??c
	rm -f prog09??d
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
	rm -f lixo* soma soma2
