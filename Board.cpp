#include "Board.h"

float calculateHeight(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard){
    return (endOfBoard.y - beginOfBoard.y)/5;
}

float calculateWeight(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard){
    return (endOfBoard.x - beginOfBoard.x)/9;
}

Board::Board(sf::Vector2f _beginOfBoard , sf::Vector2f _endOfBoard){
    this->beginOfBoard = _beginOfBoard;
    this->endOfBoard = _endOfBoard;
    float cellHeight = calculateHeight(this->beginOfBoard ,this->endOfBoard);
    float cellWeight = calculateWeight(this->beginOfBoard ,this->endOfBoard);
    for(int i = 0 ; i < 5 ; i++){
        std::vector<Cell*> rowCell;
        for(int j = 0 ; j = 9 ; j++){
            sf::Vector2f beginOfCell;
            beginOfCell.x = beginOfBoard.x + j*cellWeight;
            beginOfCell.y = beginOfBoard.y + i*cellHeight;
            sf::Vector2f endOfCell;
            endOfCell.x = beginOfCell.x + cellWeight;
            endOfCell.y = beginOfCell.y + cellHeight;
            rowCell.push_back(new Cell(beginOfCell , endOfCell));
        }
        cells.push_back(rowCell);
    }
}

void Board::plantAt(sf::Vector2f mouseAddr ,Plant* plant) {
    for(auto rowCell : cells){
        for(auto cell : rowCell){
            if(cell->isEmpty() && cell->isContainAddr(mouseAddr))
                cell->setPlant(plant);
        }
    }
} 

// void Board::removePlantAt(int row, int col) {
//     cells[row][col].removePlant();
// }

// bool Board::isCellEmpty(int row, int col) const {
//     return cells[row][col].isEmpty();
// }