CC=gcc
CFLAGS=-g -Wall -Werror -fsanitize=address
list: linkedList.o
	$(CC) $(CFLAGS) -o $@ $^
linkedList.o: linkedList.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f -r list
	rm -f -r *.o
	clear