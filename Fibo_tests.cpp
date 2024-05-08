#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "Utils.hpp"
#include "Fibonacci.hpp"

TEST_CASE("Checking sumc function ", "[sumc]")
{
    unsigned char a,b,c;
    unsigned char res;
    SECTION("adding two zeros without carry, result should be 0 without carry")
    {
        a = b = c = 0;
        res = sumc(a, b, c);

        REQUIRE(c == 0);
        REQUIRE (res == 0);
    }

    SECTION("adding two zeros with carry, result should be 1, without carry")
    {
        a = b = 0;
        c = 1;

        res = sumc(a, b, c);

        REQUIRE(c == 0);
        REQUIRE (res == 1);
    }

    SECTION("adding 8 with 9 without carry, result should be 7, with carry")
    {
        a = 8;
        b = 9;
        c = 0;

        res = sumc(a, b, c);

        REQUIRE(c == 1);
        REQUIRE (res == 7);
    }

    SECTION("adding 10 with 9 without carry, result should not be 9, with carry, it is an error case so should raise an exception(we should have only 0 to 9 as inputs)")
    {
        a = 10;
        b = 9;
        c = 0;

        REQUIRE_THROWS_AS(sumc(a, b, c),std::invalid_argument);
    }
}

TEST_CASE("Checking add function ", "[add]")
{
    numberType a, b;
    SECTION("adding two zeros, result should be 0")
    {
        a = {0};
        b = {0};
        numberType res = add(a,b);
        REQUIRE( res == numberType{0});
    }

    SECTION("adding 1 to 9, result should be 10")
    {
        a = {1};
        b = {9};
        numberType res = add(a,b);
        REQUIRE( res == numberType{1, 0});
    }

    SECTION("adding 19 to 8, result should be 27")
    {
        a = {1,9};
        b = {8};
        numberType res = add(a,b);
        REQUIRE( res == numberType{2,7});
    }

    SECTION("adding 1000 to 1, result should be 1001")
    {
        a = {1,0,0,0};
        b = {1};
        numberType res = add(a,b);
        REQUIRE( res == numberType{1,0,0,1});
    }
    SECTION("adding 1000 to 6, result should be 1006")
    {
        a = {1,0,0,0};
        b = {6};
        numberType res = add(a,b);
        REQUIRE( res == numberType{1,0,0,6});
    }

    SECTION("adding invalid numbers should throw exception(10, 9 -> invalid_argument)")
    {
        a = {10};
        b = {9};
        REQUIRE_THROWS_AS(add(a, b),std::invalid_argument);
    }
}


TEST_CASE("testing Fibonacci recursive mode", "[fib_rec]")
{
    Fibonacci fib;

    SECTION("any value below 1, should be 0")
    {
        auto ret = fib.fib_recursive(-1);
        REQUIRE(ret == numberType{0});
    }

    SECTION("any value below 1, should be 0")
    {
        auto ret = fib.fib_recursive(0);
        REQUIRE(ret == numberType{0});
    }

    SECTION("get fib(3), should be 2")
    {
        auto ret = fib.fib_recursive(3);
        REQUIRE(ret == numberType{2});
    }

    SECTION("get fib(10), should be 55")
    {
        auto ret = fib.fib_recursive(10);
        REQUIRE(ret == numberType{5,5});
    }

    SECTION("get fib(33), should be 3524578")
    {
        auto ret = fib.fib_recursive(33);
        REQUIRE(ret == numberType{3,5,2,4,5,7,8});
    }
}


TEST_CASE("testing Fibonacci dynamic mode", "[fib_dynamic]")
{
    Fibonacci fib;

    SECTION("any value below 1, should be 0")
    {
        auto ret = fib.fib_dynamic(-1);
        REQUIRE(ret == numberType{0});
    }

    SECTION("any value below 1, should be 0")
    {
        auto ret = fib.fib_dynamic(0);
        REQUIRE(ret == numberType{0});
    }

    SECTION("get fib(3), should be 2")
    {
        auto ret = fib.fib_dynamic(3);
        REQUIRE(ret == numberType{2});
    }

    SECTION("get fib(10), should be 55")
    {
        auto ret = fib.fib_dynamic(10);
        REQUIRE(ret == numberType{5,5});
    }
    
    SECTION("get fib(33), should be 3524578")
    {
        auto ret = fib.fib_dynamic(33);
        REQUIRE(ret == numberType{3,5,2,4,5,7,8});
    }
    SECTION("get fib(200), should be 280571172992510140037611932413038677189525")
    {
        auto ret = fib.fib_dynamic(200);
        REQUIRE(ret == numberType{2,8,0,5,7,1,1,7,2,9,9,2,5,1,0,1,4,0,0,3,7,6,1,1,9,3,2,4,1,3,0,3,8,6,7,7,1,8,9,5,2,5});
    }
}

TEST_CASE("TEST to string function", "[toStr]")
{
    Fibonacci fib;
    SECTION("get fib(200), string should be 280571172992510140037611932413038677189525")
    {
        auto ret = fib.fib_dynamic(200);
        REQUIRE(fib.solution_toStr(ret) == "280571172992510140037611932413038677189525");
    }

    SECTION("get fib(1), string should be 1")
    {
        auto ret = fib.fib_dynamic(1);
        REQUIRE(fib.solution_toStr(ret) == "1");
    }

}