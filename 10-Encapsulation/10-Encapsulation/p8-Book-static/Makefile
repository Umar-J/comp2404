p8:	main.o Book.o
	g++ -o p8 main.o Book.o

main.o:	main.cc Book.h
	g++ -c main.cc

Book.o:	Book.cc Book.h
	g++ -c Book.cc

clean:
	rm -f *.o p8
