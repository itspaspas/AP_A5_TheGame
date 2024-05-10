#include <vector>
#include "Plants.hpp"
#include "Zombie.h"


#ifndef cell_H
#define cell_H

class Plant;

class Cell {
public:
    Cell(sf::Vector2f beginOfCell , sf::Vector2f endOfCell);// Constructor (initialize as empty)
    sf::Vector2f setPlant(Plant* plant); // Set the plant in the cell
    void removePlant(); // Remove the plant from the cell
    bool isEmpty() const; // Check if the cell is empty
    bool isContainAddr(sf::Vector2f Addr);
    Plant* getPlant() const; // Get the plant in the cell
    sf::Vector2f getCellMidPosition();
    void getFull();

private:
    sf::Vector2f beginOfCell;
    sf::Vector2f endOfCell;
    bool empty;
    Plant* plant; // Pointer to the plant (nullptr if empty)
};


#endif
