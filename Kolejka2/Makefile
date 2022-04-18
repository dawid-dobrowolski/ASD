#==============================================================================
#Makefile Zestaw 2 Implementacja kolejki priorytetowej
#==============================================================================
CC		:= g++
CFLAGS	:= -Wall 

.PHONE: all clean

all:  main.out


main.out:	main.o
main.o:		main.cpp	

%.out: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC)	$(CFLAGS)	-c	-o	$@	$<
clean:
	$(RM) $(wildcard *.[o])
