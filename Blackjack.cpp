#include "Blackjack.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

Blackjack::Blackjack()
{
    //ctor

}

Blackjack::~Blackjack()
{
    //dtor
}

void Blackjack::buildDeck(int deckNumber){
    for (int s = 0; s < deckNumber; s++){

        for(int i=0;i<4;i++){
            for(int j=0; j<13;j++){
                card *newCard = new card;
                newCard->suit=i;
                if (j+1 == 1){
                    newCard->value = 11;
                    newCard->name = "Ace";
                }
                    else if (j+1 == 2){
                        newCard->value = j + 1;
                        newCard->name = "Two";
                    }
                    else if (j+1 == 3){
                        newCard->value = j + 1;
                        newCard->name = "Three";
                    }
                    else if (j+1 == 4){
                        newCard->value = j + 1;
                        newCard->name = "Four";
                    }
                    else if (j+1 == 5){
                        newCard->value = j + 1;
                        newCard->name = "Five";
                    }
                    else if (j+1 == 6){
                        newCard->value = j + 1;
                        newCard->name = "Six";
                    }
                    else if (j+1 == 7){
                        newCard->value = j + 1;
                        newCard->name = "Seven";
                    }
                    else if (j+1 == 8){
                        newCard->value = j + 1;
                        newCard->name = "Eight";
                    }
                    else if (j+1 == 9){
                        newCard->value = j + 1;
                        newCard->name = "Nine";
                    }
                    else if (j+1 == 10){
                        newCard->value = j + 1;
                        newCard->name = "Ten";
                    }
                    else if (j+1 == 11){
                        newCard->value = 10;
                        newCard->name = "Jack";
                    }
                    else if (j+1 == 12){
                        newCard->value = 10;
                        newCard->name = "Queen";
                    }
                    else if (j+1 == 13){
                        newCard->value = 10;
                        newCard->name = "King";
                    }
                    //cout<<newCard->name<<endl;
                    deck.push_back(newCard);
                }
            }
        }
    }


void Blackjack::shuffleDeck(int deckNumber){
    srand(time(NULL));
    random_shuffle(deck.begin(),deck.end());

}

void Blackjack::HitMe(player* currentPlayer, bool secondHand)//this boolean checks
//if the hand to deal to is the 2nd one, if a player has split
{
    int index = deck.size() - 1;
    card* tmp = deck[index];

    if (secondHand == false)
    {
        currentPlayer->hand.push_back(tmp);
    }

    else
    {
        currentPlayer->hand2.push_back(tmp);
    }
    deck.pop_back();
    delete tmp;
}
