all: p1

p1: Character.o battle.o
	g++ -o p1 main.cc Character.o battle.o

Character.o: Character.h Character.cc 
	g++ -c Character.cc

battle.o: battle.h battle.cc	
	g++ -c battle.cc

clean: 
	rm -f *.o p1
