//
// Created by Makram Kamaleddine on 10/28/15.
//

#ifndef MY_MPL_REMOVE_CONST_H
#define MY_MPL_REMOVE_CONST_H

namespace mpl {

    // a metafunction that takes a type
    // that is const or volatile qualified
    // and removes this qualifier

    // no cv qualifiers: return the type given
    template<typename T>
    struct remove_cv {
        using type = T;
    };

    // const qualifier
    template<typename U>
    struct remove_cv<U const> {
        using type = U;
    };

    // volatile qualifier
    template<typename V>
    struct remove_cv<V volatile> {
        using type = V;
    };

    // const volatile
    template<typename W>
    struct remove_cv<W const volatile> {
        using type = W;
    };

    // alias template for better readability
    template<typename T>
    using remove_cv_t = typename remove_cv<T>::type;
}

#endif //MY_MPL_REMOVE_CONST_H
