#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
#include <vector>
#include <ciso646>

using namespace std;
using namespace ariel;

class Player
{
string name;
int stackSize;
int score = 0;
int wins = 0;
int loses = 0;
int draws = 0;
vector<card> cards;

public:
    Player(string);
    Player();
    card play();
    int stacksize();
    int cardesTaken();
    void addcard(card);
    void states(string,int);
    void printStates();
    string getName();
};

#endif