#ifndef MATH__MATH_HPP
#define MATH__MATH_HPP

#include "math/macro.hpp"
#include "math/numbers.hpp"
#include "math/functions.hpp"
#include "math/types/color.hpp"
#include "math/types/vector.hpp"
#include "math/types/vector2.hpp"
#include "math/types/quat.hpp"
#include "math/types/transform.hpp"
#include "math/types/plane.hpp"


using FTransform = TTransform<FReal>;
using FVector2 = TVector2<FReal>;
using FVector = TVector<FReal>;
using FPlane = TPlane<FReal>;
using FQUat = TQuat<FReal>;


#endif //!MATH__MATH_HPP
