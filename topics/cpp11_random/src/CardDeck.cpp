//
// Created by Jonathan Gerber on 12/2/16.
//

#include "CardDeck.hpp"

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << "m_card: " << card.m_card << " m_suit: " << card.m_suit;
    return os;
}
