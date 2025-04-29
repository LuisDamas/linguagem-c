CC=gcc
CFLAGS=-std=c99 -Wall 
# -nostdinc

all:
	echo $@
	echo @<

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o prog12?? prog12??a prog12??b
	rm -f a.out
	rm -f *.gch
	rm -f *.swp
	rm -f lixo* gest
	rm -f demo-reg/demo-reg
	rm -f queue-arr/*.o queue-arr/demo-queue-arr
	rm -f queue-dynamic/*.o queue-dynamic/demo-queue-dynamic
	rm -f stack-dynamic/*.o stack-dynamic/demo-stack-dynamic


