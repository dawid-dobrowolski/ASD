#==============================================================================
#Makefile Zestaw 07
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall 

.PHONE: all clean

all:  stack.out


stack.out:	stack.o
stack.o:	stack.cpp	

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
