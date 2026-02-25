#pragma once

#include <cstdlib>

template<typename T>
inline T Min(T a, T b) { return a <= b ? a : b; }

template<typename T>
inline T Max(T a, T b) { return a >= b ? a : b; }

template<typename T>
inline T Clamp(T x, T min, T max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

inline double Random() {
	return rand() / (RAND_MAX + 1.0); // #todo: template constant
}

inline double Random(double min, double max) {
	return min + (max-min) * Random();
}