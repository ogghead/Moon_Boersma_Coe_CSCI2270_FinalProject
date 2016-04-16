#ifndef BLACKJACK_H
#define BLACKJACK_H

struct card
{
    int value;
    std::string suit;
    std::string name;
    int counter;
};

struct player
{
    std::string name;
    int orientation;//1 defensive, 2 normal, 3 aggressive playstyle
    int handValue;
    vector<card> hand;
    int totalMoney;
    int bet;
    bool isSplit;
    int handValue2 = 0;
    vector<card> hand2;
    int bet2 = 0;
    bool stand = false;
};

struct dealer
{
    int handValue;
    vector<card> hand;
    bool stand = false;
};

class Blackjack
{
private:
dealer Dealer;
vector<card> deck;
vector<player> players;
int cardCounter;

public:
    void buildDeck(int deckNumber);//random number of 52 card decks shuffled
    void createPlayers(int playerNumber);//random orientation players created
    void Deal();
    void HitMe();
    void Stand();
    void Split();
    void DoubleDown();
    void addCardCount(int counter);
    int displayCardCounter();
    void newRound();
};


#endif
