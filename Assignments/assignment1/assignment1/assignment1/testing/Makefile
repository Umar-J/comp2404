all: a1

a1: Date.o Event.o PlannerDate.o Planner.o tester.h
	g++ -o a1 main.cc Date.o Event.o PlannerDate.o Planner.o

Date.o: Date.cc Date.h
	g++ -c Date.cc

Event.o: Event.h Event.cc
	g++ -c Event.cc

PlannerDate.o: PlannerDate.cc PlannerDate.h Event.h Date.h
	g++ -c PlannerDate.cc

Planner.o: Planner.h Event.h Date.h PlannerDate.h Planner.cc
	g++ -c Planner.cc

clean:
	rm -f *.o a1