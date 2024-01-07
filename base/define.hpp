#include <ctype.h>
#pragma once

typedef float flt32_t;
typedef double flt64_t;

//struct to check if to types are the same :)
template <typename T, typename U>
struct is_same
{
    static constexpr bool value = false;
    constexpr operator bool() const 
    {
        return false;
    }
};

template <typename T>
struct is_same<T, T>
{
    static constexpr bool value = true;
    constexpr operator bool() const 
    {
        return true;
    }
};
