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

    // compile time integral constant
    // useful for various other templates
    template<typename integral, integral v>
    struct integral_constant {
        enum { value = v };
    };

    // alias template for bool constant
    template<bool b>
    using bool_constant = integral_constant<bool, b>;

    // convenience types: true type and false type
    using true_type = bool_constant<true>;
    using false_type = bool_constant<false>;
}
#endif //MY_MPL_INTOPS_H
