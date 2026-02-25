#pragma once

#include "Hittable.hpp"
#include "FiRay.hpp"

#include <memory>
#include <vector>

using std::make_shared;

struct HittableList : public Hittable {
	using HittableSharedPtr = std::shared_ptr<Hittable>;

	std::vector<HittableSharedPtr> objects;

	bool Hit(
		const Ray& ray, 
		double tMin, double tMax,
		HitRecord& rec) const override;	
};

