#include <cmath>
#include "define.hpp"
#pragma once

namespace math
{
    struct point2d
    {
        flt64_t x = 0;
        flt64_t y = 0;
        point2d() = default;
        point2d(flt64_t o1, flt64_t o2)
        {
            this->x = o1;
            this->y = o2;
        }
    };

    class vector2d
    {
    private:
        point2d self;
    public:
        vector2d() = default;
        vector2d(point2d other) : self(other) {}
        vector2d(flt64_t o1, flt64_t o2) : self(o1, o2) {}

        point2d get_point() {return self;}

        vector2d operator+(vector2d other)
        {
            return vector2d
            (
                self.x + other.self.x,
                self.y + other.self.y
            );
        }

        void operator+=(vector2d other)
        {
            self = this->operator+(other).get_point();
        }

        void invert()
        {
            self.x *= -1;
            self.y *= -1;
        }

        //TODO
        /*
        static vector2d from_polar(flt64_t degrees, flt64_t length)
        {
            flt64_t radians = degrees / 180 * M_PI;

        }
        */
       
    };
}