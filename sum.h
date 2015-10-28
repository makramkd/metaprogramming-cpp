//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_SUM_H
#define MY_MPL_SUM_H

namespace mpl {

    // compile time sum
    // using variadics
    template<int... Sequence>
    struct sum;

    template<int N0, int... N1To>
    struct sum<N0, N1To> {
        static constexpr auto value = sum<N1To>::value + N0;
    };

    // base cases
    template<int N0>
    struct sum<N0> {
        static constexpr auto value = N0;
    };

    template<>
    struct sum {
        static constexpr auto value = 0;
    };
}
#endif //MY_MPL_SUM_H
