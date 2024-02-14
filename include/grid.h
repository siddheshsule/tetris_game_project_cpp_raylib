#ifndef C1B482F0_8AE3_4A4E_9C4C_4D1C30567014
#define C1B482F0_8AE3_4A4E_9C4C_4D1C30567014

#include<vector>
#include<raylib.h>

class Grid{
    public:
        Grid();
        int grid[20][20];
        void Print();
        void Initialize();
        void Draw();

    private:        
        int numRows;
        int numCols;
        int cellSize;        
        std::vector<Color> colors;
};

#endif /* C1B482F0_8AE3_4A4E_9C4C_4D1C30567014 */
