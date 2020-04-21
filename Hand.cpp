//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "Hand.h"

Hand::Hand()
{
    m_Cards.reserve(11);    // biggest hand to reach 21 ever
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card *aCard)
{
    m_Cards.push_back(aCard);
}

int Hand::GetTotal() const
{
    int total = 0;

    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }

    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
    {
        total += (*iter)->GetValue();
    }

    for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            if (total <= 11)
            {
                total += 10;
            }
        }
    }


    return total;
}

void Hand::Clear()
{
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++)
    {
        delete (*iter);
    }

    m_Cards.clear();
}
