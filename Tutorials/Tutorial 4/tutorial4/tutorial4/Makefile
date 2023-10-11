all: test
	
test: test.cc App.o HeapArrays.o StackArrays.o
	g++ -o test test.cc App.o HeapArrays.o StackArrays.o
	
StackArrays.o:	StackArrays.h StackArrays.cc 
	g++ -c StackArrays.cc 
	
HeapArrays.o:	HeapArrays.h HeapArrays.cc 
	g++ -c HeapArrays.cc 

App.o:	App.h App.cc
	g++ -c App.cc
	
clean:
	rm -f test *.o
