#Created by Tyler Dailey, University of Utah, 9/13/16
#Assignment 3, CS 3505

CC = g++
CFLAGS = -Wall -std=c++11
TRIEINCLUDE = ./
TRIELIB = ./

TestTrie : libTrie.a TestTrie.o
	$(CC) $(CFLAGS) -o TestTrie TestTrie.o -L$(TRIELIB) -lTrie

libTrie.a : Trie.o Node.o TestTrie.o
	ar -rcs libTrie.a Trie.o Node.o TestTrie.o

Trie.o : $(TRIEINCLUDE)Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c -I$(TRIEINCLUDE) Trie.cpp

Node.o : $(TRIEINCLUDE)Node.h Node.cpp
	$(CC) $(CFLAGS) -c -I$(TRIEINCLUDE) Node.cpp

TestTrie.o : $(TRIEINCLUDE)Trie.h TestTrie.cpp
	$(CC) $(CFLAGS) -c -I$(TRIEINCLUDE) TestTrie.cpp

clean :
	rm TestTrie *.o libTrie.a

test:
	./TestTrie "dictionary.txt" "dictionary2.txt"

testZ:
	./TestTrie "dictionary.txt" "z.txt"

testZYX:
	./TestTrie "dictionary.txt" "zyx.txt"
