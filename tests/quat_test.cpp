#include "gtest/gtest.h"
#include "math/types/quat.hpp"



struct quat_tests : public testing::Test
{
	using FQuat = TQuat<float>;

	void Compare(FQuat& l, FQuat r)
	{
		EXPECT_NEAR(l.x, r.x, Math::EPSILON);
		EXPECT_NEAR(l.y, r.y, Math::EPSILON);
		EXPECT_NEAR(l.z, r.z, Math::EPSILON);
		EXPECT_NEAR(l.w, r.w, Math::EPSILON);
	}
};

TEST_F(quat_tests, identity)
{
	auto probe = FQuat::Identity;

	ASSERT_EQ(0, probe.x);
	ASSERT_EQ(0, probe.y);
	ASSERT_EQ(0, probe.z);
	ASSERT_EQ(1, probe.w);
}

TEST_F(quat_tests, construction)
{
	{	// raw components
		auto probe = FQuat(0, 0, 0, 1);
		ASSERT_EQ(0, probe.x);
		ASSERT_EQ(0, probe.y);
		ASSERT_EQ(0, probe.z);
		ASSERT_EQ(1, probe.w);
	}
	{	// default
		auto probe = FQuat();
		auto whant = FQuat::Identity;
		Compare(whant, probe);
	}
	{	// rotation around axis
		auto c = Math::Cos(DEG2RAD(30));
		auto s = Math::Sin(DEG2RAD(30));
		auto probe = FQuat({ 0, 0, 1 }, 60);
		auto whant = FQuat(0, 0, s, c);
		Compare(whant, probe);
	}
	{	// euler angles
		auto c = Math::Cos(DEG2RAD(30));
		auto s = Math::Sin(DEG2RAD(30));
		auto probe = FQuat(0, 0, 60);
		auto whant = FQuat(0, 0, s, c);
		Compare(whant, probe);
	}
	{	// from another quat
		auto base  = TQuat<double>(0, 1, 0, 0);
		auto probe = FQuat(base);
		auto whant = FQuat(0, 1, 0, 0);
		Compare(whant, probe);
	}
	{	// assignement
		auto base  = TQuat<double>(0, 1, 0, 0);
		auto probe = FQuat();
		auto whant = FQuat(0, 1, 0, 0);
		
		probe = base;

		Compare(whant, probe);
	}
}

TEST_F(quat_tests, index_picking)
{
	{	// non-constant
		auto probe = FQuat();
		ASSERT_EQ(0, probe[0]);
		ASSERT_EQ(0, probe[1]);
		ASSERT_EQ(0, probe[2]);
		ASSERT_EQ(1, probe[3]);
		EXPECT_ANY_THROW(probe[ 4]);
		EXPECT_ANY_THROW(probe[-1]);
	}
	{	// constant
		const auto probe = FQuat();
		ASSERT_EQ(0, probe[0]);
		ASSERT_EQ(0, probe[1]);
		ASSERT_EQ(0, probe[2]);
		ASSERT_EQ(1, probe[3]);
		EXPECT_ANY_THROW(probe[4]);
		EXPECT_ANY_THROW(probe[-1]);
	}
	{	// pre-defined values
		auto probe = FQuat(1, 2, 3, 4);
		ASSERT_EQ(1, probe[0]);
		ASSERT_EQ(2, probe[1]);
		ASSERT_EQ(3, probe[2]);
		ASSERT_EQ(4, probe[3]);
	}
}

TEST_F(quat_tests, complex_rotations)
{
	{	// roll -> pitch
		auto A1 = FQuat(90, 0, 0);
		auto A2 = FQuat(0, 90, 0);
		auto AR = A2 * A1;
		auto AE = FQuat({1, 1, -1}, 90);
		Compare(AE, AR);
	}
}
