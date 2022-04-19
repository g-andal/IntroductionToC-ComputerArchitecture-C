CC=gcc
CFLAGS=-g -Wall -Werror -fsanitize=address
string: stringOps.o
	$(CC) $(CFLAGS) -o $@ $^
stringOps.o: stringOps.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f -r string
	rm -f -r *.o
	clear