#==============================================================================
#Makefile Zestaw 1 Implementacja zbioru na Listach
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
