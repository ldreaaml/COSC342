#pragma once

#include "Image.h"
#include "Pixel.h"

class Shape {

public:

	Shape(const Pixel& colour);
	Shape(const Shape& shape);
	virtual ~Shape();

	Shape& operator=(const Shape& shape);

	virtual void draw(Image& image) const = 0; 
	//^this means no implementation will be provided for the base shape
	// which means shape becomes an abstract class
	// and we cant create Shape Object, but only its sub class
	
	void setColour(Pixel colour);

protected:

	Pixel colour_;

};