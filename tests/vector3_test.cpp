#include "gtest/gtest.h"
#include "math/math.hpp"



struct vec3_tests : public testing::Test
{

};

TEST_F(vec3_tests, angle2)
{
	{
		auto a = FVector(3, 0, 0);
		auto b = FVector(0, 5, 0);
		auto f = Math::Angle2(a, b);
		ASSERT_FLOAT_EQ(RAD2DEG(f), 90);
	}
	{
		auto a = FVector(3, 0, 0);
		auto b = FVector(0, -1, 0);
		auto f = Math::Angle2(a, b);
		ASSERT_FLOAT_EQ(RAD2DEG(f),270);
	}
}
