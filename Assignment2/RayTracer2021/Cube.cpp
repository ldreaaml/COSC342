/* $Rev: 250 $ */
#include "Cube.h"

#include "utility.h"

Cube::Cube() : Object()
{
}

Cube::Cube(const Cube &cube) : Object(cube)
{
}

Cube::~Cube()
{
}

Cube &Cube::operator=(const Cube &cube)
{
	if (this != &cube)
	{
		Object::operator=(cube);
	}
	return *this;
}

std::vector<RayIntersection> Cube::intersect(const Ray &ray) const
{

	std::vector<RayIntersection> result;

	/*****************************************************
	* Code to implement Ray-Cube interesection goes here *
	*****************************************************/

	//apply inverse transormation to ray
	Ray inverseRay = transform.applyInverse(ray);

	if (true)
	{

		//The cube will be made from 6 planes which align on different axes
		//[x,y,z] = [x0,y0,z0] + t[dx,dy,dz]

		/*Two faces parallel to X-Y plane, shift +-1 unit along the Z-axis
		 z = +-1 = z0 + t(dz)  , rearrange equation to  t = (+-1)-z0/dz */
		double z0 = inverseRay.point(2);
		double dz = inverseRay.direction(2);
		double t;

		//This plane shift 1 unit on Z-axis  t = 1-z0/dz
		t = (1 - z0) / dz;
		if (std::abs(dz) > epsilon&& t>0)
		{ //check if ray hits the plane
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; //find the point where ray hit??

			//check if hit point's X and Y value lie in the range [-1,1]
			if (hit.point(0) >= -1 && hit.point(0) <= 1 && hit.point(1) >= -1 && hit.point(1) <= 1)
			{

				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(0, 0, 1); //Z=0, so hit point normal is [0,0,1] ??

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
		//This plane shift 1 unit on Z-axis  t = 1-z0/dz
		t = (-1 - z0) / dz;
		if (std::abs(dz) > epsilon&& t>0)
		{ //check if ray hits the plane
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; //find the point where ray hit??

			//check if hit point's X and Y value lie in the range [-1,1]
			if (hit.point(0) >= -1 && hit.point(0) <= 1 && hit.point(1) >= -1 && hit.point(1) <= 1)
			{

				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(0, 0, 1); //Z=0, so hit point normal is [0,0,1]

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

		/*Two faces parallel to X-Z plane, shift +-1 unit along the Y-axis
		 y = +-1 = y0 + t(dy)  , rearrange equation to  t = (+-1)-y0/dy */

		double y0 = inverseRay.point(1);
		double dy = inverseRay.direction(1);

		//This plane shift 1 unit on Z-axis  t = 1-z0/dz
		t = (1 - y0) / dy;
		if (std::abs(dy) > epsilon&& t>0)
		{ //check if ray hits the plane
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; //find the point where ray hit??

			//check if hit point's X and Z value lie in the range [-1,1]
			if (hit.point(0) >= -1 && hit.point(0) <= 1 && hit.point(2) >= -1 && hit.point(2) <= 1)
			{

				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(0, 1, 0); //normal vector point along Y-axis

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
		//This plane shift -1 unit on Y-axis  t = 1-z0/dz
		t = (-1 - y0) / dy;
		if (std::abs(dy) > epsilon&& t>0)
		{ //check if ray hits the plane
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; //find the point where ray hit??

			//check if hit point's X and Z value lie in the range [-1,1]
			if (hit.point(0) >= -1 && hit.point(0) <= 1 && hit.point(2) >= -1 && hit.point(2) <= 1)
			{

				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(0, 1, 0); //normal vector point along Y-axis

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

		/*Two faces parallel to Y-Z plane, shift +-1 unit along the X-axis
		 x = +-1 = x0 + t(dx)  , rearrange equation to  t = (+-1)-x0/dx */

		double x0 = inverseRay.point(0);
		double dx = inverseRay.direction(0);

		//This plane shift 1 unit on X-axis  t = 1-x0/dx
		t = (1 - x0) / dx;
		if (std::abs(dx) > epsilon&& t>0)
		{ //check if ray hits the plane
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; //find the point where ray hit??

			//check if hit point's Y and Z value lie in the range [-1,1]
			if (hit.point(1) >= -1 && hit.point(1) <= 1 && hit.point(2) >= -1 && hit.point(2) <= 1)
			{

				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(1, 0, 0); //normal vector point along Y-axis

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

		//This plane shift 1 unit on X-axis  t = 1-x0/dx
		t = (-1 - x0) / dx;
		if (std::abs(dx) > epsilon && t>0)
		{ //check if ray hits the plane
			RayIntersection hit;
			hit.point = inverseRay.point + t * inverseRay.direction; //find the point where ray hit??

			//check if hit point's Y and Z value lie in the range [-1,1]
			if (hit.point(1) >= -1 && hit.point(1) <= 1 && hit.point(2) >= -1 && hit.point(2) <= 1)
			{

				hit.material = material;	  //hit point material to be the same as Plane's material
				hit.normal = Normal(1, 0, 0); //normal vector point along Y-axis

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

	} //END IF

	return result;
}