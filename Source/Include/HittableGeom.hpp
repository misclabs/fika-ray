#pragma once

#include "Hittable.hpp"
#include "FiVec.hpp"
#include "FiRay.hpp"

struct Sphere : public Hittable {
	Vec3d center;
	double radius;

	Sphere(const Vec3d& c, double r) : center{c}, radius{r} {}

	bool Hit(
		const Ray& ray, 
		double tMin, double tMax,
		HitRecord& rec) const override;
};
