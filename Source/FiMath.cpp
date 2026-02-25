#include "FiMath.hpp"
#include "FiVec.hpp"

#include <cmath>

template<typename Number>
Number DegreesToRadians(Number degrees) {
	return degrees * MathConstants::Pi / Number{180.0};
}

template<typename NumberType>
NumberType Sqrt(NumberType x) {
	// todo(jw): use intrinsic 
	return std::sqrt(x);
}

// linear blend aka linear interpolation
template<typename LerpedType, typename ParamType>
LerpedType Lerp(const LerpedType& start, const LerpedType& end, ParamType t) {
	return (ParamType{1.0} - t)*start + t*end;
}

template Vec3d Lerp(const Vec3d& start, const Vec3d& end, double t);
template double DegreesToRadians(double degrees);
template double Sqrt(double x);