softbody: main.o
	g++ main.o vertex.o -o softbody -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

vertex.o: vertex.cpp vertex.h globals.h
	g++ -c vertex.cpp


main.o: main.cpp globals.h vertex.o
	g++ -c main.cpp


clean: 
	rm *.o softbody