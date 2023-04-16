#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "player.hpp"
#include <ciso646>

using namespace std;
using namespace ariel;

class Game
{
    Player& firstPlayer;
    Player& secondPlayer;
    vector<card> deck;
    int numOfTurns = 0;
    int deckSize;
    string gameLog;
    string lastTurn;
    bool resetPrinter = true;
    string type;
    string card1print;
    string card2print;
    

public:
    Game(Player& firstPlayer, Player& secondPlayer);
    void playTurn();
    void printLastTurn();
    void printStats();
    void printLog();
    void printWiner();
    void playAll();
    void shuffleDeck();
    string printCard(card card);
};

#endif