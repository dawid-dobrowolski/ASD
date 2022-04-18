#==============================================================================
#Makefile Zestaw 05
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall 

.PHONE: all clean

all:  deque.out


deque.out:	deque.o
deque.o:	deque.cpp	

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
