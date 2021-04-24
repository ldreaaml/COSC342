#include "Cylinder.h"

#include "utility.h"

Cylinder::Cylinder() : Object()
{
}

Cylinder::Cylinder(const Cylinder &cylinder) : Object(cylinder)
{
}

Cylinder::~Cylinder()
{
}

Cylinder &Cylinder::operator=(const Cylinder &cylinder)
{
	if (this != &cylinder)
	{
		Object::operator=(cylinder);
	}
	return *this;
}

std::vector<RayIntersection> Cylinder::intersect(const Ray &ray) const
{

	std::vector<RayIntersection> result;

	/*********************************************************
	* Code to implement Ray-Cylinder interesection goes here *
	*********************************************************/

	Ray inverseRay = transform.applyInverse(ray);

	const Point &p = inverseRay.point;
	const Direction &d = inverseRay.direction;
	// Equation is x^2 + y^2 = 1
	// x = px + dx(t)  and   y = py + dy(t)  - see full working in the summary report
	double px = p(0), dx = d(0), py = p(1), dy = d(1);

	double a = (dx * dx) + (dy * dy);
	double b = 2 * ((px * dx) + (py * dy));
	double c = (px * px) + (py * py) - 1;

	RayIntersection hit;
	hit.material = material;

	double b2_4ac = b * b - 4 * a * c;
	double t;

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
			if (hit.point(2) >= -1 && hit.point(2) <= 1)
			{
				// Intersection is in front of the ray's start point

				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(Normal(1, 1, 0)); //Normal point to ??
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
			if (hit.point(2) >= -1 && hit.point(2) <= 1)
			{
				// Intersection is in front of the ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(Normal(1, 1, 0));
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
			if (hit.point(2) >= -1 && hit.point(2) <= 1)
			{
				// Intersection is in front of th ray's start point
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(Normal(1, 1, 0));
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

	if(true){ 
		// cap is essentially a plane but we calculate the boundary to make sure it doesn't render the part outside the circle
		//top cap  = plane with z = 1
		double z0 = inverseRay.point(2);
		double dz = inverseRay.direction(2);
		t = (1 - z0) / dz;
		if (std::abs(dz) > epsilon)  // ++ t>0?? 
		{ 
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; 
			// boundary x^2 + y^2 < 1   &&  x^2 + y^2 > -1
			double x = hit.point(0);
			double y = hit.point(1);
			if ( (x*x + y*y) >= -1 && (x*x + y*y) <=1)
			{
				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(0, 0, 1); //Z=0, so hit point normal is [0,0,1] ??

				//apply forward transform to it's point and normal to undo inverse transform we applied to the ray
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				//calculate distance between ray's starting point and hit point
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}
		//bottom cap = plane with z = -1
		t = (-1 - z0) / dz;
		if (std::abs(dz) > epsilon)  // ++ t>0?? 
		{ 
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; 
			// x^2 + y^2 < 1   &&  x^2 + y^2 > -1
			double x = hit.point(0);
			double y = hit.point(1);
			if ( (x*x + y*y) >= -1 && (x*x + y*y) <=1)
			{
				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(0, 0, 1); //Z=0, so hit point normal is [0,0,1] ??

				//apply forward transform to it's point and normal to undo inverse transform we applied to the ray
				hit.point = transform.apply(hit.point);
				hit.normal = transform.apply(hit.normal);

				//calculate distance between ray's starting point and hit point
				hit.distance = (hit.point - ray.point).norm();
				result.push_back(hit);
			}
		}
	}


	return result;
}
