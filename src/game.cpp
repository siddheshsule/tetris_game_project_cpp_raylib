#include <random>
#include<iostream>
#include "game.h"

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
}

Game::~Game()
{
}

Block Game::GetRandomBlock() {
    if(blocks.empty()) {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return {LBlock(), JBlock(), IBlock(), ZBlock(), OBlock(),SBlock(), TBlock()};
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();

}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();    
    if(gameOver && keyPressed != 0) {
        gameOver = false;
        Reset();
    }
    switch(keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            RotateBlock();
            break;                
    }

}

void Game::MoveBlockLeft() {
    if(!gameOver) {
        currentBlock.Move(0,-1);
        if(IsBlockOutside()|| BlockFits() == false) {
            currentBlock.Move(0,1);
        }
    }
}

void Game::MoveBlockRight() {
    if(!gameOver) {
        currentBlock.Move(0,1); 
        if(IsBlockOutside()|| BlockFits() == false) {
            currentBlock.Move(0,-1);
        }   
    }
}

void Game::MoveBlockDown() {
    if(!gameOver) {
        currentBlock.Move(1,0); 
        if(IsBlockOutside() || BlockFits() == false) {
            currentBlock.Move(-1,0);
            LockBlock();
        }   
    }
}

void Game::RotateBlock()
{
    if(!gameOver) {
        currentBlock.Rotate();
        if(IsBlockOutside()|| BlockFits() == false) {
            currentBlock.UndoRotation();
        }
    }
}

bool Game::IsBlockOutside()
{    
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item : tiles) {
        if(grid.IsCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}


void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false) {
        gameOver = true;
    }    
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles) {
        if(grid.IsCellEmpty(item.row, item.column) == false) {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
