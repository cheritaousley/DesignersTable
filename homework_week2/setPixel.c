#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// Implement setPixel. Pass it some chunk of memory, row, col and some value.
// the memory could be a grid, then take the value and place it in the row and column passed.
// similiar to taking an array and setting the 50th position to 227
// This is just thinking of it as a grid and figuring out the offse
// offset = address = index
// offset = (row x rowSize) + column
// when using struct like this, must write 'struct colorCode'
// struct colorCode
// {
//     uint8_t r;
//     uint8_t g;
//     uint8_t b;
// };
// can also be written like this and then use 'colorCode'
typedef struct colorCode
{
    int r;
    int g;
    int b;
} colorCode;

// typedef struct PixelBuffer{
// size_t rows;
// size_t columns;
// };

void setPixel(colorCode *grid, int row, int col, colorCode val)
{
    int rowSize = 8;
    int offset = (row * rowSize) + col;
    grid[offset] = val;
    printf("%d, %d, %d", grid[offset].r, grid[offset].g, grid[offset].b);
}

bool PB_HorizontalLine(PixelBuffer &pb, const size_t row, const size_t numberOfPixels, uint32_t c)
{
    for (int idx = col; idx < col + numberOfPixels; idx++)
    {
        PB_setPixel(pb, idx, row, c);
    }
    return true;
};

int main(void)
{
    struct colorCode grid[80];
    struct colorCode val = {255, 0, 0};
    int row = 4;
    int col = 3;
    setPixel(grid, row, col, val);
}