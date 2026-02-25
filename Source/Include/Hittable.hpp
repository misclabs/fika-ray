#pragma once

#include "FiVec.hpp"
#include "FiRay.hpp"

struct HitRecord {
	Vec3d point;
	Vec3d normal;
	double t;
	bool frontFace;

	inline void SetFaceNormal(const Ray& ray, const Vec3d& outwardNormal) {
		frontFace = ray.direction.Dot(outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

struct Hittable {
	virtual bool Hit(
		const Ray& ray, 
		double tMin, double tMax,
		HitRecord& rec) const = 0;
};
