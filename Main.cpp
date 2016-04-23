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
        int dD=0;
        int deck=0;
        int players=0;
        string inputDeck, inputPlayers;
        cout<<"How many decks: "<<endl;
        getline(cin,inputDeck);
       // deck=stoi(inputDeck);
        cout<<"How many players: "<<endl;
        getline(cin,inputPlayers);
     //   players=stoi(inputPlayers);
    //myGame.buildDeck(deck);
    //myGame.shuffleDeck(deck);
    //myGame.createPlayers(players);
 //   while(1){
        //betting function
//        myGame.Deal();
//        dD=0;
        //while(player.stand==false){
//            if(player.orientation==0){
//                string input;
//                cout<<"type in 1 to hit, 2 to stand, 3 to double down, 4 to split"<<endl;
//                if(input=="1"){
//                    dD++;
//                    myGame.HitMe();
//                }else if(input=="2"){
//                    myGame.Stand();
//                }else if((input=="3")&&(dD==0)){
//                     myGame.DoubleDown();
                //}else if((input=="4")&&(dD==0)&&(card1->name ==card2->name)){
                    //myGame.Split();
//                }else if(input=="3"){
//                    cout<< "cannot double down"<<endl;
//                }else if(input=="4"){
//                    cout<<"cannot split"<<endl;
//                }
//            }

        //}


//    }
    return 0;
}

