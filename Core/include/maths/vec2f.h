#ifndef CORE_MATHS_VEC2F_H_
#define CORE_MATHS_VEC2F_H_
#include <valarray>

#include "vec2i.h"

namespace core
{
	struct Vec2f
    {
        float x = 0, y = 0;

        //Test for additions
        constexpr Vec2f operator+(Vec2f other) const
        {
            return {x + other.x, y + other.y};
        }

        //Test for subtractions
        constexpr Vec2f operator-(Vec2f other) const
        {
            return {x - other.x, y - other.y};
        }

        //Test for reverse operator
        constexpr Vec2f operator-() const
        {
            return {-x, -y};
        }

        //Test for Dot product
        static constexpr float Dot(Vec2f v1, Vec2f v2)
        {
            return v1.x * v2.x + v1.y * v2.y;
        }

        [[nodiscard]] float Magnitude() const
        {
            return std::sqrt(x * x + y * y);
        }

        [[nodiscard]] float SqrtMagnitude() const
        {
            return x * x + y * y;
        }

        [[nodiscard]] Vec2f Norm() const
        {
            const float magnitude = Magnitude();

            if (magnitude == 0)
            {
                return { 0, 0 };
            }
            return {x / magnitude, y / magnitude};
        }

        static float Lerp(Vec2f v1, Vec2f v2)
        {
            float t = 0.5;

            return v1.x + t * (v2.x - v1.x);
        }

        //Test for perpendicular
        constexpr Vec2f Perpendicular() const
        {
            return { -y, x };
        }

        //Test for reversed perpendicular
        constexpr Vec2f Perpendicular2() const
        {
            return { y, -x };
        }

    }; // struct Vec2f
}

#endif //CORE_MATHS_VEC2F_H_