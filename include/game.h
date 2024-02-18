#ifndef F7DDD0E1_CD54_4C82_9B9B_E12217DA1DB1
#define F7DDD0E1_CD54_4C82_9B9B_E12217DA1DB1

#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game {
    public:
        Game();
        ~Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockUp();
        void MoveBlockDown();
        Grid grid;
        bool gameOver;

    private:
        bool IsBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;   
};

#endif /* F7DDD0E1_CD54_4C82_9B9B_E12217DA1DB1 */
