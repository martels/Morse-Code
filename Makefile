main: main.o MorseTranslation.o GPIOclass.o
	g++ main.o MorseTranslation.o GPIOclass.o -o main

GPIOclass.o: GPIOclass.cpp
	g++ -Wall -c GPIOclass.cpp

MorseTranslation.o: MorseTranslation.cpp
	g++ -Wall -c MorseTranslation.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm main.o MorseTranslation.o GPIOclass.o main