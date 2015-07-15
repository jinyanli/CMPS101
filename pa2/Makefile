#------------------------------------------------------------------------------
#Author Jinyan Li, CMPS 101, pa2
# Makefile for CMPS 101 Programming Assignment 2
#
#       make                   makes Lex
#       make ListClient        makes ListClient
#
#------------------------------------------------------------------------------

Lex : Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -c -std=c99 -Wall -O0 -g Lex.c

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -c -std=c99 -Wall -O0 -g ListClient.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall -O0 -g List.c

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o
 
