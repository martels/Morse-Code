main: main.o MorseTranslation.o
	g++ main.o MorseTranslation.o -o main


MorseTranslation.o: MorseTranslation.cpp
	g++ -Wall -c MorseTranslation.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm main.o MorseTranslation.o main