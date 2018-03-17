CC=c++ #main compiler

all: base58

base58: base58.o
	g++ base58.o -o base58

clean:
	rm -rf *o base58
