#include "Cell.h"

Cell::Cell(sf::Vector2f _beginOfCell , sf::Vector2f _endOfCell){
    this->beginOfCell = _beginOfCell;
    this->endOfCell = _endOfCell;
    empty = true;
}

bool Cell::isContainAddr(sf::Vector2f Addr){
    return (this->beginOfCell.x <= Addr.x && Addr.x < this->endOfCell.x &&
            this->beginOfCell.y <= Addr.y && Addr.y < this->endOfCell.y);
}

sf::Vector2f Cell::setPlant(Plant* plant){
    this->plant = plant;
    sf::Vector2f position;
    position.x = endOfCell.x - beginOfCell.x;
    position.y = endOfCell.y - beginOfCell.y;
    plant->setPosition(position);
    return position;
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

sf::Vector2f Cell::getCellMidPosition(){
    sf::Vector2f midpoint;
    midpoint.x = (endOfCell.x + beginOfCell.x)/2;
    midpoint.y = (endOfCell.y + beginOfCell.y)/2;
    return midpoint;
}
