#include "gtest/gtest.h"
#include "math/math.hpp"



struct vec3_tests : public testing::Test
{

};

TEST_F(vec3_tests, angle2)
{
	for (auto& [a, b, d, msg] : std::vector<std::tuple<FVector, FVector, FReal, std::string>>{
		  {{3, 0, 0}, {0, 5, 0}, 90 , "I and II"}
		, {{3, 0, 0}, {0,-1, 0}, 270, "III and IV"}
		, {{3, 0, 0}, {3, 0, 0}, 0  , "same vectors (check of cos[1+0])"}
	})
	{
		auto f = Math::Angle2(a, b);
		EXPECT_FLOAT_EQ(RAD2DEG(f), d) << msg;
	}
	// \todo: test vectors with 2 non-zero coordinates
}
