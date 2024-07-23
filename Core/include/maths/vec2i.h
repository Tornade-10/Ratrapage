#ifndef CORE_MATHS_VEC2I_H_
#define CORE_MATHS_VEC2I_H_


#include "vec2f.h"

namespace core
{
	struct Vec2i
    {
        int x = 0, y = 0;

        //Test for additions
        constexpr Vec2i operator+(Vec2i other) const
        {
            return {x + other.x, y + other.y};
        }

        //Test for subtractions
        constexpr Vec2i operator-(Vec2i other) const
        {
            return {x - other.x, y - other.y};
        }

        //Test for reverse operator
        constexpr Vec2i operator-() const
        {
            return {-x, -y};
        }

        //Test for Dot product
        static constexpr int Dot(Vec2i v1, Vec2i v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        //Test for perpendicular
        constexpr Vec2i Perpendicular() const
        {
            return { -y, x };
        }

        //Test for reversed perpendicular
        constexpr Vec2i Perpendicular2() const
        {
            return { y, -x };
        }

    }; // struct Vec2i
}

// Implement Queue with Array
// Implement Stack with Vector

// Make a "death test" if the Fix Queue or the Fix Stack is too big

#endif //CORE_MATHS_VEC2I_H_