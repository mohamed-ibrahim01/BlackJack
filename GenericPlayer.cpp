//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const string &name) :
m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBusted()
{
    return (GetTotal() > 21);
}

void GenericPlayer::Bust()
{
    cout << m_Name << " busts.\n\n";
}
