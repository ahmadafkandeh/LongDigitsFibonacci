#ifndef LONG_DIGITS_FIBONACCI
#define LONG_DIGITS_FIBONACCI

#include <iostream>
#include <list>
#include <chrono>
#include <vector>
#include <functional>
class Fibonacci {
public:
	std::list<unsigned char> fib_recursive(int n);
	std::list<unsigned char> fib_dynamic(int n);
	std::string solution_toStr(const std::list<unsigned char> & obj);
};

#endif // LONG_DIGITS_FIBONACCI
