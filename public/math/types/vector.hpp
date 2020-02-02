#ifndef MATH__VECTOR_HPP
#define MATH__VECTOR_HPP

#include <string>
#include "math/macro.hpp"
#include "math/functions.hpp"
#include "reflect/reflect.hpp"


template<typename T>
struct TVector : public reflect::FArchived
{
	ARCH_BEGIN(reflect::FArchived)
		ARCH_FIELD(, , x)
		ARCH_FIELD(, , y)
		ARCH_FIELD(, , z)
		ARCH_END();
	using SVector = TVector<T>;

public: //--------------| data
	T x;
	T y;
	T z;

public: //--------------| generation
	TVector(T v = 0) : x(v), y(v), z(v)
	{}

	TVector(T x, T y, T z) : x(x), y(y), z(z)
	{}

	template<typename Q>
	TVector(const TVector<Q>& r) : x(r.x), y(r.y), z(r.z)
	{}

	template<typename Q>
	SVector& operator=(const TVector<Q>& r) 
	{ 
		MATH_VECTOR_VECTOR((*this), r, =, MATH_STATE); 
	}

	      T& operator[](Int i)       { switch (i) { case 0: return x; case 1: return y; case 2: return z; } throw std::out_of_range("Invalid index"); }
	const T& operator[](Int i) const { switch (i) { case 0: return x; case 1: return y; case 2: return z; } throw std::out_of_range("Invalid index"); }
	
	SVector Sign() const 
	{ 
		return { MATH_VECTOR_SCALAR((*this), >= 0 ? 1 : -1, , MATH_LIST) }; 
	}

public: //--------------| vector - vector
	template<typename Q> SVector operator+(const TVector<Q>& r) const { return { MATH_VECTOR_VECTOR((*this), r, +, MATH_LIST) }; }
	template<typename Q> SVector operator-(const TVector<Q>& r) const { return { MATH_VECTOR_VECTOR((*this), r, -, MATH_LIST) }; }
	template<typename Q> SVector operator*(const TVector<Q>& r) const { return { MATH_VECTOR_VECTOR((*this), r, *, MATH_LIST) }; }
	template<typename Q> SVector operator/(const TVector<Q>& r) const { return { MATH_VECTOR_VECTOR((*this), r, /, MATH_LIST) }; }
	template<typename Q> SVector operator^(const TVector<Q>& r) const
	{
		return {
			y * r.z - r.y * z,
			z * r.x - r.z * x,
			x * r.y - r.x * y };
	}

	template<typename Q> SVector& operator+=(const TVector<Q>& r) { MATH_VECTOR_VECTOR((*this), r, +=, MATH_STATE); return *this; }
	template<typename Q> SVector& operator-=(const TVector<Q>& r) { MATH_VECTOR_VECTOR((*this), r, -=, MATH_STATE); return *this; }
	template<typename Q> SVector& operator*=(const TVector<Q>& r) { MATH_VECTOR_VECTOR((*this), r, *=, MATH_STATE); return *this; }
	template<typename Q> SVector& operator/=(const TVector<Q>& r) { MATH_VECTOR_VECTOR((*this), r, /=, MATH_STATE); return *this; }
	template<typename Q> SVector& operator^=(const TVector<Q>& r)
	{
		*this = *this ^ r; 
		return *this;
	}

public: //--------------| vector - scalar
	SVector operator+(const T& r) const { return { MATH_VECTOR_SCALAR((*this), r, +, MATH_LIST) }; }
	SVector operator-(const T& r) const { return { MATH_VECTOR_SCALAR((*this), r, -, MATH_LIST) }; }
	SVector operator*(const T& r) const { return { MATH_VECTOR_SCALAR((*this), r, *, MATH_LIST) }; }
	SVector operator/(const T& r) const { return { MATH_VECTOR_SCALAR((*this), r, /, MATH_LIST) }; }

	SVector& operator+=(const T& r) { MATH_VECTOR_SCALAR((*this), r, +=, MATH_STATE); return *this; }
	SVector& operator-=(const T& r) { MATH_VECTOR_SCALAR((*this), r, -=, MATH_STATE); return *this; }
	SVector& operator*=(const T& r) { MATH_VECTOR_SCALAR((*this), r, *=, MATH_STATE); return *this; }
	SVector& operator/=(const T& r) { MATH_VECTOR_SCALAR((*this), r, /=, MATH_STATE); return *this; }

public: //--------------| unary
	SVector operator-() const
	{
		return { MATH_VECTOR_SCALAR((*this), -1, *, MATH_LIST) };
	}

public: //--------------| comparement
	template<typename Q>
	bool operator==(const TVector<Q>& r) const
	{
		return MATH_VECTOR_VECTOR((*this), r, == , &&);
	}

	template<typename Q>
	bool operator!=(const TVector<Q>& r) const
	{
		return !((*this) == r);
	}

public: //--------------| size
	T Sum()   const { return MATH_VECTOR_SCALAR((*this), , , +); }
	T Size2() const { return MATH_VECTOR_VECTOR((*this), (*this), *, +); }
	T Size()  const { return Math::Sqrt(Size2()); }

	SVector GetNormal() const
	{
		auto size = Size();
		return { MATH_VECTOR_SCALAR((*this), size, / , MATH_LIST) };
	}

	SVector& Normalize()
	{
		auto size = Size();
		MATH_VECTOR_SCALAR((*this), size, /=, MATH_STATE);
		return *this;
	}

public: //--------------| misc

	template<typename Q, typename R>
	SVector Lerp(const TVector<Q> & r, const R & factor) const
	{
		return (*this) - (r - (*this)) * factor;
	}

	std::string ToString() const
	{
		auto ss = std::ostringstream();
		ss 	<< "x: " << x << " "
			<< "y: " << y << " "
			<< "z: " << z;
		return ss.str();
	}

	const static TVector<T> ZeroVector;
};

template<typename T> inline TVector<T> operator+(T r, const TVector<T> & v) { return v + r; }
template<typename T> inline TVector<T> operator-(T r, const TVector<T> & v) { return v - r; }
template<typename T> inline TVector<T> operator*(T r, const TVector<T> & v) { return v * r; }
template<typename T> inline TVector<T> operator/(T r, const TVector<T> & v) { return v / r; }

template<typename T>
const TVector<T> TVector<T>::ZeroVector(0);


// ----------------| Math::
namespace Math
{
	template<typename T>
	TVector<T> Sqrt(const TVector<T>& x)
	{
		return {
			Sqrt(x.x),
			Sqrt(x.y),
			Sqrt(x.z)};
	}

	template<typename T, typename Q>
	TVector<T> Clamp(const TVector<T>& v, Q min, Q max)
	{
		return {
			Clamp(v.x, min, max),
			Clamp(v.y, min, max),
			Clamp(v.z, min, max)};
	}
}


#endif //!MATH__VECTOR_HPP
