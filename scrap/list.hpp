#include <cstdlib>

template <typename T>
class list
{
private:
    size_t size;
    size_t max_size;
    T* arr;
public:
    list()
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

    size_t get_size()
    {
        return this->size;
    }
};