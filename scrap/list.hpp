#include <cstdlib>
#include "../base/define.hpp"

namespace scrap 
{
    template <typename T>
    class list_t
    {
    private:
        size_t size;
        size_t max_size;
        T* arr;
    public:
        list_t()
        {
            this->arr = (T*) malloc(0);
            this->size = 0;
        }

        void append(T elem)
        {
            this->arr = (T*) realloc(this->arr, ++this->size);
            this->arr[this->size - 1] = elem;
        }   

        void pop()
        {
            this->arr = (T*) realloc(this->arr, --this->size);
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