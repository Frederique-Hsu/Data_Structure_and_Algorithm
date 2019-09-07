#include "Fibonacci.h"

Fibonacci::Fibonacci(unsigned index)
{
    if (index <= 2)
    {
        /* f(1) = 1
         * f(2) = 1
         */
        yield = 1;
    }
    else
    {
        /* f(n) = f(n-1) + f(n-2) */
        yield = Fibonacci(index - 1).yield + Fibonacci(index - 2).yield;
    }
}

unsigned long Fibonacci::getYield()
{
    return yield;
}

Fibonacci::Fibonacci(const Fibonacci& other)
{
    yield = other.yield;
}

Fibonacci& Fibonacci::operator=(const Fibonacci& other)
{
    this->yield = other.yield;
    return *this;
}

std::vector<unsigned long> Fibonacci::getFibonacciSeries(unsigned index)
{
    std::vector<unsigned long> fibseries;
    for (unsigned n = 1; n <= index; ++n)
    {
        Fibonacci fib(n);
        fibseries.push_back(fib.getYield());
    }
    return fibseries;
}