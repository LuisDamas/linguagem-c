CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clear:
	rm *.o

