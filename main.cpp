#include <iostream>

#include "if.h"

int main() {

    constexpr auto val = 3;
    mpl::if_t<(val < 2), decltype(val), unsigned> val2 = 3;

    
}