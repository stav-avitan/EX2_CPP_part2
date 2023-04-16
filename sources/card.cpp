#include "card.hpp"
#include <ciso646>
using namespace ariel;



//Default constructor
card::card (){
    this->newKindOfcard = "this card worth nothing!";
    this->newValOfcard = 0;
};


//Constructor for building a card
card::card (int valOfcard, string kindOfcard){
    this->newKindOfcard = kindOfcard;
    this->newValOfcard = valOfcard;
};

//return the kind of the card
string card::getType(){
    return this->newKindOfcard;
}

//return the value of the card
int card::getValue(){
    return this->newValOfcard;
}

//compare between two cards: if the first bigger then the second it return 1, 
//if the second bigger then the first it return -1, 
//If they are equal it returns 0.
int card::compareto(card secCaed) {
    int valOfsecondcard = secCaed.newValOfcard;
    int valOfFirstcard = this->newValOfcard;

    if (valOfsecondcard == 1) {
        if (valOfFirstcard == 2 || valOfFirstcard == 1) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else if (valOfFirstcard == 1) {
        if ( valOfsecondcard == 1 || valOfsecondcard == 2) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else if (valOfsecondcard > valOfFirstcard) {
        return -1;
    }
     else if (valOfFirstcard > valOfsecondcard) {
        return 1;
    }
    else {
        return 0;
    }
};
