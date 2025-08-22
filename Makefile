CC = gcc
CFLAGS = -Wall -g

qe: qe.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f qe *.o
