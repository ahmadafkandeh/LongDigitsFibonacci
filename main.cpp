#include "Fibonachi.hpp"
#include "Utils.hpp"

#include <iostream>

#define RECURSIVE_LIMIT 50

int main()
{
    Fibonachi fib;
    TimeMeasure tim;
    int number;

    std::cout << "Enter an integer:";
    std::cin >> number;

    if (number > RECURSIVE_LIMIT)
    {
        std::cout << "number is too big for recursive calculation! \n";
    }

    if (number < RECURSIVE_LIMIT)
    {
        std::cout << "Calculating the fibonachi for given number in recursive mode:\n";
        tim.start();
        auto ret = fib.fib_recursive(number);
        auto timeStr = tim.stop();
        std::cout << "result: " << fib.solution_toStr(ret) << std::endl;
        std::cout << timeStr << std::endl;
    }

    std::cout << "Calculating the fibonachi for given number in dynamic mode:\n";
    tim.start();
    auto ret = fib.fib_dynamic(number);
    auto timeStr = tim.stop();
    std::cout << "result: " << fib.solution_toStr(ret) << std::endl;
    std::cout << timeStr << std::endl;

    return 0;
}