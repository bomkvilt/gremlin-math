#ifndef MATH__NUMBERS_HPP
#define MATH__NUMBERS_HPP

#include <cinttypes>

//-------| common floating point type

#ifndef bDouble
using FReal = float;
#else
using FReal = double;
#endif

//-------| unsigned int types

using Int8  = int8_t;
using Int16 = int16_t;
using Int32 = int32_t;
using Int64 = int64_t;
using Int   = Int32;

//-------| signed int types

using UInt8  = uint8_t;
using UInt16 = uint16_t;
using UInt32 = uint32_t;
using UInt64 = uint64_t;
using UInt   = UInt32;



#endif //!MATH__NUMBERS_HPP
