//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_EUCLID_H
#define MY_MPL_EUCLID_H

namespace mpl {

    // gcd via euclid's algorithm
    template<unsigned int M, unsigned int N>
    struct gcd {
        static constexpr auto value = gcd<N, M % N>::value;
    };

    template<unsigned int M>
    struct gcd<M, 0> {
        static_assert(M != 0, "gcd of 2 zeroes is undefined");
        static constexpr auto value = M;
    };
}
#endif //MY_MPL_EUCLID_H
