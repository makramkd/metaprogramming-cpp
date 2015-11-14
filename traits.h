//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_TRAITS_H
#define MY_MPL_TRAITS_H

#include <cstddef>
#include "inspect.h"

namespace mpl {

    // we will use is_any_of to make life
    // easier
    template<typename T>
    using is_floating = is_any_of<T, float, const float,
            volatile float, const volatile float, double, const double,
            volatile double, const volatile double,
            long double, const long double, volatile long double,
            const volatile long double>;

    template<typename T>
    using is_integral = is_any_of<T, bool, char, char16_t, char32_t,
            short, int, long, long long, unsigned char, unsigned short,
            unsigned int, unsigned long long,
            const char, volatile char, const volatile char,
            const char16_t, volatile char16_t, const volatile char16_t,
            const char32_t, volatile char32_t, const volatile char32_t,
            const short, volatile short, const volatile short>; // many more

    // re-implementing is_void
    template<typename T>
    using is_void = is_any_of<T, void, volatile void, const void,
            const volatile void>;


    // is_null_pointer
    template<typename T>
    using is_null_pointer = is_any_of<T, std::nullptr_t,
            const std::nullptr_t, volatile std::nullptr_t,
            const volatile std::nullptr_t>;

    // this is probably incomplete
    template<typename T>
    struct is_array : false_type {};

    template<typename T, int N>
    struct is_array<T[N]> : true_type { };

}

#endif //MY_MPL_TRAITS_H
