softbody: main.o
	g++ main.o -o softbody -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp globals.h
	g++ -c main.cpp

vertex.o: vertex.cpp vertex.h globals.h
	g++ -c vertex.cpp

clean: 
	rm *.o softbody