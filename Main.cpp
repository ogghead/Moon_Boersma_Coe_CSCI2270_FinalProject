#include <sstream>
#include <iostream>
#include "Blackjack.h"
#include <stack>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

    bool Quit = false;
    while (!Quit)
    {
        string bet;
        cout<<"Buy-in is 10, max bet is 1000."<<endl;
        cout<<"How much would you like to bet?"<<endl;
        getline(cin,bet);
        int myBet = stoi(bet);
        myGame.Bet(myBet);
        myGame.Deal();
        player* me = myGame.returnPlayer();
        player* dealer = myGame.returnDealer();
myGame.show();
        cout << "The dealer has: " << endl;
        cout << "??" << endl;
        cout << dealer->hand[0]->name << " of " << dealer->hand[0]->sui << endl;
        cout << endl;

        cout << "You have: " << endl;
        cout << me->hand[0]->name << " of " << me->hand[0]->sui << endl;
        cout << me->hand[1]->name << " of " << me->hand[1]->sui << endl;
        cout << endl;
        //cout << dealer->hand[1] << endl;



        cout << "1. Hit " << endl;
        cout << "2. Stand" << endl;
        cout << "3. Double Down " << endl;
        int splitted=0;
        if (me->hand[0]->name == me->hand[1]->name){
            cout << "4. Split " << endl;
            me->isSplit = true;

        }
        string choice;
        getline(cin, choice);
        int myChoice = stoi(choice);
        if (myChoice == 1){
            myGame.HitMe(me, false);

        }
        if (myChoice == 2){
            myGame.Stand(me);
        }
        if (myChoice == 3){
            myGame.doubleDown(me);
        }
        if (myChoice == 4 && me->isSplit==true){
            myGame.Split(me);
            splitted=1;
        }

        while (!me->stand)
        {
            cout << "1. Hit " << endl;
            cout << "2. Stand" << endl;
            string choice;
            getline(cin, choice);
            int myChoice = stoi(choice);

            if (myChoice == 1){
                myGame.HitMe(me, false);
            }
            if (myChoice == 2){
                myGame.Stand(me);
            }
        }
        if (me->isSplit){
            while (!me->stand2)
            {
                cout << "1. Hit " << endl;
                cout << "2. Stand" << endl;
                string choice;
                getline(cin, choice);
                int myChoice = stoi(choice);

                if (myChoice == 1){
                    myGame.HitMe(me, true);
                }
                if (myChoice == 2){
                    myGame.Stand2(me);
                }
            }
        }

        myGame.Round();

        myGame.show();
     cout << "The dealer had: " << endl;
        for (int i = 0; i < dealer->hand.size();i++)
        {
            cout << dealer->hand[i]->name << " of " << dealer->hand[i]->sui << endl;
        }
        cout << endl;

        cout << "You had: " << endl;
        for (int i = 0; i < me->hand.size();i++)
        {
            cout << me->hand[i]->name << " of " << me->hand[i]->sui << endl;
        }
        cout << endl;

         cout<<"CardCounter: "<<myGame.displayCardCounter()<<endl;
        if(me->handValue > 21){
            me->handValue=0;
        }
         if(dealer->handValue > 21){
            dealer->handValue=0;
        }
        if(me->handValue < dealer->handValue){
            cout<<"You lose."<<endl;
            me->totalMoney=me->totalMoney-me->bet;
        }
        if(me->handValue > dealer->handValue){
            cout<< " You win." <<endl;
            if(me->hand.size()==2){
                me->totalMoney=me->totalMoney+(me->bet)/2 +me->bet;
            }else{
            me->totalMoney=me->totalMoney+me->bet;
            }
        }
        if(me->handValue==dealer->handValue){
            cout<< " You push." <<endl;
        }

        if(splitted==1){
          if(me->handValue2 > 21){
            me->handValue2=0;
        }


        if(me->handValue2 < dealer->handValue){
            cout<<"You lose.(Second Hand)"<<endl;
            me->totalMoney=me->totalMoney-me->bet2;
        }
        if(me->handValue > dealer->handValue){
             cout<< " You win. (Second Hand)" <<endl;
            if(me->hand2.size()==2){
                me->totalMoney=me->totalMoney+(me->bet2)/2 +me->bet2;
            }else{
            me->totalMoney=me->totalMoney+me->bet2;
            }
        }
        if(me->handValue==dealer->handValue){
                cout << "You push. (Second Hand)"<<endl;
        }


    }


    myGame.Reset();
    cout<< "Would you like to stop playing? (Y) ";
    string choice2;
    getline(cin, choice2);
    if (choice2 == "N")
        Quit = true;
    }


    return 0;
}

