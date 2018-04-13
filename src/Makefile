FLAGS = -L./libs -L. -L/usr/include/GL -L/usr/X11R6/lib -lcng -lglut -lGLU -lGL -lX11 -lm -g

main.exe: Cpopulation.o Cville.o Cchemin.o Cselection.o main.o
	g++ $^ -o main.exe $(FLAGS)

main.o: cpp/main.cpp inc/Cville.h inc/Cpopulation.h inc/Cchemin.h inc/cng.h
	g++ -c cpp/main.cpp

Cpopulation.o: inc/Cpopulation.h cpp/Cpopulation.cpp inc/Cchemin.h
	g++ -c cpp/Cpopulation.cpp

Cville.o: inc/Cville.h cpp/Cville.cpp
	g++ -c cpp/Cville.cpp

Cchemin.o: inc/Cchemin.h cpp/Cchemin.cpp inc/Cville.h
	g++ -c cpp/Cchemin.cpp

Cselection.o: inc/Cselection.h inc/Cpopulation.h inc/Cchemin.h cpp/Cselection.cpp
	g++ -c cpp/Cselection.cpp
