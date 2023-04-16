#include "game.hpp"
#include <string.h>
#include <algorithm>
#include <random>
#include <ciso646>
using namespace std;

Game ::Game(Player &p1, Player &p2) : firstPlayer(p1), secondPlayer(p2)
{

    // We create the deck.
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (i == 0)
            {
                card card(j, "Club");
                this->deck.push_back(card);
            }
            else if (i == 1)
            {
                card card(j, "Diamond");
                this->deck.push_back(card);
            }
            else if (i == 2)
            {
                card card(j, "Spade");
                this->deck.push_back(card);
            }
            else if (i == 3)
            {
                card card(j, "Heart");
                this->deck.push_back(card);
            }
        }
    }

    // We shuffle the deck using rand.
    random_device rd;
    mt19937 gen(rd());
    shuffle(deck.begin(), deck.end(), gen);

    // We deal the cards.
    bool whichOne = true;
    for (unsigned int i = 0; i <= 51; i++)
    {
        if (whichOne)
        {
            this->firstPlayer.addcard(deck.at(i));
            whichOne = false;
        }
        else
        {
            this->secondPlayer.addcard(deck.at(i));
            whichOne = true;
        }
    }
};

void Game ::playTurn()
{

   if (&firstPlayer == &secondPlayer)
    {
    throw std::runtime_error("Error: The two players cannot be the same");
    }
    else if (firstPlayer.stacksize() == 0 || secondPlayer.stacksize() == 0)
    {
    throw std::runtime_error("Error: At least one of the players has no cards");
    }


    numOfTurns++;
    card card1 = firstPlayer.play();
    card card2 = secondPlayer.play();
    deckSize += 2;
    if (resetPrinter)
    {
        resetPrinter = false;
    }

    // In case firstPlayer won
    // Define a function to print the card's value and type
    
    // In case firstPlayer wins
    if (card1.compareto(card2) == 1)
    {
        //printCard(card1);
        // Print the cards played
        string card1print = printCard(card1);
        string card2print = printCard(card2);
        cout << firstPlayer.getName() << " played " << card1print << endl;
        cout << secondPlayer.getName() << " played " << card2print << endl;
        
        // Update player states and game log
        firstPlayer.states("win", deckSize);
        firstPlayer.states("lose", 0);
        string lastTurn = "Congratulations!! " + firstPlayer.getName() + " has won!\n";
        gameLog += lastTurn;
        
        // Reset printer and deck size
        resetPrinter = true;
        deckSize = 0;
    }

    // In case secondPlayer wins
    else if (card1.compareto(card2) == -1)
    {
        //printCard(card2);
        // Print the cards played
        string card1print = printCard(card1);
        string card2print = printCard(card2);
        cout << firstPlayer.getName() << " played " << card1print << endl;
        cout << secondPlayer.getName() << " played " << card2print << endl;
        
        // Update player states and game log
        firstPlayer.states("lose", 0);
        firstPlayer.states("win", deckSize);
        string lastTurn = "Congratulations!! " + secondPlayer.getName() + " has won!\n";
        gameLog += lastTurn;
        
        // Reset printer and deck size
        resetPrinter = true;
        deckSize = 0;
    }
    else
    {
        // In case it's a draw
        if (this->firstPlayer.stacksize() == 0 || this->secondPlayer.stacksize() == 0)
        {
            this->firstPlayer.states("draw", this->deckSize / 2);
            this->secondPlayer.states("draw", this->deckSize / 2);
            return;
        }

        // This is the covered card
        this->firstPlayer.play();
        this->secondPlayer.play();

        this->numOfTurns++;
        this->deckSize = this->deckSize + 2;

        // In case that at least one of the players doesn't have cards
        if (this->firstPlayer.stacksize() == 0 || this->secondPlayer.stacksize() == 0)
        {
            this->firstPlayer.states("draw", this->deckSize / 2);
            this->secondPlayer.states("draw", this->deckSize / 2);
            return;
        }

        // In case both players have cards
        this->firstPlayer.states("draw", 0);
        this->secondPlayer.states("draw", 0);
        this->lastTurn = this->lastTurn + this->firstPlayer.getName() + " played " + card1print + "\n" +
                         this->secondPlayer.getName() + " played " + card2print + "\n" +
                         "It's a tie!";
        this->resetPrinter = false;
        this->playTurn();
    }
};


string Game ::printCard(card card) {
    string cardPrint;
    switch (card.getValue()) {
        case 1:
            cardPrint = "Ace";
            break;
        case 11:
            cardPrint = "Jack";
            break;
        case 12:
            cardPrint = "Queen";
            break;
        case 13:
            cardPrint = "King";
            break;
        default:
            cardPrint = to_string(card.getValue());
            break;
    }
    cardPrint += " of " + card.getType();
    return cardPrint;
}

void Game ::printLastTurn()
{
    cout << this->lastTurn << endl;
};

void Game ::printStats()
{
    this->firstPlayer.printStates();
    this->secondPlayer.printStates();
};

void Game ::printLog()
{
    cout << this->gameLog << endl;
};

void Game ::playAll()
{
    while (this->firstPlayer.stacksize() != 0 && this->secondPlayer.stacksize() != 0)
    {
        this->playTurn();
    }
};

void Game ::printWiner()
{
    if (this->numOfTurns < 26)
    {
        cout << "This game didn't over..." << endl;
        return;
    }

    if (this->firstPlayer.cardesTaken() > this->secondPlayer.cardesTaken())
    {
        cout << "The winner of this game is: " << this->firstPlayer.getName() << endl;
    }
    else if (this->firstPlayer.cardesTaken() < this->secondPlayer.cardesTaken())
    {
        cout << "Congratulation, the winner of this game is: " << this->secondPlayer.getName() << endl;
    }
    // In case of a draw
    else
    {
        throw std::runtime_error("Rhis is a TIE!");
    }
};