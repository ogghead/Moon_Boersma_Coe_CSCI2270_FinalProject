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
    myGame.buildDeck(1);
    myGame.shuffleDeck(1);
    return 0;
}
