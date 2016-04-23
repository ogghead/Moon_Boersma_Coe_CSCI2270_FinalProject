all: Blackjack.o Main.o
	g++ Blackjack.o Main.o

Blackjack.o: Blackjack.cpp Blackjack.h
	g++ -c -std=c++11 Blackjack.cpp

Main.o: Main.cpp Blackjack.h
	g++ -c -std=c++11 Main.cpp
