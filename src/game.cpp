#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
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

    switch(keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_UP:
            MoveBlockUp();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
    }

}

void Game::MoveBlockLeft() {
    currentBlock.Move(0,-1);    
}

void Game::MoveBlockRight() {
    currentBlock.Move(0,1);    
}


void Game::MoveBlockUp() {
    currentBlock.Move(-1,0);    
}

void Game::MoveBlockDown() {
    currentBlock.Move(1,0);    
}
