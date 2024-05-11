#include "Plants.hpp"
#include "Cell.h"
#include <vector>

#ifndef Board_H
#define Board_H

class Board {
public:

    Board(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard);
    ~Board();
    sf::Vector2f plantAt(sf::Vector2f mouseAddr, Plant* plant);
    bool isCellEmpty(sf::Vector2f addr);
    bool isContain(sf::Vector2f mousePositionFloat);

private:

    sf::Vector2f beginOfBoard;
    sf::Vector2f endOfBoard;
    std::vector<std::vector<Cell*>> cells;
};


#endif
