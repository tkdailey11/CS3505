#Created by Tyler Dailey, University of Utah, 9/13/16
#Assignment 3, CS 3505

CC = g++
CFLAGS = -Wall -std=c++11
TRIEINCLUDE = ./
TRIELIB = ./

TrieTest : libTrie.a TrieTest.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o -L$(TRIELIB) -lTrie

libTrie.a : Trie.o Node.o TrieTest.o
	ar -rcs libTrie.a Trie.o Node.o TrieTest.o

Trie.o : $(TRIEINCLUDE)Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c -I$(TRIEINCLUDE) Trie.cpp

Node.o : $(TRIEINCLUDE)Node.h Node.cpp
	$(CC) $(CFLAGS) -c -I$(TRIEINCLUDE) Node.cpp

TrieTest.o : $(TRIEINCLUDE)Trie.h TrieTest.cpp
	$(CC) $(CFLAGS) -c -I$(TRIEINCLUDE) TrieTest.cpp

clean :
	rm TrieTest *.o libTrie.a

test:
	./TrieTest "dictionary.txt" "dictionary2.txt"

testZ:
	./TrieTest "dictionary.txt" "z.txt"

testZYX:
	./TrieTest "dictionary.txt" "zyx.txt"

testInvalid1:
	./TrieTest "this is an invalid file" "dictionary.txt"

testInvalid2:
	./TrieTest "dictionary.txt" "invalid.txt"
