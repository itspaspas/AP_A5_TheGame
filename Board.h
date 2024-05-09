#include "Plants.hpp"
#include "Cell.h"
#include <vector>

#ifndef Board_H
#define Board_H

class Board {
public:
    Board(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard); // Constructor
    ~Board();
    sf::Vector2f plantAt(sf::Vector2f mouseAddr, Plant* plant); // Plant a plant in a cell
    void removePlantAt(int row, int col); // Remove a plant from a cell
    bool isCellEmpty(int row, int col) const; // Check if a cell is empty
    bool isContain(sf::Vector2f mousePositionFloat);
    Cell* getCellAt(sf::Vector2f position);

private:
    int numRows;
    int numColumns;
    sf::Vector2f beginOfBoard;
    sf::Vector2f endOfBoard;
    std::vector<std::vector<Cell*>> cells; // 2D vector of cells
};


#endif
