CC=gcc
CFLAG=-g
a.out: processtree.c
			$(CC) $(CFLAG) processtree.c
demo: a.out
	a.out
