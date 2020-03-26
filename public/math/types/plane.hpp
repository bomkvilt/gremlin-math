#ifndef MATH__PLANE_HPP
#define MATH__PLANE_HPP

#include "math/types/vector.hpp"


template<typename T>
struct TPlane : public reflect::FArchived
{
	ARCH_BEGIN(reflect::FArchived)
		ARCH_FIELD(, , normal)
		ARCH_END();
	using SVector = TVector<T>;

public:

	SVector normal;

public:

	TPlane() = default;

	TPlane(const SVector& normal)
		: normal(normal)
	{}

	// create a plane on base of 3 points
	TPlane(const SVector& A, const SVector& B, const SVector& C)
	{
		auto a = B - A;
		auto b = C - A;
		normal = (a ^ b).GetNormal();
	}

	// create a plane on base of 2 vectors
	TPlane(const SVector& a, const SVector& b)
	{
		normal = (a ^ b).GetNormal();
	}

public:

	SVector Project(const SVector& vector)
	{
		auto product = (vector * normal).Size();
		auto norm2   = normal.Size2();
		return vector - normal * (product / norm2);
	}
};


#endif //!MATH__PLANE_HPP
