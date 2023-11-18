p1:	main.o Student.o Address.o
	g++ -o p1 main.o Student.o Address.o

main.o:	main.cc Student.h Address.h
	g++ -c main.cc

Student.o:	Student.cc Student.h Address.h
	g++ -c Student.cc

Address.o:	Address.cc Address.h
	g++ -c Address.cc

clean:
	rm -f *.o p1
