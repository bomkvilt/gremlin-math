#ifndef MATH__FUNCTIONS_HPP
#define MATH__FUNCTIONS_HPP

#include <algorithm>
#include "Math/numbers.hpp"


namespace Math
{
	// constants
	
	constexpr FReal Pi      = static_cast<FReal>(3.141593);
	constexpr FReal Epsilon = static_cast<FReal>(1e-05);

	// misc

	template<typename T, typename Q>
	T Clamp(T v, Q min, Q max)
	{
		return v > max ? max
			: v < min ? min
			: v;
	}
	
	float  Sqrt(float  x);
	double Sqrt(double x);

	template<typename T, typename R, typename Q>
	bool Equal(const T& x, const R& y, const Q& delta)
	{
		return Abs(x - y) < delta;
	}

	template<typename T, typename R>
	bool Equal(const T& x, const R& y)
	{
		return Equal(x, y, Epsilon);
	}

	template<typename T>
	T Sign(const T& x)
	{
		if (x > 0) return +1;
		if (x < 0) return -1;
		return 0;
	}

	float  Cos(float  x);
	double Cos(double x);
	float  Sin(float  x);
	double Sin(double x);
	float  Tan(float  x);
	double Tan(double x);
	float  Cot(float  x);
	double Cot(double x);

	float  Acos(float  x);
	double Acos(double x);
	float  Asin(float  x);
	double Asin(double x);
	float  Atan(float  x);
	double Atan(double x);
	float  Atan2(float  x, float  y);
	double Atan2(double x, double y);

	float  Abs(float  x);
	double Abs(double x);
	float  Mod(float  x, float  y);
	double Mod(double x, double y);
	float  Max(float  x, float  y);
	double Max(double x, double y);
	float  Min(float  x, float  y);
	double Min(double x, double y);
	float  Avg(float  x, float  y);
	double Avg(double x, double y);
}


template<typename T> 
constexpr FReal  DEG2RAD(const T     & x) { return static_cast<FReal >((x * Math::Pi) / 180); }
constexpr float  DEG2RAD(const float & x) { return static_cast<float >((x * Math::Pi) / 180); }
constexpr double DEG2RAD(const double& x) { return static_cast<double>((x * Math::Pi) / 180); }


template<typename T> 
constexpr FReal  RAD2DEG(const T     & x) {  return static_cast<FReal >((x * 180) / Math::Pi); }
constexpr float  RAD2DEG(const float & x) {  return static_cast<float >((x * 180) / Math::Pi); }
constexpr double RAD2DEG(const double& x) {  return static_cast<double>((x * 180) / Math::Pi); }


#endif //!MATH__FUNCTIONS_HPP
