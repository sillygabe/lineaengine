#pragma once

//All the needed data structures
namespace data
{
    //Just like in the `std` but it will actually compile with SDL
    //cheers :)
    template <class T, class U>
    struct pair
    {
        T first;
        U second;

        pair(T a, U b) 
        {
            this->first = a;
            this->second = b;
        }
    };
};