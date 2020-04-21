//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_GENERICPLAYER_H
#define BLACKJACK_2_GENERICPLAYER_H

#include <iostream>
#include "Hand.h"

using namespace std;

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:
    GenericPlayer(const string& name);
    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;
    bool IsBusted();
    void Bust();

protected:
    string m_Name;
};


#endif //BLACKJACK_2_GENERICPLAYER_H
