all: test

test: test.cc Message.o List.o
	g++ -o test test.cc Tester.cc Message.o List.o

Message.o: Message.cc Message.h
	g++ -c Message.cc

List.o: List.cc List.h
	g++ -c List.cc

clean:
	rm -f *.o test