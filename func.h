//
// Created by Makram Kamaleddine on 11/13/15.
//

#ifndef MY_MPL_FUNC_H
#define MY_MPL_FUNC_H

#include "inspect.h"
#include <utility>

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

    // metafunction that gets the return type of the given
    // function (or decltype(f), more correctly)
    template<typename>
    struct return_type;

    template<typename Ret, typename... Args>
    struct return_type<Ret(Args...)>
    {
        using type = Ret;
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
    template<typename T, typename Ret>
    struct args_have_type<T, Ret()>
    {
        static constexpr auto value = false;
    };

    template<typename Ret>
    struct args_have_type<void, Ret()>
    {
        static constexpr auto value = true;
    };

    // a useful alias template if i can get it right
    template<typename T, typename Ret, typename... Args>
    using args_have_type_v = typename args_have_type<T, Ret(Args...)>::value;

    // check that one of the arguments to the function
    // is of the given type
    template<typename T, typename Ret, typename... Args>
    struct has_arg_type;

    template<typename T, typename Ret, typename Arg0, typename... Args>
    struct has_arg_type<T, Ret(Arg0, Args...)>
    {
        static constexpr auto value = equal_types<T, Arg0>::value ? true : has_arg_type<T, Ret(Args...)>::value;
    };

    template<typename T, typename Ret, typename Arg>
    struct has_arg_type<T, Ret(Arg)>
    {
        static constexpr auto value = equal_types<T, Arg>::value;
    };

    template<typename T, typename Ret>
    struct has_arg_type<T, Ret()>
    {
        static constexpr auto value = false;
    };

    template<typename Ret>
    struct has_arg_type<void, Ret()>
    {
        static constexpr auto value = true;
    };

    // useful alias template
    template<typename T, typename Ret, typename... Args>
    using has_arg_type_v = typename has_arg_type<T, Ret(Args...)>::value;

    // dummy template
    template<typename Ret, typename... Args>
    struct arithmetic_args;

    // a template to determine whether the arguments
    // of a function are all arithmetic types
    template<typename Ret, typename Arg0, typename... Args>
    struct arithmetic_args<Ret(Arg0, Args...)>
    {
        static constexpr auto value = std::is_arithmetic<Arg0>::value && arithmetic_args<Ret(Args...)>::value;
    };

    // end the recursion
    template<typename Ret, typename Arg>
    struct arithmetic_args<Ret(Arg)>
    {
        static constexpr auto value = std::is_arithmetic<Arg>::value;
    };

    // a function with no arguments has no arithmetic
    // arguments (or is it vacuously true? no idea)
    template<typename Ret>
    struct arithmetic_args<Ret()>
    {
        static constexpr auto value = false;
    };
}
#endif //MY_MPL_FUNC_H
