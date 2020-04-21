//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_HOUSE_H
#define BLACKJACK_2_HOUSE_H


#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
    House();

    bool IsHitting() const override;
    void FlipFirstCard();
};


#endif //BLACKJACK_2_HOUSE_H
