//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_DECK_H
#define BLACKJACK_2_DECK_H


#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
    Deck();

    void Populate();
    void Shuffle();
    void Deal(Hand &aHand);
    void AdditionalCards(GenericPlayer &aGenericPlayer);
};


#endif //BLACKJACK_2_DECK_H
