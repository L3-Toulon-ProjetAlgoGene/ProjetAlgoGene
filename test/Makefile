test.exe: test.o Cville.o Cchemin.o Cpopulation.o Cselection.o
	g++ -Wall $^ -o test.exe

test.o: test.cpp ../src/inc/Cselection.h
	g++ -c test.cpp

Cville.o: ../src/inc/Cville.h ../src/cpp/Cville.cpp
	g++ -c ../src/cpp/Cville.cpp

Cchemin.o: ../src/inc/Cchemin.h ../src/inc/Cville.h ../src/cpp/Cchemin.cpp
	g++ -c ../src/cpp/Cchemin.cpp

Cpopulation.o: ../src/inc/Cpopulation.h ../src/inc/Cchemin.h ../src/cpp/Cpopulation.cpp
	g++ -c ../src/cpp/Cpopulation.cpp

Cselection.o: ../src/inc/Cselection.h ../src/cpp/Cselection.cpp
	g++ -c ../src/cpp/Cselection.cpp
