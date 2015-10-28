//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_FACTORIAL_H
#define MY_MPL_FACTORIAL_H

namespace mpl {

    template<int N>
    struct factorial {
        static constexpr auto value = factorial<N - 1>::value * N;
    };

    template<>
    struct factorial<0> {
        static constexpr auto value = 1;
    };
}

#endif //MY_MPL_FACTORIAL_H
