//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "Deck.h"
#include <algorithm>

Deck::Deck()
{
    m_Cards.reserve(52);
}

void Deck::Populate()
{
    for (int r = Card::ACE; r < Card::KING; ++r)
    {
        for (int s = Card::CLUB; s < Card::SPADE; ++s)
        {
            m_Cards.push_back(new Card(static_cast<Card::rank> (r), static_cast<Card::suit> (s)));
        }
    }
}

void Deck::Shuffle()
{
    srand(static_cast<unsigned int> (time(0)));
    random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand &aHand)
{
    if (!(m_Cards.empty()))
    {
        Shuffle();
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "out of cards\n";
    }
}

void Deck::AdditionalCards(GenericPlayer &aGenericPlayer)
{
    while (!aGenericPlayer.IsBusted() && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);
        cout << aGenericPlayer;

        if (aGenericPlayer.IsBusted())
        {
            aGenericPlayer.Bust();
        }
    }
}
