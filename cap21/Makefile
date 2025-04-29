CC=gcc
CFLAGS=-Wall  -g
OBJ=mylist.o search.o

seq-search: seq-search.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

seq-search-ord: seq-search-ord.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bin-search-ite: bin-search-ite.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bin-search-rec: bin-search-rec.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bin-search-rec-stat: bin-search-rec-stat.o $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f seq-search seq-search-ord bin-search-ite bin-search-rec bin-search-rec-stat prog????
	rm -f *.swp

