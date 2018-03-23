main.exe: Cpopulation.o Cville.o Cchemin.o main.o
	g++ $^ -o main.exe

main.o: cpp/main.cpp inc/Cville.h inc/Cpopulation.h inc/Cchemin.h
	g++ -c cpp/main.cpp

Cpopulation.o: inc/Cpopulation.h cpp/Cpopulation.cpp
	g++ -c cpp/Cpopulation.cpp

Cville.o: inc/Cville.h cpp/Cville.cpp
	g++ -c cpp/Cville.cpp

Cchemin.o: inc/Cchemin.h cpp/Cchemin.cpp
	g++ -c cpp/Cchemin.cpp
