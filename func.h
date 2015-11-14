//
// Created by Makram Kamaleddine on 11/13/15.
//

#ifndef MY_MPL_FUNC_H
#define MY_MPL_FUNC_H

#include "inspect.h"

namespace mpl {

    // figure out the arity of a function f
    // using recursion only
    template<typename Ret, typename... Args>
    struct arity_of;

    template<typename Ret, typename Arg0, typename... Args>
    struct arity_of<Ret(Arg0, Args...)>
    {
        static constexpr auto value = 1 + arity_of<Ret(Args...)>::value;
    };

    template<typename Ret, typename Arg>
    struct arity_of<Ret(Arg)>
    {
        static constexpr auto value = 1;
    };

    template<typename Ret>
    struct arity_of<Ret()>
    {
        static constexpr auto value = 0;
    };

    // dummy pattern
    template<typename, typename, typename...>
    struct returns;

    // check the return type of a function against
    // a given type.
    template<typename T, typename Ret, typename... Args>
    struct returns<T, Ret(Args...)>
    {
        static constexpr auto value = equal_types<T, Ret>::value;
    };

    // check the argument types of a function against
    // a given type
    template<typename T, typename Ret, typename... Args>
    struct args_have_type;

    template<typename T, typename Ret, typename Arg0, typename... Args>
    struct args_have_type<T, Ret(Arg0, Args...)>
    {
        static constexpr auto value = equal_types<T, Arg0>::value && args_have_type<T, Ret(Args...)>::value;
    };

    template<typename T, typename Ret, typename Arg>
    struct args_have_type<T, Ret(Arg)>
    {
        static constexpr auto value = equal_types<T, Arg>::value;
    };

    // cases where we have no arguments and void as type to check
    template<typename Ret>
    struct args_have_type<void, Ret()>
    {
        static constexpr auto value = true;
    };
}
#endif //MY_MPL_FUNC_H
