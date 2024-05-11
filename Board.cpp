#include "Board.h"

Board::~Board() {
    for (auto& row : cells) {
        for (auto cell : row) {
            delete cell;
        }
    }
}

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
        for(int j = 0 ; j < 9 ; j++){
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

sf::Vector2f Board::plantAt(sf::Vector2f mouseAddr ,Plant* plant) {
    for(auto rowCell : this->cells){
        for(Cell* cell : rowCell){
            if(cell->isEmpty() && cell->isContainAddr(mouseAddr)){
                cell->getFull();
                plant->assignCell(cell);
                return cell->setPlant(plant);
            }
        }
    }
} 

bool Board::isContain(sf::Vector2f mousePositionFloat){
    return ((mousePositionFloat.x > this->beginOfBoard.x) && 
            (mousePositionFloat.x < this->endOfBoard.x) && 
            (mousePositionFloat.y > this->beginOfBoard.y) && 
            (mousePositionFloat.y < this->endOfBoard.y));}

void Board::removePlantAt(int row, int col) {
    if (row < numRows && col < numColumns) {
        cells[row][col]->removePlant();
    }
}

bool Board::isCellEmpty(sf::Vector2f addr){
    for(auto cellRow : cells){
        for(auto cell : cellRow){
            if(cell->isContainAddr(addr)){
                if(cell->isEmpty())
                    return true;
            }
        }
    }
    return false;
}

Cell* Board::getCellAt(sf::Vector2f position) {
    float cellWidth = (endOfBoard.x - beginOfBoard.x) / numColumns;
    float cellHeight = (endOfBoard.y - beginOfBoard.y) / numRows;

    int column = static_cast<int>((position.x - beginOfBoard.x) / cellWidth);
    int row = static_cast<int>((position.y - beginOfBoard.y) / cellHeight);

    // Check if the calculated row and column are within the bounds of the cell grid
    if (row >= 0 && row < numRows && column >= 0 && column < numColumns) {
        return cells[row][column];
    }

    return nullptr; // Return nullptr if the position is out of the board's bounds
}

// int Board::getRowOfPlant(sf::Vector2f plantPosition) {
//     Cell* cell = getCellAt(plantPosition);
//     if (cell != nullptr) {
//         float cellHeight = (endOfBoard.y - beginOfBoard.y) / numRows;
//         int row = static_cast<int>((plantPosition.y - beginOfBoard.y) / cellHeight);
//         return row;
//     }
//     return -1; // Return -1 if the plant is not found or the position is out of bounds
// }