#ifndef MATH__MACRO_HPP
#define MATH__MACRO_HPP


#define DEG2RAD(x)	((x * Math::Pi ) / 180)
#define RAD2DEG(x)	((x * 180) / Math::Pi )
#define MATH_LIST		, /**/
#define MATH_STATE		; /**/


#define MATH_VECTOR_VECTOR(A, B, OP, SP)		\
	(A.x OP B.x) SP						\
	(A.y OP B.y) SP						\
	(A.z OP B.z) 						\
/**/

#define MATH_VECTOR_SCALAR(V, S, OP, SP)		\
	(V.x OP S) SP						\
	(V.y OP S) SP						\
	(V.z OP S) 							\
/**/

#define MATH_VECTOR2_VECTOR2(A, B, OP, SP)	\
	(A.x OP B.x) SP						\
	(A.y OP B.y)						\
/**/

#define MATH_VECTOR2_SCALAR(V, S, OP, SP)	\
	(V.x OP S) SP						\
	(V.y OP S) 							\
/**/

#define MATH_QUAT_QUAT(A, B, OP, SP)			\
	(A.w OP B.w) SP						\
	(A.x OP B.x) SP						\
	(A.y OP B.y) SP						\
	(A.z OP B.z) 						\
/**/

#define MATH_QUAT_SCALAR(V, S, OP, SP)		\
	(V.x OP S) SP						\
	(V.y OP S) SP						\
	(V.z OP S) 							\
/**/



#endif //!MATH__MACRO_HPP
