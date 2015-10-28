//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_IF_H
#define MY_MPL_IF_H

#include "inspect.h"

namespace mpl {

    template<bool, typename T, typename>
    struct If : type_id<T> {

    };

    template<typename T, typename F>
    struct If<false, T, F> : type_id<F> {

    };

    template<bool P, typename T, typename F>
    using if_t = typename If<P, T, F>::type ;
}
#endif //MY_MPL_IF_H
