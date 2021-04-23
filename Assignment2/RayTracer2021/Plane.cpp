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

	/******************************************************
	* Code to implement Ray-Plane interesection goes here *
	******************************************************/
	Ray inverseRay = transform.applyInverse(ray);

	double z0 = inverseRay.point(2); //z value?
	double dz = inverseRay.direction(2);
	double t = -z0/dz;

	if(std::abs(dz) > epsilon && t>0){ //if ray hit the plain

		RayIntersection hit; 
		hit.point = inverseRay.point + t * inverseRay.direction; //find hit point 

		if(hit.point(0) <= 1 && hit.point(0) >= -1){ //x is within range [-1,1]
			if(hit.point(1)<=1 && hit.point(1)>=-1){ //y is within range [-1,1]

				hit.material = material; //the hit point material to be the same as plane's material
				hit.normal = Normal(0,0,1); //the hit point normal is [0 0 1]
				
				/* next step is apply forward transform to it's point and normal to undo inverse transform we applied to the ray */
				
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				hit.distance = (hit.point - ray.point).norm(); //calculate distance between ray's starting point and hit point
				result.push_back(hit);
			}

		}
	}
	return result;
}