#include "HittableGeom.hpp"

void FillSphereHitRecord(HitRecord& rec, const Sphere& sphere, const Ray& ray, double t) {
	rec.t = t;
	rec.point = ray.At(t);
	auto outwardNormal = (rec.point - sphere.center) / sphere.radius;
	rec.SetFaceNormal(ray, outwardNormal);
}

bool Sphere::Hit(const Ray& ray,
	double tMin, double tMax,
	HitRecord& rec) const {

	auto relativeRayOrigin = ray.origin - center;
	auto a = ray.direction.LengthSquared();
	auto halfB = relativeRayOrigin.Dot(ray.direction);
	auto c = relativeRayOrigin.LengthSquared() - radius * radius;
	auto discriminant = halfB * halfB - a * c;
	
	if (discriminant > 0) {
		auto root = Sqrt(discriminant);
		auto t = (-halfB - root) / a;
		if (t < tMax && t > tMin) {
			FillSphereHitRecord(rec, *this, ray, t);
			return true;
		}
		t = (-halfB + root) / a;
		if (t < tMax && t > tMin) {
			FillSphereHitRecord(rec, *this, ray, t);
			return true;
		}
	}

	return false;
}
