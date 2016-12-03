//
// Created by Jonathan Gerber on 12/2/16.
//

#ifndef CPP_HAPPY_FUN_TIME_CARDDECK_HPP
#define CPP_HAPPY_FUN_TIME_CARDDECK_HPP

#include <ostream>

enum class Suits {
    HEART, DIAMOND, CLUB, SPADE
};

enum class Cards {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

struct CardValue {
    Cards m_card;
    int m_value;
    std::string m_name;
};

struct CardSuit {
    Suits m_suit;
    int m_value;
    std::string m_name;
};

struct Card {
    Cards m_card;
    Suits m_suit;

    std::pair<int,int> to_pair() const;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);

};

class CardDeck {


};


#endif //CPP_HAPPY_FUN_TIME_CARDDECK_HPP
