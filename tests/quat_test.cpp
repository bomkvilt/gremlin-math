#include "gtest/gtest.h"
#include "math/types/quat.hpp"



struct quat_tests : public testing::Test
{
	using SQuat   = TQuat<float>;
	using SVector = TVector<float>;

	void Compare(SQuat& l, SQuat r)
	{
		EXPECT_NEAR(l.x, r.x, Math::Epsilon);
		EXPECT_NEAR(l.y, r.y, Math::Epsilon);
		EXPECT_NEAR(l.z, r.z, Math::Epsilon);
		EXPECT_NEAR(l.w, r.w, Math::Epsilon);
	}
};

TEST_F(quat_tests, identity)
{
	auto probe = SQuat::Identity;

	ASSERT_EQ(0, probe.x);
	ASSERT_EQ(0, probe.y);
	ASSERT_EQ(0, probe.z);
	ASSERT_EQ(1, probe.w);
}

TEST_F(quat_tests, construction)
{
	{	// raw components
		auto probe = SQuat(0, 0, 0, 1);
		ASSERT_EQ(0, probe.x);
		ASSERT_EQ(0, probe.y);
		ASSERT_EQ(0, probe.z);
		ASSERT_EQ(1, probe.w);
	}
	{	// default
		auto probe = SQuat();
		auto whant = SQuat::Identity;
		Compare(whant, probe);
	}
	{	// rotation around axis
		auto c = Math::Cos(DEG2RAD(30.));
		auto s = Math::Sin(DEG2RAD(30.));
		auto probe = SQuat({ 0, 0, 1 }, 60);
		auto whant = SQuat(0, 0, s, c);
		Compare(whant, probe);
	}
	{	// euler angles
		auto c = Math::Cos(DEG2RAD(30.));
		auto s = Math::Sin(DEG2RAD(30.));
		auto probe = SQuat(0, 0, 60);
		auto whant = SQuat(0, 0, s, c);
		Compare(whant, probe);
	}
	{	// from another quat
		auto base  = TQuat<double>(0, 1, 0, 0);
		auto probe = SQuat(base);
		auto whant = SQuat(0, 1, 0, 0);
		Compare(whant, probe);
	}
	{	// assignement
		auto base  = TQuat<double>(0, 1, 0, 0);
		auto probe = SQuat();
		auto whant = SQuat(0, 1, 0, 0);
		
		probe = base;

		Compare(whant, probe);
	}
}

TEST_F(quat_tests, index_picking)
{
	{	// non-constant
		auto probe = SQuat();
		ASSERT_EQ(0, probe[0]);
		ASSERT_EQ(0, probe[1]);
		ASSERT_EQ(0, probe[2]);
		ASSERT_EQ(1, probe[3]);
		EXPECT_ANY_THROW(probe[ 4]);
		EXPECT_ANY_THROW(probe[-1]);
	}
	{	// constant
		const auto probe = SQuat();
		ASSERT_EQ(0, probe[0]);
		ASSERT_EQ(0, probe[1]);
		ASSERT_EQ(0, probe[2]);
		ASSERT_EQ(1, probe[3]);
		EXPECT_ANY_THROW(probe[4]);
		EXPECT_ANY_THROW(probe[-1]);
	}
	{	// pre-defined values
		auto probe = SQuat(1, 2, 3, 4);
		ASSERT_EQ(1, probe[0]);
		ASSERT_EQ(2, probe[1]);
		ASSERT_EQ(3, probe[2]);
		ASSERT_EQ(4, probe[3]);
	}
}

// TEST_F(quat_tests, complex_rotations)
// {
// 	{	// roll -> pitch
// 		auto A1 = SQuat(90, 0, 0);
// 		auto A2 = SQuat(0, 90, 0);
// 		auto AR = A2 * A1;
// 		auto AE = SQuat({1, 1, -1}, 90);
// 		Compare(AE, AR);
// 	}
// }

TEST_F(quat_tests, basisTranslation)
{
	auto x1 = SVector(0, 0, 66);
	auto x2 = SVector(66, 0, 0);
	auto z1 = SVector(17.49933184,-27.97808759, 57.15767665);
	auto z2 = SVector(50.55893325, 42.11214013,  5.13438634);

	auto qv = SVector(23.90946073, 4.88044964, 31.87555227).GetNormal();
	auto qf = 50.39964764;
	auto Q0 = SQuat(qv, qf);
	
	auto Q1 = Math::BasisTranslation(x1, x2, z1, z2);
	Compare(Q0, Q1);
}

TEST_F(quat_tests, basisTranslation_identity)
{
	auto x1 = SVector(0, 0, 1);
	auto x2 = SVector(1, 0, 0);
	auto z1 = SVector(0, 0, 1);
	auto z2 = SVector(1, 0, 0);

	auto Q0 = SQuat::Identity;

	auto Q1 = Math::BasisTranslation(x1, x2, z1, z2);
	Compare(Q0, Q1);
}
