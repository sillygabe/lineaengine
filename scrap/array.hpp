template <typename T, unsigned long long size>
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

    T &operator[](unsigned long long s)
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


    unsigned long long get_size()
    {
        return size;
    }
};