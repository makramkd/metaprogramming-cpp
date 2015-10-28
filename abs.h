//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_ABS_H
#define MY_MPL_ABS_H

#include <limits.h>

namespace mpl {

    // usage:
    // abs<N>::value ('calls' the metafunction)
    template<int N>
    struct abs {
        static_assert(N != INT_MIN, "N is too small");
        static constexpr auto value = N < 0 ? -N : N;
    };
}

#endif //MY_MPL_ABS_H
