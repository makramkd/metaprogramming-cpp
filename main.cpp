#include <iostream>

#include "func.h"

int f(int, int, int)
{
    return 0;
}

void g()
{

}

void h(int, double, long, long double)
{

}

int main() {

    static_assert(mpl::arity_of<decltype(f)>::value == 3, "arity is 3!");
    static_assert(mpl::arity_of<decltype(g)>::value == 0, "arity is 0!");

    std::cout << mpl::arity_of<decltype(f)>::value << "\n";
    std::cout << mpl::arity_of<decltype(g)>::value << "\n";

    static_assert(mpl::returns<void, decltype(g)>::value, "return type is void!");
    static_assert(mpl::returns<int, decltype(f)>::value, "return type is int!");

    static_assert(mpl::args_have_type<int, decltype(f)>::value, "args have int!");
    static_assert(mpl::args_have_type<void, decltype(g)>::value, "args have void!");

    std::cout << mpl::args_have_type<double, decltype(f)>::value << std::endl;

    std::cout << mpl::has_arg_type<long double, decltype(h)>::value << std::endl;
    std::cout << mpl::has_arg_type<bool, decltype(g)>::value << std::endl; // false
    std::cout << mpl::has_arg_type<int, decltype(h)>::value << std::endl;

    //std::cout << mpl::has_exact_arg_types<std::tuple<int, int, int>, decltype(f)>::value << std::endl;
}