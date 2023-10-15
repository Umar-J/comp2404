#observe - Linux is case sensitive. These names should match your filenames exactly

all: test
	
test: test.o TestControl.o AppArray.o App.o Device.o Tester.o
	g++ -o test test.o TestControl.o AppArray.o App.o Device.o Tester.o
	
test.o: test.cc App.h Device.h
	g++ -c test.cc

TestControl.o:   TestControl.cc TestControl.h
	g++ -c TestControl.cc

AppArray.o:   AppArray.cc AppArray.h
	g++ -c AppArray.cc
	
Device.o:	Device.h Device.cc 
	g++ -c Device.cc 

App.o:	App.h App.cc
	g++ -c App.cc

Tester.o:	Tester.h Tester.cc
	g++ -c Tester.cc
	
clean:
	rm -f test *.o
