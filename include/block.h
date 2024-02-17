#ifndef DA9EEC13_86FC_489F_B84B_C98D60140AF7
#define DA9EEC13_86FC_489F_B84B_C98D60140AF7

#include<vector>
#include<map>
#include"position.h"
#include "colors.h"

class Block {
    public:
        Block();
        int id;
        std::map<int, std::vector<Position>> cells;
        void Draw();
        void Move(int rows, int columns);
        std::vector<Position> GetCellPosition();
    private:
        int cellSize;
        int rotationState;
        int rowOffset;
        int columnOffset;
        std::vector<Color> colors;
};

#endif /* DA9EEC13_86FC_489F_B84B_C98D60140AF7 */
