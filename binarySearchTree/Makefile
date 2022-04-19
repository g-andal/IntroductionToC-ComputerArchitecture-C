CC=cc
CFLAGS=-g -Wall -Werror -fsanitize=address
bts: bts.o
	$(CC) $(CFLAGS) -o $@ $^
bts.o: bts.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f -r bts
	rm -f -r *.o
	clear