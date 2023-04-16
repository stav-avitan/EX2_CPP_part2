#ifndef card_HPP
#define card_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ciso646>

using namespace std;

namespace ariel
{

    class card
    {
    int newValOfcard;
    string newKindOfcard;

    public:
        card(int valOfcard,string kindOfcard);
        card();
        int getValue();
        string getType();
        int compareto(card secCaed);
    };

}

#endif