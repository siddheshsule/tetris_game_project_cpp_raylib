#ifndef F7DDD0E1_CD54_4C82_9B9B_E12217DA1DB1
#define F7DDD0E1_CD54_4C82_9B9B_E12217DA1DB1

#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        bool gameOver;
        int score;
        Music music;

    private:
        bool IsBlockOutside();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void MoveBlockLeft();
        void MoveBlockRight();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int rowsMoved);
        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;  
        Sound rotateSound;
        Sound clearSound; 
};

#endif /* F7DDD0E1_CD54_4C82_9B9B_E12217DA1DB1 */
