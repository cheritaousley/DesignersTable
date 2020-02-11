// code - implementation
#include "grtypes.h"
#include <stdlib.h>
#include <stdio.h>

bool PB_init(PixelBuffer &pb, size_t rows, size_t columns)
{
    pb.height = rows;
    pb.width = columns;
    pb.data = (uint32_t *)malloc(sizeof(uint32_t) * rows * columns);

    return true;
}

bool PB_clear(PixelBuffer &pb)
{
    free(pb.data);
    pb.height = 0;
    pb.width = 0;

    return true;
}

bool PB_setPixel(PixelBuffer &pb, size_t x, size_t y, uint32_t c)
{
    size_t offset = (y * pb.width) + x;
    pb.data[offset] = c;

    return true;
}

void PB_getPixel(PixelBuffer &pb)
{
    return pb.data;
}

bool PB_HorizontalLine(PixelBuffer &pb,
                       const size_t row, const size_t col, const size_t numberOfPixels,
                       const uint32_t c)
{
    for (int idx = col; idx < col + numberOfPixels; idx++)
    {
        PB_setPixel(pb, idx, row, c);
    }

    return true;
}

void main()
{
    // allocate an instance of the structure on the stack
    PixelBuffer pb;

    // initialize it
    bool success = PB_init(pb, 320, 240);

    // clear the thing up
    PB_clear(pb);
}