#pragma once

#include "FiVec.hpp"

struct Ray {
	Vec3d origin;
	Vec3d direction;

	Vec3d At(double t) const {
		return origin + t*direction;
	}
};
