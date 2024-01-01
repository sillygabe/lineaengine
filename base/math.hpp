#include "define.hpp"
#include <cmath>

int64_t gcd(int64_t first, int64_t second)
{
    return second == 0 ? first : gcd(second, first % second);
}

class fraction_t
{
private:
    int64_t numer, denom;
public:
    fraction_t()
    {
        this->numer = 1;
        this->denom = 1;
    }
    fraction_t(const int64_t n1, const int64_t n2)
    {
        if (n2 == 0) return;
        this->numer = n1;
        this->denom = n2;
        this->normalize();
    }

    void normalize()
    {
        //TODO
    }

    flt64_t get_as_float()
    {
        return (flt64_t) (this->numer / this->denom);
    }

    int64_t get_as_number()
    {
        return (int64_t) (this->numer / this->denom);
    }

    int64_t get_numerator()
    {
        return this->numer;
    }
    int64_t get_denominator()
    {
        return this->denom;
    }
};  