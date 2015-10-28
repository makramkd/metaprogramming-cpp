#include <iostream>

#include "inspect.h"

int main() {

    constexpr auto value = 3;
    constexpr auto val = 3.14;

    static_assert(mpl::equal_types<decltype(value), decltype(val)>::value, "Types are not equal!");
    static_assert(mpl::equal_types<int, int>::value, "Types are not equal!!");


}