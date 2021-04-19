#include "Plane.h"

#include "utility.h"

Plane::Plane() : Object() {

}

Plane::Plane(const Plane& plane) : Object(plane) {

}

Plane::~Plane() {

}

Plane& Plane::operator=(const Plane& plane) {
	if (this != &plane) {
		Object::operator=(plane);
	}
	return *this;
}

std::vector<RayIntersection> Plane::intersect(const Ray& ray) const {

	std::vector<RayIntersection> result;

	Ray inverseRay = transform.applyInverse(ray);
	/******************************************************
	* Code to implement Ray-Plane interesection goes here *
	******************************************************/

	// plane x,y with z=0
	// z0 = point, dz = direction
	// z0 + t(dz) = 0   OR   t = -z0/dz

	// double z0 = inverseRay.point(2);
	// double dz = inverseRay.direction(2);
	// double t = -z0/dz;

	// if(std::abs(dz) < epsilon){ //if value is 

	// 	RayIntersection hit; //find hit point 
	// 	hit.point = inverseRay.point + t * inverseRay.direction;

	// 	if(hit.point(0) <= 1 && hit.point(0) >= -1){ //x is within range [-1,1]
	// 		if(hit.point(1)<=1 && hit.point(1)>=-1){ //y is within range [-1,1]
	// 			hit.material = material; //the hit point material to be the same as plane's material
	// 			Vector normalHit(3);
	// 			normalHit(0) = 0; normalHit(0) = 0; normalHit(2) = 1;
	// 			hit.normal = normalHit; //the hit point normal is [0 0 1]
				
	// 			/* next step is apply forward transform to it's point and normal to undo inverse transform we applied to the ray */
	// 			// hit.point = transform.apply(Point(inverseRay.point + t*inverseRay.direction));
	// 			// hit.point = transform.apply(Normal(inverseRay.point + t*inverseRay.direction));
	// 			hit.point = transform.apply(hit.point);
	// 			hit.normal = transform.apply(hit.normal);

	// 			hit.distance = (hit.point - ray.point).norm(); //calculate distance between ray's starting point and hit point
	// 			result.push_back(hit);
	// 		}

	// 	}
	// }

	double zO = inverseRay.point(2);
	double dz = inverseRay.direction(2);
	double t = -zO/dz;
	
	if (std::abs(dz) > epsilon && t > 0){
		RayIntersection hit;
		hit.point = inverseRay.point + t*inverseRay.direction;
		
		if(hit.point(0) >= -1 && hit.point(0) <= 1 &&
			hit.point(1) >= -1 && hit.point(1) <= 1){
			
			hit.material = material;
			
			Vector normalHit(3);
			normalHit(0) = 0; normalHit(1) = 0; normalHit(2) = 1;
			hit.normal = normalHit;
			
			hit.point = transform.apply(hit.point);
			hit.normal = transform.apply(hit.normal);
			hit.distance = (hit.point - ray.point).norm();
			
			result.push_back(hit);
		}
		
	}

	return result;
}