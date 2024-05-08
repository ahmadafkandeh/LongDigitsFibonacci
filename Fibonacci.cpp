#include "Fibonacci.hpp"

#include <iostream>
#include <list>
#include <chrono>
#include <vector>
#include <functional>

#include "Utils.hpp"

numberType Fibonacci::fib_recursive(int n) {
    if (n <= 0)
    {
        return {0};
    }
    else if (n <= 2)
    {
        return {1};
    }
    return add(fib_recursive(n-1),fib_recursive(n-2));
}

numberType Fibonacci::fib_dynamic(int n) {
    std::vector<numberType> sol;

    if (n <= 0)
    {
        return {0};
    }

    if (n <=2)
    {
        return {1};
    }
    
    sol.push_back({1});
    sol.push_back({1});
    
    for(int i = 2 ; i < n; i++)
    {
        sol.push_back( add(sol.at(0), sol.at(1)));
        sol.erase(sol.begin());
    }
    return sol.at(1);
}

std::string Fibonacci::solution_toStr(const std::list<unsigned char> & obj) {
    std::string ret = "";
    ret.reserve(obj.size());
        for(auto it = obj.begin() ; it != obj.end() ; it++)
            ret.append (std::to_string(static_cast<int>((*it))));

    return ret;
}
