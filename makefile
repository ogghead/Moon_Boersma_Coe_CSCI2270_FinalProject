all: Main.o Blackjack.o
	g++ Blackjack.o Main.o
Main.o: Main.cpp BLACKJACK_H
	g++ -c Main.cpp
Blackjack.o: Blackjack.cpp BLACKJACK_H
	g++ -c Blackjack.cpp
