//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_PLAYER_H
#define BLACKJACK_2_PLAYER_H


#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const string &name);

    virtual bool IsHitting() const;
    void Win();
    void Lose();
    void Push();
};


#endif //BLACKJACK_2_PLAYER_H
