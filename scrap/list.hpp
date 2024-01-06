#include <stdlib.h>
#include "../base/define.hpp"
#pragma once

namespace data
{
    template <typename T>
    class list
    {
    private:
        size_t size;
        T* arr;
    public:
        list()
        {
            this->arr = (T*) malloc(0);
            this->size = 0;
        }

        void set(T elem)
        {
            for (size_t i = 0; i < size; i++)
            {
                this->arr[i] = elem;
            }
        }

        void append(T elem)
        {
            this->arr = (T*) realloc(this->arr, (++this->size) * sizeof(T));
            this->arr[this->size - 1] = elem;
        }   

        void pop()
        {
            this->arr = (T*) realloc(this->arr, (--this->size) * sizeof(T));
        }

        T *operator[](const size_t pos)
        {
            return &(this->arr[pos]);
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
            return this->size;
        }
    };
}