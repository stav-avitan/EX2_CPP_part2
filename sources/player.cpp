#include "player.hpp"
#include "card.hpp"
#include <ciso646>


Player ::Player(string name)
{
    this->name = name;
    this->stackSize = 0;
};

Player ::Player()
{
    this->name = "";
    this->stackSize = 0;
};

int Player::stacksize()
{
    return this->stackSize;
};

int Player::cardesTaken()
{
    return this->score;
};

void Player::addcard(card extra)
{
    this->cards.push_back(extra);
    this->stackSize++;
};

string Player ::getName() { return this->name; };

 //////////////////////////////////////////////////////////////////////////////////////////////
card Player::play()
{
    card tempcard;
    if (!cards.empty()) {
        tempcard = cards.back();
        cards.pop_back();
        stackSize--;
    }
    return tempcard;
}

void Player::states(string resOFTheRound, int takencards) {
    if (resOFTheRound == "lose") {
        loses++;
    } else {
        score += takencards;
        if (resOFTheRound == "win") {
            wins++;
        } else if (resOFTheRound == "draw") {
            draws++;
        }
    }
}

void Player::printStates() {
    cout << name << " won " << score << " cards!" << endl;
    cout << "Wins: " << wins << " (" << static_cast<double>(wins) / 26 * 100 << "%)" << endl;
    cout << "Draws: " << draws << " (" << static_cast<double>(draws) / 26 * 100 << "%)" << endl;
    cout << "Losses: " << loses << " (" << static_cast<double>(loses) / 26 * 100 << "%)" << endl;
}





