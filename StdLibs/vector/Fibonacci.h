#ifndef FIBONACCI_H
#define FIBONACCI_H

    #include <vector>

    class Fibonacci
    {
    public:
        Fibonacci(unsigned index);
        Fibonacci(const Fibonacci& other);
        Fibonacci& operator=(const Fibonacci& other);

        unsigned long getYield();
        static std::vector<unsigned long> getFibonacciSeries(unsigned index);
    private:
        unsigned long yield;
    };

#endif  /*FIBONACCI_H */
