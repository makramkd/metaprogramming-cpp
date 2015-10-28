//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_INTOPS_H
#define MY_MPL_INTOPS_H

namespace mpl {

    // integer operations
    // these can be written out manually in
    // constexpr but its more convenient to
    // have metafunctions
    // need to find a way to do this for all
    // integral types
    template<int N, int M>
    struct add {
        enum { value = N + M };
    };

    template<int N, int M>
    struct sub {
        enum { value = N - M };
    };

    template<int N, int M>
    struct mod {
        enum { value = N % M };
    };

    template<int N, int M>
    struct div {
        enum { value = N / M }; // integer division
    };

    template<int N, int M>
    struct mult {
        enum { value = N * M };
    };
}
#endif //MY_MPL_INTOPS_H
