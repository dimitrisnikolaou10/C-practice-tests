correct: main6.o correct.o
	g++ main6.o correct.o -o correct

main6.o: main6.cpp
	g++ -c main6.cpp

correct.o: correct.cpp
	g++ -c correct.cpp
