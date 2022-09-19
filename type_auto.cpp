#include "headers.hpp"
/*
We want to create a function that will add numbers together when called in
succession.

add(1)(2); // == 3

We also want to be able to continue to add numbers to our chain.

add(1)(2)(3); // == 6
add(1)(2)(3)(4); //  == 10
add(1)(2)(3)(4)(5); // == 15

We should be able to store the returned values and reuse them.

var addTwo = add(2);
addTwo; // == 2
addTwo + 5; // == 7
addTwo(3); // == 5
addTwo(3)(5); // == 10

https://stackoverflow.com/questions/1591217/what-is-the-meaning-of-leading-underscores-in-a-c-constructor


type auto can't be print out 
*/
using namespace std;
class Yoba
{
public:
    Yoba(int n)
        : _n(n)
    {}
    Yoba operator()(int n)
    {
        return Yoba(_n + n);
    }
    bool operator==(int n)
    {
        return _n == n;
    }
    int operator+(int n)
    {
        return _n + n;
    }
    int operator-(int n)
    {
        return _n - n;
    }
    friend bool operator==(int n, const Yoba &y)
    {
        return n == y._n;
    }

public:
    int _n;
};

auto add(int n)
{
    return Yoba(n);
}
int main()
{
    auto a = add(1)(2)(3);
     cout << a._n << endl;
    // std::cout << "add(1)(2) == 3\n";
    // std::cout << "add(1)(2)(3) == 6\n";
    return 0;
}