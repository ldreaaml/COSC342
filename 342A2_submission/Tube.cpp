#include "Tube.h"

#include "utility.h"


Tube::Tube(double ratio) : Object(), ratio_(ratio) {
}

Tube::Tube(const Tube& tube) : Object(tube), ratio_(tube.ratio_) {

}

Tube::~Tube() {

}

Tube& Tube::operator=(const Tube& tube) {
	if (this != &tube) {
		Object::operator=(tube);
		ratio_ = tube.ratio_;
	}
	return *this;
}

std::vector<RayIntersection> Tube::intersect(const Ray& ray) const {
	std::vector<RayIntersection> result;

	/*****************************************************
	* Code to implement Ray-Tube interesection goes here *
	*****************************************************/

	/* Tube can be made using cylinders and plain. 
	We need two cylinder object for inner and outer surface of the tube and two plains for top and bottom caps*/

	Ray inverseRay = transform.applyInverse(ray);

	const Point &p = inverseRay.point;
	const Direction &d = inverseRay.direction;
	RayIntersection hit;
	hit.material = material;

	// The equation of curved surface of the cylinder is x^2 + y^2 = r^2
	double px = p(0), dx = d(0), py = p(1), dy = d(1);
	double a = (dx * dx) + (dy * dy);
	double b = 2 * ((px * dx) + (py * dy));
	double c = (px * px) + (py * py) - 1;

	double b2_4ac = b * b - 4 * a * c;
	double t;

	/* OUTER SURFACE of the tube */
	switch (sign(b2_4ac))
	{
	case -1:
		// No intersections
		break;
	case 0:
		// One intersection

		t = -b / (2 * a);
		if (t > 0)
		{
			hit.point = p + t * d;
			Normal norm = p + t * d; //normal is hit point with z=0,  [x,y,0]
			norm(2) = 0;
			if (hit.point(2) >= -1 && hit.point(2) <= 1){ //check boundary, make sure length of tube or z value is in range [-1,1]
				
				// Intersection is in front of the ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(norm);
				if (hit.normal.dot(ray.direction) > 0)
				{
					hit.normal = -hit.normal;
				}
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}
		break;
	case 1:
		// Two intersections

		t = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		if (t > 0)
		{
			hit.point = p + t * d;
			Normal norm = p + t * d; //normal is hit point with z=0 ,  [x,y,0]
			norm(2) = 0;
			if (hit.point(2) >= -1 && hit.point(2) <= 1){ //check boundary, z is in range [-1,1]
				// Intersection is in front of the ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(norm);
				if (hit.normal.dot(ray.direction) > 0)
				{
					hit.normal = -hit.normal;
				}
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}

		t = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (t > 0)
		{
			hit.point = p + t * d;
			Normal norm = p + t * d; //normal is hit point with z=0 ,  [x,y,0]
			norm(2) = 0;
			if (hit.point(2) >= -1 && hit.point(2) <= 1){ //check boundary, z is in range [-1,1]
				// Intersection is in front of th ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(norm);
				if (hit.normal.dot(ray.direction) > 0)
				{
					hit.normal = -hit.normal;
				}
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}

		break;
	default:
		// Shouldn't be possible, but just in case
		std::cerr << "Something's wrong - sign(x) should be -1, +1 or 0" << std::endl;
		exit(-1);
		break;
	}

	/* INNER SURFACE of the tube*/
	// for inner surface,  the radius is ratio instead of 1
	c = (p(0) * p(0)) + (p(1) * p(1)) - (ratio_ * ratio_);
	b2_4ac = b * b - 4 * a * c;
	switch (sign(b2_4ac))
	{
	case -1:
		// No intersections
		break;
	case 0:
		// One intersection
		t = -b / (2 * a);
		if (t > 0)
		{
			hit.point = p + t * d;
			Normal norm = p + t * d; //normal is hit point with z=0 ,  [x,y,0]
			norm(2) = 0;
			if (hit.point(2) >= -1 && hit.point(2) <= 1)
			{ //check boundary, z is in range [-1,1]

				// Intersection is in front of the ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(norm);
				if (hit.normal.dot(ray.direction) > 0)
				{
					hit.normal = -hit.normal;
				}
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}
		break;
	case 1:
		// Two intersections

		t = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		if (t > 0)
		{
			hit.point = p + t * d;
			Normal norm = p + t * d; //normal is hit point with z=0 ,  [x,y,0]
			norm(2) = 0;
			if (hit.point(2) >= -1 && hit.point(2) <= 1)
			{ //check boundary, z is in range [-1,1]

				// Intersection is in front of the ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(norm);
				if (hit.normal.dot(ray.direction) > 0)
				{
					hit.normal = -hit.normal;
				}
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}

		t = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (t > 0)
		{
			hit.point = p + t * d;
			Normal norm = p + t * d; //normal is hit point with z=0 ,  [x,y,0]
			norm(2) = 0;
			if (hit.point(2) >= -1 && hit.point(2) <= 1)
			{ //check boundary, z is in range [-1,1]

				// Intersection is in front of th ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(norm);
				if (hit.normal.dot(ray.direction) > 0)
				{
					hit.normal = -hit.normal;
				}
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}

		break;
	default:
		// Shouldn't be possible, but just in case
		std::cerr << "Something's wrong - sign(x) should be -1, +1 or 0" << std::endl;
		exit(-1);
		break;
	}

	double z0 = inverseRay.point(2);
	double dz = inverseRay.direction(2);

	/* TOP CAP of the tube is an XY plane with z = 1*/
	t = (1 - z0) / dz;
	if (std::abs(dz) > epsilon && t > 0){

		RayIntersection hit;
		hit.point = inverseRay.point + t * inverseRay.direction;
		double x = hit.point(0);
		double y = hit.point(1);
		double p = (x * x) + (y * y);
		// need to check if range is between the inner and outer circle
		// ratio <= x^2 + y^2 <= 1
		if (ratio_ * ratio_ <= p && p <= 1)
		{
			hit.material = material;	  //hit point material to be the same as Plane's material
			hit.normal = Normal(0, 0, 1); //XY Plane is perpendicular to z-axis, so the normal is [0 0 1]

			//apply forward transform to it's point and normal to undo inverse transform we applied to the ray
			hit.point = transform.apply(hit.point);
			hit.normal = transform.apply(hit.normal);
			if (hit.normal.dot(ray.direction) > 0)
			{
				hit.normal = -hit.normal;
			}
			//calculate distance between ray's starting point and hit point
			hit.distance = (hit.point - ray.point).norm();
			result.push_back(hit);
		}
	}

	/* BOTTOM CAP of the tube is an XY plane with z = -1*/
	t = (-1 - z0) / dz;
	if (std::abs(dz) > epsilon && t > 0)
	{
		RayIntersection hit;
		hit.point = inverseRay.point + t * inverseRay.direction;
		double x = hit.point(0);
		double y = hit.point(1);
		double p = (x * x) + (y * y);
		// need to check if range is between the inner and outer circle
		// ratio <= x^2 + y^2 <= 1
		if (ratio_ * ratio_ <= p && p <= 1)
		{
			hit.material = material;	  //hit point material to be the same as Plane's material
			hit.normal = Normal(0, 0, 1); //XY Plane is perpendicular to z-axis, so the normal is [0 0 1]

			//apply forward transform to it's point and normal to undo inverse transform we applied to the ray
			hit.point = transform.apply(hit.point);
			hit.normal = transform.apply(hit.normal);
			if (hit.normal.dot(ray.direction) > 0)
			{
				hit.normal = -hit.normal;
			}
			//calculate distance between ray's starting point and hit point
			hit.distance = (hit.point - ray.point).norm();
			result.push_back(hit);
		}
	}

	return result;
}
