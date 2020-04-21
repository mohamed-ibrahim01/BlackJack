//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_HAND_H
#define BLACKJACK_2_HAND_H

#include <vector>
#include "Card.h"

using namespace std;

class Hand
{
public:
    Hand();
    ~Hand();

    void Add(Card* aCard);
    int GetTotal() const;
    void Clear();

protected:
    vector<Card*> m_Cards;
};


#endif //BLACKJACK_2_HAND_H
