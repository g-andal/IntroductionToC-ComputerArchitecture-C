CC=cc
CFLAGS=-g -Wall -Werror -fsanitize=address
hash: hashTable.o
	$(CC) $(CFLAGS) -o $@ $^
hashTable.o: hashTable.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f -r hash
	rm -f -r *.o
	clear