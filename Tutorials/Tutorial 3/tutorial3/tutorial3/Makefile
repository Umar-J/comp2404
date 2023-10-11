all: test

test: Date.o Event.o PlannerDate.o
	g++ -o test test.cc Date.o Event.o PlannerDate.o

Date.o: Date.cc Date.h
	g++ -c Date.cc

Event.o: Event.h Event.cc
	g++ -c Event.cc

PlannerDate.o: PlannerDate.cc PlannerDate.h Event.h Date.h
	g++ -c PlannerDate.cc
	
clean:
	rm -f *.o test