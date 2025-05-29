/*!
 *  \file       morton_code.cpp
 *  \brief      
 *  
 */


#include "morton_code.hpp"

#include <algorithm>


/*!
 *  \brief  Expands a 10-bit integer into 30-bits by inserting 2 zeros after each bit.
 */
unsigned int MortonCode::expandBits(unsigned int v)
{
    v = (v * 0x0001'0001u) & 0xFF00'00FFu;
    v = (v * 0x0000'0101u) & 0x0F00'F00Fu;
    v = (v * 0x0000'0011u) & 0xC30C'30C3u;
    v = (v * 0x0000'0005u) & 0x4924'9249u;
    return v;
}

/*!
 *  \brief  Calculate a 30-bit Morton code for the given 3D point located within the unit cube [0, 1]
 */
unsigned int MortonCode::morton3D(float x_coord, float y_coord, float z_coord)
{
    using std::min;
    using std::max;

    x_coord = min(max(x_coord * 1024.0f, 0.0f), 1023.0f);
    y_coord = min(max(y_coord * 1024.0f, 0.0f), 1023.0f);
    z_coord = min(max(z_coord * 1024.0f, 0.0f), 1023.0f);

    unsigned int x_bits = expandBits((unsigned int)x_coord);
    unsigned int y_bits = expandBits((unsigned int)y_coord);
    unsigned int z_bits = expandBits((unsigned int)z_coord);

    return (x_bits << 2) + (y_bits << 1) + z_bits;
}