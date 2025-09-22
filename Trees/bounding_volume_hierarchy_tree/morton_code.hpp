/*!
 *  \file       morton_code.hpp
 *  \brief      Define and implement the Morton Code.
 *  
 */


#pragma once


class MortonCode
{
public:
    static unsigned int expandBits(unsigned int v);
    static unsigned int morton3D(float x_coord, float y_coord, float z_coord);
};