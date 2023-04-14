/*!
 *  \file   Square.hpp
 *  \brief  Define a new class Square
 *
 */

#ifndef SQUARE_HPP
#define SQUARE_HPP

    #include <iostream>

    class Square
    {
    public:
        explicit Square(double edge = 0.0);
    private:
        double m_edge;
    public:
        double getEdge() const;
        double getArea() const;
        double getPerimeter() const;
        void print(std::ostream& out = std::cout) const;
        bool operator<(const Square& rhs) const;
        bool operator==(const Square& rhs) const;
    };

    std::ostream& operator<<(std::ostream& out, const Square& rhs);

#endif  /* SQUARE_HPP */
