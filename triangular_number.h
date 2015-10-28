//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_TRIANGULAR_NUMBER_H
#define MY_MPL_TRIANGULAR_NUMBER_H

namespace mpl {

    template<int N>
    struct triangular_number {
        static constexpr auto value = triangular_number<N - 1>::value + N;
    };

    template<>
    struct triangular_number<1> {
        static constexpr auto value = 1;
    };

    template<>
    struct triangular_number<0> {
        static constexpr auto value = 0;
    };
}
#endif //MY_MPL_TRIANGULAR_NUMBER_H
