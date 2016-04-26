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

bool Blackjack::ai(player * player){
    int ori=player->orientation;
        while(player->stand==false){
            if(ori==0){
                break;
            }

            else if(ori==2){
                if(player->handValue < 17){
                    HitMe(player,false);
                }
            if(player->handValue >= 17){
                Stand(player);
                }
            }
            else if(ori==1){
                if(player->handValue < 16){
                    HitMe(player,false);
                }
                if(player->handValue >= 16){
                    Stand(player);
                }
            }

            else if(ori==3){
                if(player->handValue < 18){
                    HitMe(player,false);
                }
                if(player->handValue >= 18){
                    Stand(player);
                }
            }
        }
    }

void Blackjack::HitMe(player* currentPlayer, bool secondHand)//this boolean checks
//if the hand to deal to is the 2nd one, if a player has split
{
    int index = deck.size() - 1;
    card* tmp = deck[index];

    if (secondHand == false)
    {
        currentPlayer->hand.push_back(tmp);
        if((tmp->value==11)&&(currentPlayer->handValue+11 > 21))
        {
            currentPlayer->handValue=currentPlayer->handValue+1;
        }
        else
        {
        currentPlayer->handValue=currentPlayer->handValue + tmp->value;
         if(currentPlayer->handValue>21){
             currentPlayer->stand=true;
         }
        }
    }

    else
    {
        currentPlayer->hand2.push_back(tmp);
        if((tmp->value==11)&&(currentPlayer->handValue2+11 > 21)){
            currentPlayer->handValue2=currentPlayer->handValue2+1;
        }else{
        currentPlayer->handValue2=currentPlayer->handValue2 + tmp->value;
        }
         if(currentPlayer->handValue2>21){
             currentPlayer->stand2=true;
         }
    }


    if (tmp->value == 2 || tmp->value == 3 || tmp->value == 4 ||
        tmp->value == 5 || tmp->value == 6)
        {
            cardCounter = cardCounter + 1;
        }
    else if (tmp->value == 7 || tmp->value == 8 || tmp->value == 9)
        {
            cardCounter = cardCounter;
        }
    else if (tmp->value >= 10)
        {
            cardCounter = cardCounter - 1;
        }
    deck.pop_back();
    delete tmp;

}

void Blackjack::createPlayers(int playerNumber)
{
    player* me = new player;
    me->orientation = 0;
    me->totalMoney = 1000;

    players.push_back(me);

    srand(time(NULL));

    for(int i = 1; i < playerNumber; i++)
    {
        player* newAI = new player;
        newAI->orientation = rand() % 4 + 1;
        newAI->totalMoney = 1000;
        players.push_back(newAI);
    }
}

vector <player*> Blackjack::returnPlayers()
{
    return players;
}

void Blackjack::Deal()
{
    for (int i = 0; i < players.size(); i++)
    {
        HitMe(players[i], false);
        HitMe(players[i], false);
    }
}

void Blackjack::Stand(player* currentPlayer)
{
    currentPlayer->stand = true;
}

void Blackjack::Stand2(player* currentPlayer)
{
    currentPlayer->stand2 = true;
}

void Blackjack::Split(player* myPlayer)
{
    card* tmp = myPlayer->hand[1];
    myPlayer->hand.pop_back();
    myPlayer->hand2.push_back(tmp);
    myPlayer->handValue = myPlayer->handValue - tmp->value;
    myPlayer->handValue2 = tmp->value;
    HitMe(myPlayer,true);
    HitMe(myPlayer,false);
    myPlayer->bet2 = myPlayer->bet;
}

void Blackjack::Bet(player* currentPlayer, int bet)
{
    currentPlayer->bet = bet;
}

int Blackjack::displayCardCounter()
{
    return cardCounter;
}
