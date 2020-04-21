//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "Card.h"


Card::Card(Card::rank r, Card::suit s) :
m_Rank(r),
m_Suit(s)
{
    m_IsFaceUp = true;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

int Card::GetValue()
{
    if (m_IsFaceUp)
    {
        if(m_Rank > 10)
            return 10;
        else
            return m_Rank;
    }
    else
    {
        return 0;
    }
}
