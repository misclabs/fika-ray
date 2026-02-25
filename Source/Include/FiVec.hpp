#pragma once

#include "FiMath.hpp"

#include <type_traits>

template<typename ComponentType>
struct Vec3 {
	union {
		struct {
			ComponentType x;
			ComponentType y;
			ComponentType z;
		};
		struct {
			ComponentType r;
			ComponentType g;
			ComponentType b;
		};
		ComponentType v[3];
	};

	auto operator+=(const Vec3<ComponentType>& right) {
		x += right.x;
		y += right.y;
		z += right.z;

		return *this;
	}

	auto operator*=(const Vec3<ComponentType>& right) {
		x *= right.x;
		y *= right.y;
		z *= right.z;

		return *this;
	}

	auto operator*=(ComponentType right) {
		x *= right;
		y *= right;
		z *= right;

		return *this;
	}
	
	ComponentType LengthSquared() const {
		return x * x + y * y + z * z;
	}

	ComponentType Length() const {
		return Sqrt<ComponentType>(LengthSquared());
	}

	Vec3<ComponentType> Normalized() const {
		return *this / Length();
	}

	ComponentType Dot(const Vec3<ComponentType>& right) const {
		return x * right.x + y * right.y + z * right.z;
	}
};

template<typename ComponentType>
Vec3<ComponentType> operator*(ComponentType t, const Vec3<ComponentType>& v) {
	return Vec3<ComponentType>{ t*v.x, t*v.y, t*v.z };
}

template<typename ComponentType>
Vec3<ComponentType> operator+(const Vec3<ComponentType>& left, const Vec3<ComponentType>& right) {
	return Vec3<ComponentType>{
		left.x + right.x,
		left.y + right.y,
		left.z + right.z
	};
}

template<typename ComponentType>
Vec3<ComponentType> operator-(const Vec3<ComponentType>& vec) {
	return Vec3<ComponentType>{ -vec.x, -vec.y, -vec.z };
}

template<typename ComponentType>
Vec3<ComponentType> operator-(const Vec3<ComponentType>& left, const Vec3<ComponentType>& right) {
	return Vec3<ComponentType>{
		left.x - right.x,
		left.y - right.y,
		left.z - right.z
	};
}

template<typename ComponentType>
Vec3<ComponentType> operator*(const Vec3<ComponentType>& v, ComponentType t) {
	return Vec3<ComponentType>{
		v.x * t,
		v.y * t,
		v.z * t
	};
}

template<typename ComponentType>
Vec3<ComponentType> operator/(const Vec3<ComponentType>& v, ComponentType t) {
	static_assert(std::is_floating_point<ComponentType>::value, "");
	return Vec3<ComponentType>{
		v.x / t,
		v.y / t,
		v.z / t
	};
}

using Vec3d = Vec3<double>;
using Vec3i = Vec3<int>;
