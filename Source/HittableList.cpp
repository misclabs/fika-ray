#include "HittableList.hpp"

bool HittableList::Hit(
	const Ray& ray, 
	double tMin, double tMax,
	HitRecord& rec) const {

	HitRecord tempRec;
	bool didHitAnything = false;
	auto closestTSoFar = tMax;

	for (const auto& object : objects) {
		if (object->Hit(ray, tMin, closestTSoFar, tempRec)) {
			didHitAnything = true;
			closestTSoFar = tempRec.t;
			rec = tempRec;
		}
	}

	return didHitAnything;
}	
