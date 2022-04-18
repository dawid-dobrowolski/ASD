#==============================================================================
#Makefile Zestaw 04
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall 

.PHONE: all clean

all:  list.out


list.out:	list.o
list.o:		list.cpp	

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
