#include <iostream>

#include "power.h"
#include "factorial.h"
#include "abs.h"
#include "intops.h"

int main() {

    const int N = 18;
    const int M = 42;
    auto val1 = mpl::add<N, M>::value;
    auto val2 = mpl::sub<N, M>::value;
    auto val3 = mpl::div<N, M>::value;
    auto val4 = mpl::mod<N, M>::value;
    auto val5 = mpl::mult<N, M>::value;

    std::cout << val1 << " " << val2 << " " << val3 << " ";
    std::cout << val4 << " " << val5 << std::endl;
}