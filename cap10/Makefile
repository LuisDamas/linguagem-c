CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog10??
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
	rm -f lixo* gest
	rm -f conta head line mostra mycat mycopy proc upper show_cols
