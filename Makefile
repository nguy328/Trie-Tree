CXX = g++
CPPFLAGS = -g -Wall -std=c++11

all: TrieSet.o

TrieSet.o: TrieSet.h TrieSet.cpp 
	$(CXX) $(CPPFLAGS) -c TrieSet.cpp -o TrieSet.o

