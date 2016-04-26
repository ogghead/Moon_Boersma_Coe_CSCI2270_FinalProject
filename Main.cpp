#include <sstream>
#include <iostream>
#include "Blackjack.h"
#include <stack>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    Blackjack myGame;
        int i=0;
        int dD=0;
        int deck=0;
        int players=0;
        string inputDeck, inputPlayers;
        cout<<"How many decks: "<<endl;
        getline(cin,inputDeck);
        stringstream de(inputDeck);
        de >> deck;
        cout<<"How many players: "<<endl;
        getline(cin,inputPlayers);
        stringstream pl(inputPlayers);
        pl >> players;
    myGame.buildDeck(deck);
    myGame.shuffleDeck(deck);
    myGame.createPlayers(players);


    return 0;
}

