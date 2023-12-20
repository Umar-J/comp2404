all: t8

t8: test.cc Episode.o Search.o
	g++ -o test test.cc Episode.o Search.o

Episode.o: Episode.cc Episode.h
	g++ -c Episode.cc

Search.o: Search.cc Search.h
	g++ -c Search.cc

clean:
	rm -f *.o t8