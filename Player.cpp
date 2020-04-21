//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "Player.h"


Player::Player(const string &name) : GenericPlayer(name)
{}

bool Player::IsHitting() const
{
    char response;
    cout << m_Name << " Do you want to hit? (Y/N): ";
    cin >> response;

    return response == 'Y' || response == 'y';
}

void Player::Win()
{
    cout << m_Name << " wins.\n";
}

void Player::Lose()
{
    cout << m_Name << " lose.\n";
}

void Player::Push()
{
    cout << m_Name << " push.\n";
}
