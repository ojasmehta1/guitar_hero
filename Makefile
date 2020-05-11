GuitarHero: RingBuffer.o GuitarString.o main.o
	g++ -o GuitarHero main.o GuitarString.o RingBuffer.o -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window

main.o: RingBuffer.hpp GuitarString.hpp main.cpp
	g++ -c main.cpp -pedantic -Wall -Werror

GuitarString.o: RingBuffer.hpp GuitarString.hpp GuitarString.cpp
	g++ -c GuitarString.cpp -pedantic -Wall -Werror

RingBuffer.o: RingBuffer.hpp RingBuffer.cpp
	g++ -c RingBuffer.cpp -pedantic -Wall -Werror

clean:
	rm -f *.o *~ GuitarHero
