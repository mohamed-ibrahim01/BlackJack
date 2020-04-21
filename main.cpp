#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "GenericPlayer.h"
#include "Game.h"

using namespace std;

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

/**
 * application main function
 *
 * game loop is here
 *
 */

int main() {

    // get the number of players
    int numPlayers = 0;
    while(numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1-7): ";
        cin >> numPlayers;
    }

    // get each player name
    string name;
    vector<string> names;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Player name: ";
        cin >> name;
        names.push_back(name);
    }


    Game game(names);   // create Game object instance

    // begin the game loop
    char again = 'Y';
    while (again == 'Y' || again == 'y')
    {
        game.Play();

        cout << "Do you want to play again? (Y/N): ";
        cin >> again;
    }

    cout << "Exit the game.";

    return 0;
}

/**
 * overload the << operator so we can  send Card object to the standered output directly
 * and we can define how to display it
 *
 * this function is a declared as friend function in Card class
 * so it can uses its private member variables
 *
 * it contains the suits and ranks shape to be displayed
 */

ostream& operator<<(ostream& os, const Card& aCard)
{
    string ranks[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string suits[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
    {
        os << ranks[aCard.m_Rank] << suits[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}


/**
 * overload the << operator so we can send GenericPlayer object (or any derived class)
 * to the standered output directly
 *
 * this function is a declared as friend function in Card class
 * so it can uses its private member variables
 *
 * it contains the suits and ranks shape to be displayed
 */
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    vector<Card*>::const_iterator iter;
    for (iter = aGenericPlayer.m_Cards.begin(); iter != aGenericPlayer.m_Cards.end(); ++iter)
    {
        os << *(*iter) << "\t";
    }

    if (aGenericPlayer.GetTotal() != 0)
    {
        os << "(" << aGenericPlayer.GetTotal() << ")";
    }

    os << endl;

    return os;
}
