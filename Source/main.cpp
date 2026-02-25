#include "FikaRay.hpp"

#include "FiMath.hpp"
#include "FiVec.hpp"
#include "FiRay.hpp"
#include "FiCamera.hpp"
#include "Hittable.hpp"
#include "HittableGeom.hpp"
#include "HittableList.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <type_traits>
#include <memory>

using std::make_shared;

Vec3i Color256FromNormalized(const Vec3d& normalizedColor) {
	return Vec3i {
		static_cast<int>(255.999 * normalizedColor.r),
		static_cast<int>(255.999 * normalizedColor.g),
		static_cast<int>(255.999 * normalizedColor.b)
	};
}

inline std::ostream& operator<<(std::ostream& out, const Vec3i& vec) {
	return out << vec.x << ' ' << vec.y << ' ' << vec.z;
}

double HitSphere(const Vec3d& center, double radius, const Ray ray) {
	Vec3d relativeRayOrigin = ray.origin - center;
	double a = ray.direction.LengthSquared();
	double halfB = relativeRayOrigin.Dot(ray.direction);
	double c = relativeRayOrigin.LengthSquared() - radius * radius;
	double discriminant = halfB * halfB - a * c;
	if (discriminant < 0)
		return -1.0;
	else
		return (-halfB - Sqrt(discriminant)) / a;
}

Vec3d RayColor(const Ray& ray, const Hittable& world) {
	HitRecord rec;
	if (world.Hit(ray, 0, MathConstants::Infinity, rec)) {
		return 0.5 * (rec.normal + Vec3d{1.0, 1.0, 1.0});
	}

	Vec3d unitDir = ray.direction.Normalized();
	double t = 0.5 * (unitDir.y + 1.0);
	return Lerp(
		Vec3d{1.0, 1.0, 1.0}, Vec3d{0.5, 0.7, 1.0}, t);
}


int main() {
	const int imageWidth = 720;
	const int imageHeight = 480;
	const int samplesPerPixel = 100;

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
	Vec3d lowerLeft{-2.0, -1.0, -1.0};
	Vec3d horizontal{4.0, 0.0, 0.0};
	Vec3d vertical{0.0, 2.0, 0.0};
	Vec3d origin{0.0, 0.0, 0.0};

	HittableList world;
	world.objects.push_back(make_shared<Sphere>(Vec3d{0, 0, -1}, 0.5));
	world.objects.push_back(make_shared<Sphere>(Vec3d{0, -100.5, -1}, 100));

	Vec3i* imageData = new Vec3i[imageWidth * imageHeight];
	Camera camera;
	for (int j = imageHeight - 1; j >= 0; --j) {
		std::cerr << "\rRendering: scanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i) {
			Vec3d color{0, 0, 0};
			for (int s = 0; s < samplesPerPixel; ++s) {
				auto u = (i + Random()) / imageWidth;
				auto v = (j + Random()) / imageHeight;
				auto ray = camera.GetRay(u, v);
				
				color += RayColor(ray, world);
			}

			color *= (1.0 / samplesPerPixel);

			color.r = Clamp(color.r, 0.0, 0.999);
			color.g = Clamp(color.g, 0.0, 0.999);
			color.b = Clamp(color.b, 0.0, 0.999);

			imageData[j*imageWidth + i] = Color256FromNormalized(color);
		}
	}
	std::cerr << "\rRendering complete\n";

	for (int j = imageHeight - 1; j >= 0; --j) {
		std::cerr << "\rWriting: scanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i) {
			std::cout << imageData[j*imageWidth + i] << '\n';
		}
	}
	std::cerr << "\rWriting complete\n";

	std::cerr << "Fin.\n";

	return 0;
}
