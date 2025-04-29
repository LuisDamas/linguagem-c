CC=gcc
CFLAGS=-std=gnu11 -Wall  -g
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clear:
	rm *.o

