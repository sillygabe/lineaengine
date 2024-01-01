#include "../base/define.hpp"

namespace scrap 
{
    template <typename T, size_t size>
    class array_t
    {
    private:
        T arr[size];
    public:
        array_t() = default;
        ~array_t() = default;
        array_t(T a[size])
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