//
// Created by Mohammed Ibrahim on 11/16/19.
//

#ifndef BLACKJACK_2_GAME_H
#define BLACKJACK_2_GAME_H

#include <vector>
#include <iostream>
#include "Deck.h"
#include "House.h"
#include "Player.h"

using namespace std;

class Game {
public:
    Game(const vector<string> &names);

    void Play();

private:
    void DeclareWinners();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};


#endif //BLACKJACK_2_GAME_H
