
#include "Cell.h"

Cell::Cell(sf::Vector2f _beginOfCell , sf::Vector2f _endOfCell){
    this->beginOfCell = _beginOfCell;
    this->endOfCell = _endOfCell;
    empty = true;
}

bool Cell::isContainAddr(sf::Vector2f Addr){
    return ((this->beginOfCell.x < Addr.x < this->endOfCell.x ) && 
            (this->beginOfCell.y < Addr.y < this->endOfCell.y));
}

void Cell::setPlant(Plant* plant){
    this->plant = plant;
    empty = false;
}

void Cell::removePlant() {
    delete this->plant;
    empty = true;
}

bool Cell::isEmpty() const {
    return empty;
}

Plant* Cell::getPlant() const{
    return this->plant;
}
