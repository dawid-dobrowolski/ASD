#==============================================================================
#															Makefile Zestaw 03
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall -std=c+11 

.PHONE: all clean

all:  array.out

array.out:	array.o
array.o:		array.cpp

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
