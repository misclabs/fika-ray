#pragma once

#include "FiVec.hpp"
#include "FiRay.hpp"

struct Camera {
	Vec3d origin;
	Vec3d lowerLeftCorner;
	Vec3d horizontal;
	Vec3d vertical;

	Camera() : 
		origin(Vec3d{0, 0, 0}), 
		lowerLeftCorner(Vec3d{-2, -1, -1}),
		horizontal(Vec3d{4, 0, 0}),
		vertical(Vec3d{0, 2, 0})
	{}

	inline Ray GetRay(double u, double v) {
		return Ray{origin, lowerLeftCorner + u*horizontal + v*vertical - origin};
	}
};