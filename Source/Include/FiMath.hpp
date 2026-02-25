#pragma once

#include <limits>

struct MathConstants {
	inline static const double Infinity = std::numeric_limits<double>::infinity();
	inline static const double Pi = 3.1415926535897932385;
};

template<typename Number>
Number DegreesToRadians(Number degrees);

template<typename NumberType>
NumberType Sqrt(NumberType x);

// linear blend aka linear interpolation
template<typename LerpedType, typename ParamType>
LerpedType Lerp(const LerpedType& start, const LerpedType& end, ParamType t);
