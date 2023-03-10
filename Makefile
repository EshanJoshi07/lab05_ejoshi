# Makefile
CXX_FLAG = --std=c++11 -g

all: genbst

genbst: genbst.o 
	g++ $(CXX_FLAG) -o genbst genbst.o


genbst.o: genbst.cpp genbst.h
	g++ $(CXX_FLAG) -c genbst.cpp

clean:
	rm *.o genbst
