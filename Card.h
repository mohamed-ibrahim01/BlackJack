//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_CARD_H
#define BLACKJACK_2_CARD_H

#include <iostream>
using namespace std;

class Card
{
    friend ostream& operator<<(ostream& os, const Card& aCard);

public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum suit {CLUB, DIAMOND, HEART, SPADE};

    Card(rank r, suit s);

    void Flip();
    int GetValue();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};


#endif //BLACKJACK_2_CARD_H
