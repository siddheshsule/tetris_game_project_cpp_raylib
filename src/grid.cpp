#include <iostream>
#include "colors.h"

#include "grid.h"

Grid::Grid()
{
   numRows = 20;
   numCols = 10;
   cellSize = 30;
   
   
   Initialize();
   colors = GetCellColors();
}

void Grid::Initialize() {
    for(int row =0; row < numRows;++row) {
        for(int column =0; column < numCols;++column) {
            grid[row][column] = 0;
        }
    }
}

void Grid::Draw()
{
    for(int row = 0; row < numRows; ++row) {
        for(int column =0; column < numCols; ++column) {
            auto cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1 , cellSize - 1,cellSize - 1, colors.at(cellValue));
        }
    }
}

void Grid::Print() {

    for(int row =0; row < numRows;++row) {
        for(int column =0; column < numCols;++column) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }

}