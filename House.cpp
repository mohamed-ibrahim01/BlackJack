//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "House.h"

House::House() : GenericPlayer("House")
{}

bool House::IsHitting() const
{
    return GetTotal() <= 16;
}

void House::FlipFirstCard()
{
    m_Cards[0]->Flip();
}
