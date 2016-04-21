#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <string>
#include <vector>
struct card
{
    int value;
    int suit;
    std::string name;
    int counter;
};

struct player
{
    std::string name;
    int orientation;//1 defensive, 2 normal, 3 aggressive playstyle
    int handValue;
    std::vector<card> hand;
    int totalMoney;
    int bet;
    bool isSplit;
    int handValue2 = 0;
    std::vector<card> hand2;
    int bet2 = 0;
    bool stand = false;
};

struct dealer
{
    int handValue;
    std::vector<card> hand;
    bool stand = false;
};

class Blackjack
{
private:
dealer Dealer;
std::vector<card*> deck;
std::vector<player> players;
int cardCounter;

public:
    Blackjack();
    ~Blackjack();
    void buildDeck(int deckNumber);//random number of 52 card decks shuffled
    void shuffleDeck(int deckNumber);
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
