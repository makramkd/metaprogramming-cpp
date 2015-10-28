//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_ENABLE_IF_H
#define MY_MPL_ENABLE_IF_H

#include "inspect.h"

namespace mpl {

    // enable_if: cause a compile time "no member" failure
    // if the predicate is not satisfied
    template<bool, typename T = void>
    struct enable_if : type_id<T> {

    };

    // notice that there is no member named type
    template<typename T>
    struct enable_if<false, T> { };
}
#endif //MY_MPL_ENABLE_IF_H
