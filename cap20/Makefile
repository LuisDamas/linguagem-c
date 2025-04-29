CC=gcc
CFLAGS=-Wall -g

quick05: quick05.o geral.o
	$(CC) $(CFLAGS) $^ -o $@

merge05: merge05.o geral.o
	$(CC) $(CFLAGS) $^ -o $@

insertion05: insertion05.o geral.o
	$(CC) $(CFLAGS) $^ -o $@

selection05: selection05.o geral.o
	$(CC) $(CFLAGS) $^ -o $@

bubble05: bubble05.o geral.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o
	rm -f quick?? merge?? insertion?? selection?? bubble??
	rm -f a.out lixo
	rm -f prog????
