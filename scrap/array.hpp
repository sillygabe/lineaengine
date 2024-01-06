#include "../base/define.hpp"
#pragma once

namespace data
{
    template <typename T, size_t size>
    class array
    {
    private:
        T arr[size];
    public:
        array() = default;
        ~array() = default;
        array(T a[size])
        {
            for (int i = 0; i < size; i++)
            {
                this->arr[i] = a[i];
            }
        }

        T &operator[](size_t s)
        {
            return (this->arr[s]);
        }

        T *begin()
        {
            return &(this->arr[0]);
        }

        T *end()
        {
            return &(this->arr[size]);
        }

        T* get_c_array()
        {
            return this->arr;
        }

        size_t get_size()
        {
            return size;
        }
    };
}