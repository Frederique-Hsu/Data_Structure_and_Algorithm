/*!
 *  \file   SQuare.cpp
 *  \brief  Implement the class Square.
 *
 */

#include "Square.hpp"

#include <cmath>

Square::Square(double edge) : m_edge{edge}
{
}

double Square::getEdge() const
{
    return m_edge;
}

double Square::getArea() const
{
    return m_edge * m_edge;
}

double Square::getPerimeter() const
{
    return 4 * m_edge;
}

void Square::print(std::ostream& out) const
{
    out << "(Square " << getEdge() << ")";
}

bool Square::operator<(const Square& rhs) const
{
    return (getEdge() < rhs.getEdge());
}

bool Square::operator==(const Square &rhs) const
{
    return (std::fabs(getEdge() - rhs.getEdge()) <= 0.0001);
}

std::ostream& operator<<(std::ostream& out, const Square& rhs)
{
    rhs.print(out);
    return out;
}
