#include <vector>
#include "Plants.hpp"
#include "Zombie.h"


#ifndef cell_H
#define cell_H


class Cell {
public:
    Cell(sf::Vector2f beginOfCell , sf::Vector2f endOfCell);// Constructor (initialize as empty)
    void setPlant(Plant* plant); // Set the plant in the cell
    // void setZombie(Zombie* zombie); // Set the zombie in the cell
    void removePlant(); // Remove the plant from the cell
    // void removeZombie(); // Remove the zombie from the cell
    bool isEmpty() const; // Check if the cell is empty
    bool isContainAddr(sf::Vector2f Addr);
    Plant* getPlant() const; // Get the plant in the cell
    // Zombie* getZombie() const; // Get the zombie in the cell

private:
    sf::Vector2f beginOfCell;
    sf::Vector2f endOfCell;
    bool empty;
    Plant* plant; // Pointer to the plant (nullptr if empty)
    // Zombie* zombie; // Pointer to the zombie (nullptr if empty)
};


#endif