//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_POWER_H
#define MY_MPL_POWER_H

namespace mpl {

    template<int T, int N>
    struct power {
        static constexpr auto value = power<T, N-1>::value * power<T, 1>::value;
    };

    // two base cases for the recursion:
    // N = 1 and N = 0
    template<int T>
    struct power<T, 1> {
        static constexpr auto value = T;
    };

    template<int T>
    struct power<T, 0> {
        static constexpr auto value = 1;
    };
}
#endif //MY_MPL_POWER_H
