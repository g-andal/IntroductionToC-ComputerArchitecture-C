CC=gcc
CFLAGS=-g -Wall -Werror -fsanitize=address
sort: sortArray.o
	$(CC) $(CFLAGS) -o $@ $^
sortArray.o: sortArray.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f -r sort
	rm -f -r *.o
	clear