//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_INSPECT_H
#define MY_MPL_INSPECT_H

#include <stddef.h>

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
}
#endif //MY_MPL_INSPECT_H
