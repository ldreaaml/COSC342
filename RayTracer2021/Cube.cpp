/* $Rev: 250 $ */
#include "Cube.h"

#include "utility.h"

Cube::Cube() : Object() {

}

Cube::Cube(const Cube& cube) : Object(cube) {

}

Cube::~Cube() {

}

Cube& Cube::operator=(const Cube& cube) {
	if (this != &cube) {
		Object::operator=(cube);
	}
	return *this;
}

std::vector<RayIntersection> Cube::intersect(const Ray& ray) const {

	
	std::vector<RayIntersection> result;
	
	/*****************************************************
	* Code to implement Ray-Cube interesection goes here *
	*****************************************************/

	Ray inverseRay = transform.applyInverse(ray);

	/* 2 plane on Z-Axis   with  z = +- 1 */

	//front plane z = 1
	//z0 + t(dz) =  1   -> (1-z0)/dz  
	double z0 = inverseRay.point(2); //z value?
	double dz = inverseRay.direction(2);
	double t = (1-z0)/dz;

	if(std::abs(dz) > epsilon){ //if ray hit the plain

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

	//back plane z = -1;
	//z0 = t(dz) = -1   -> (-1-z0)/dz
	t = (-1-z0)/dz;
	if(std::abs(dz) > epsilon){ //if ray hit the plain
		
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

	/* Adding another 2 plane on Y axis   */
	// y0 + t(dy) = +- 1;
	// hit point in x,z are in range [-1,1]
	// normal vector point along y axis

	double y0 = inverseRay.point(1); //point 1 because y axis
	double dy = inverseRay.direction(1); 

	//first plain on y axis
	t = (1-y0)/dy;	
	if(std::abs(dy) > epsilon){
		// std::cout<<"y"<<std::endl;
		RayIntersection hit; 
		hit.point = inverseRay.point + t * inverseRay.direction; //find hit point 
		if(hit.point(0) <= 1 && hit.point(0) >= -1){ //x and z is within range [-1,1]
			if(hit.point(2)<=1 && hit.point(2)>=-1){ 

				hit.material = material; 
				hit.normal = Normal(0,1,0); //the normal now point along y axis!
				
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}

		}
	}
	t = (-1-y0)/dy;	
	if(std::abs(dy) > epsilon){
		// std::cout<<"y"<<std::endl;
		RayIntersection hit; 
		hit.point = inverseRay.point + t * inverseRay.direction; //find hit point 
		if(hit.point(0) <= 1 && hit.point(0) >= -1){ //x and z is within range [-1,1]
			if(hit.point(2)<=1 && hit.point(2)>=-1){ 

				hit.material = material; 
				hit.normal = Normal(0,1,0); //the normal now point along y axis!
				
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}

		}
	}

	// Adding 2 more plan on X Axis
	// x0 + t(dx) = +- 1;
	// hit point in y,z are in range [-1,1]
	// normal vector point along x axis
	double x0 = inverseRay.point(0);
	double dx = inverseRay.point(0);
	t = (1-x0)/dx;
	if(std::abs(dy) > epsilon){
		RayIntersection hit; 
		hit.point = inverseRay.point + t * inverseRay.direction; //find hit point 
		if(hit.point(1) <= 1 && hit.point(1) >= -1){ //y and z is within range [-1,1]
			if(hit.point(2)<=1 && hit.point(2)>=-1){ 

				hit.material = material; 
				hit.normal = Normal(1,0,0); //the normal now point along y axis!
				
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}

		}
	}
	t = (-1-x0)/dx;
	if(std::abs(dy) > epsilon){
		RayIntersection hit; 
		hit.point = inverseRay.point + t * inverseRay.direction; //find hit point 
		if(hit.point(1) <= 1 && hit.point(1) >= -1){ //y and z is within range [-1,1]
			if(hit.point(2)<=1 && hit.point(2)>=-1){ 

				hit.material = material; 
				hit.normal = Normal(1,0,0); //the normal now point along y axis!
				
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}

		}
	}

	return result;
}
