//
// Created by Mohammed Ibrahim on 11/16/19.
//

#include "Game.h"

Game::Game(const vector<string> &names)
{
    // populate vector of Players
    vector<string>::const_iterator iter;
    for (iter = names.begin(); iter != names.end(); ++iter)
    {
        m_Players.push_back(Player(*iter));
    }

    // populate Deck of Cards
    m_Deck.Populate();
}

void Game::Play()
{
    vector<Player>::iterator iter;

    // deal two Cards to each player and the house
    for (int i = 0; i < 2; ++i)
    {
        for (iter = m_Players.begin(); iter != m_Players.end(); ++iter)
        {
            m_Deck.Deal(*iter);
        }
        m_Deck.Deal(m_House);
    }

    // flip the house's first card then display all all players' cards
    m_House.FlipFirstCard();    // it has a hidden card now

    for (iter = m_Players.begin(); iter != m_Players.end(); ++iter)
    {
        cout << *iter;
    }
    cout << m_House;

    // deal additional cards to each Player if he wants to hit and he not yet busted and display his hand
    for (iter = m_Players.begin(); iter != m_Players.end(); ++iter)
    {
        m_Deck.AdditionalCards(*iter);
    }


    // flip the house's first card and display his hand
    m_House.FlipFirstCard();
    cout << m_House;

    // offer additional cards to house till its hand is greater than 16 or it busts
    m_Deck.AdditionalCards(m_House);

    // declare the winners
    DeclareWinners();

    // clear all hands after each round
    for (iter = m_Players.begin(); iter != m_Players.end(); ++iter)
    {
        iter->Clear();
    }
    m_House.Clear();
}

void Game::DeclareWinners()
{
    vector<Player>::iterator iter;
    // if House busted any player who didn't bust wins
    if (m_House.IsBusted())
    {
        for (iter = m_Players.begin(); iter != m_Players.end(); ++iter)
        {
            if (!(iter->IsBusted()))
            {
                iter->Win();
            }
            else
            {
                iter->Lose();
            }
        }
    }

    // if House didn't bust check Players who didn't bust
    else
    {
        for (iter = m_Players.begin(); iter != m_Players.end(); ++iter)
        {
            if (!(iter->IsBusted()))
            {
                // if have total bigger than the House's they wins
                if (iter->GetTotal() > m_House.GetTotal())
                {
                    iter->Win();
                }
                // if have total smaller than the House's they lose
                else if (iter->GetTotal() < m_House.GetTotal())
                {
                    iter->Lose();
                }
                // if have total equal to the House's they pushes
                else
                {
                    iter->Push();
                }
            }
        }
    }
}
