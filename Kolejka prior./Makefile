#==============================================================================
#Makefile Zestaw 05
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall 

.PHONE: all clean

all:  priorityQueue.out


priorityQueue.out:	priorityQueue.o
priorityQueue.o:	priorityQueue.cpp	

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
