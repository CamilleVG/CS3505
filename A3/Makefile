DEBUG ?= 1
ifeq (DEBUG, 1)
    DEBUGFLAGS =-g3 -gdwarf2 -DDEBUG
else
    DEBUGFLAGS=-DNDEBUG
endif

CC = g++ $(DEBUGFLAGS)
CFLAGS = -Wall -g

TrieTest: Trie.o Node.o TrieTest.cpp
	$(CC) $(CFLAGS) -o TrieTest Trie.o Node.o TrieTest.cpp 

Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(CFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp 

clean:
	rm -f *.o *.a test