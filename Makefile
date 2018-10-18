main: main.o MorseTranslation.o stringconvert.o
	g++ main.o MorseTranslation.o stringconvert.o -o main

stringconvert.o: stringconvert.cpp
	g++ -Wall -c stringconvert.cpp

MorseTranslation.o: MorseTranslation.cpp
	g++ -Wall -c MorseTranslation.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm main.o MorseTranslation.o stringconvert.o main