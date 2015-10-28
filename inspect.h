//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_INSPECT_H
#define MY_MPL_INSPECT_H

#include <stddef.h>
#include "intops.h"

namespace mpl {

    // a metafunction that gets the compile time
    // rank of an array

    // base case: T is not an array type (i.e its a scalar type)
    template<typename T>
    struct rank {
        enum { value = 0u };
    };

    // recursion: U could be an array type as well
    template<class U, size_t N>
    struct rank<U[N]> {
        enum { value = 1u + rank<U>::value };
    };

    // unbounded array type
    template<typename U>
    struct rank<U[]> {
        enum { value = 1u + rank<U>::value };
    };

    // identity metafunction
    template<typename T>
    struct type_id {
        using type = T;
    };

    // alias template
    // for better usability
    template<typename T>
    using type_of = typename type_id<T>::type;

    // equality of types: really useful!

    // false by default
    template<typename T, typename U> struct equal_types : false_type { };

    // true only if they match
    template<typename T> struct equal_types<T, T> : true_type { };

    // generalizing equal_types:
    // is the given type _one_ of the list of types?

    // decl first
    template<typename T, typename... types>
    struct is_any_of;

    // base case 1:
    // given list is empty
    template<typename T>
    struct is_any_of<T> : false_type { };

    // base case 2:
    // the head of the list is the type we want
    template<typename T, typename... types>
    struct is_any_of<T, T, types...> : true_type { };

    // recursion:
    // head is not the type we want: inspect the tail of the list
    template<typename T, typename T0, typename... types>
    struct is_any_of<T, T0, types...> : is_any_of<T, types...> { };

    // is_void:
    // check if the return type of a function is void!
    template<typename T> struct is_void : false_type { };

    // specialization: on void
    // and cv variations of it (this is weird)
    template<> struct is_void<void> : true_type { };

    // const void
    template<> struct is_void<const void> : true_type { };

    // cv void!!
    template<> struct is_void<const volatile void> : true_type { };

    // volatile void
    template<> struct is_void<volatile void> : true_type { };

    // is_integral: check if a given type is
    // an integral type

    // false by default
    template<typename T> struct is_integral : false_type { };

    // many specializations:
    // char
    // short
    // int
    // long
    // unsigned
    // unsigned long
    // long long
    // unsigned long long
    // doesn't handle cv qualifiers at the moment

    template<> struct is_integral<char> : true_type { };

    template<> struct is_integral<char16_t> : true_type { };

    template<> struct is_integral<char32_t> : true_type { };

    template<> struct is_integral<wchar_t> : true_type { };

    template<> struct is_integral<short> : true_type { };

    template<> struct is_integral<int> : true_type { };

    template<> struct is_integral<long> : true_type { };

    template<> struct is_integral<long long> : true_type { };

    template<> struct is_integral<unsigned char> : true_type { };

    template<> struct is_integral<unsigned short> : true_type { };

    template<> struct is_integral<unsigned> : true_type { };

    template<> struct is_integral<unsigned long> : true_type { };

    template<> struct is_integral<unsigned long long> : true_type { };

}
#endif //MY_MPL_INSPECT_H
