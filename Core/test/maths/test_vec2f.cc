#include <maths/vec2f.h>

#include <gtest/gtest.h>

#include "maths/vec2i.h"

struct Vec2fOperationFixture : public ::testing::TestWithParam<std::pair<core::Vec2f, core::Vec2f>>
{
	float x, y;
};

TEST_P(Vec2fOperationFixture, Add)
{
	auto [v1, v2] = GetParam();
	const auto result = v1 + v2;
	EXPECT_FLOAT_EQ(result.x, v1.x + v2.x);
	EXPECT_FLOAT_EQ(result.y, v1.y + v2.y);
}

TEST_P(Vec2fOperationFixture, Sub)
{
	auto [v1, v2] = GetParam();
	const auto result = v1 - v2;
	EXPECT_FLOAT_EQ(result.x, v1.x - v2.x);
	EXPECT_FLOAT_EQ(result.y, v1.y - v2.y);

	const auto neg1 = -v1;
	const auto neg2 = -v2;
	EXPECT_FLOAT_EQ(neg1.x,-v1.x);
	EXPECT_FLOAT_EQ(neg1.y, -v1.y);
	EXPECT_FLOAT_EQ(neg2.x, -v2.x);
	EXPECT_FLOAT_EQ(neg2.y, -v2.y);
}

TEST_P(Vec2fOperationFixture, Dot)
{
	auto [v1, v2] = GetParam();
	const auto result = core::Vec2f::Dot(v1, v2);
	EXPECT_FLOAT_EQ(result, v1.x * v2.x + v1.y * v2.y);
}

TEST_P(Vec2fOperationFixture, Normalise)
{
	auto [v1, v2] = GetParam();
	const auto norm1 = v1.Norm();
	const auto norm2 = v2.Norm();
	//const auto magn1 = v1.Magnitude();
	//const auto magn2 = v2.Magnitude();

	EXPECT_NEAR(norm1.x, 0.0f, 1.0f);
	EXPECT_NEAR(norm1.y, 0.0f, 1.0f);
	EXPECT_NEAR(norm2.x, 0.0f, 1.0f);
	EXPECT_NEAR(norm2.y, 0.0f, 1.0f);

}

TEST_P(Vec2fOperationFixture, Magnitude)
{
	auto [v1, v2] = GetParam();
	const auto magn1 = v1.Magnitude();
	const auto magn2 = v2.Magnitude();

	EXPECT_FLOAT_EQ(magn1, std::sqrt(v1.x * v1.x + v1.y * v1.y));
	EXPECT_FLOAT_EQ(magn2, std::sqrt(v2.x * v2.x + v2.y * v2.y));
}

TEST_P(Vec2fOperationFixture, SqrtMagnitude)
{
	auto [v1, v2] = GetParam();
	const auto magn1 = v1.SqrtMagnitude();
	const auto magn2 = v2.SqrtMagnitude();

	EXPECT_FLOAT_EQ(magn1, v1.x * v1.x + v1.y * v1.y);
	EXPECT_FLOAT_EQ(magn2, v2.x * v2.x + v2.y * v2.y);
}

TEST_P(Vec2fOperationFixture, Lerp)
{
	auto [v1, v2] = GetParam();
	const auto result = core::Vec2f::Lerp(v1, v2);

	EXPECT_FLOAT_EQ(result, v1.x + 0.5 * (v2.x - v1.x));
}

TEST_P(Vec2fOperationFixture, Perpendicular)
{
	auto [v1, v2] = GetParam();
	const auto p1 = v1.Perpendicular();
	const auto p2 = v2.Perpendicular();
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v1, p1), 0);
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v2, p2), 0);

	const auto r1 = v1.Perpendicular2();
	const auto r2 = v2.Perpendicular2();
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v1, r1), 0);
	EXPECT_FLOAT_EQ(core::Vec2f::Dot(v2, r2), 0);
}

TEST_P(Vec2fOperationFixture, ToVec2i)
{
	auto [v1, v2] = GetParam();
	const auto vecI1 = v1.ConvertToVec2i();
	const auto vecI2 = v2.ConvertToVec2i();
}

INSTANTIATE_TEST_SUITE_P(PositiveNumbers,
    Vec2fOperationFixture,
    testing::Values(
        std::pair{ core::Vec2f{1.3f, 3.5f}, core::Vec2f{2.7f, 4.9f} },
        std::pair{ core::Vec2f{10.1f, 15.5f}, core::Vec2f{25.7f, 35.8f} }
    )
);

//TEST(vec2, casting)
//{
//	core::Vec2i vi{}
//	core::Vec2f vf = vi;
//}