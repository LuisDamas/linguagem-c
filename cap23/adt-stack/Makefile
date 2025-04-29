CC=gcc
CFLAGS=-Wall  -g

app-stack-static: main.o stack-static.o
	$(CC) $(CFLAGS) $^ -o $@

app-stack-dynamic: main.o stack-dynamic.o
	$(CC) $(CFLAGS) $^ -o $@

app-stack-linked: main.o stack-linked.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f app-stack-static app-stack-dynamic app-stack-linked
	rm -f *.gch
	rm -f *.swp

