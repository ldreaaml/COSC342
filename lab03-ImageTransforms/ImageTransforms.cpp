
// Simple, portable image I/O libraries
#include "Image.h"

// Standard I/O
#include <iostream>

// Will be needed for trigonometric functions
#include <cmath>

Vector transform(Vector v){
	Matrix T(3,3); //transform matrix shift 50 left 20 down
	T(0,0) = 1; T(0,1) =0; T(0,2) =-50;
	T(1,0) = 0; T(1,1) =1; T(1,2) =20;
	T(2,0) = 0; T(2,1) =0; T(2,2) =1;
	Vector u = T*v;	
	return u;
}

double radian(double d){
	return (M_PI * 30)/180;
}

Vector rotate(Vector v){

	Matrix T(3,3);
	T(0,0) = cos(radian(30)); T(0,1) = (sin(radian(30))*-1); T(0,2) =0;
	T(1,0) = sin(radian(30)); T(1,1) = cos(radian(30));  T(1,2) =0;
	T(2,0) = 0; T(2,1) =0; T(2,2) =1;
	Vector u = T*v;
	return u;
}

int main(int argc, char *argv[]) {

	
	// Expecting two arguments
	if (argc != 3) {
		std::cout << "Usage: ImageTransforms <input image> <output image>" << std::endl;
		std::cout <<"123" << std::endl;
		exit(-1);
	}

	Image inputImage;
	inputImage.read(argv[1]);
	//create output image of same size
	Image outputImage(inputImage.width(), inputImage.height());
	try {		
		Vector v(3);
		v(2) = 1;
		for (v(1) = 0; v(1) < outputImage.height(); ++v(1)) {
  			for (v(0) = 0; v(0) < outputImage.width(); ++v(0)) {
				Vector u = rotate(v);
				u /= u(2); //in case last element is not 1
				if(u(0) >= 0 && u(0) < outputImage.width() && 
				  u(1) >= 0 && u(1) < outputImage.height()){
					outputImage(v) = inputImage(u);
				}
			} 
		}
	} catch (std::out_of_range exception) {
		std::cout << exception.what() << std::endl;
	}
	outputImage.write_png(argv[2]);

    return 0;
}



void test(){

	/*for (int y = 0; y < inputImage.height(); ++y) {
			for (int x = 0; x < inputImage.width(); ++x) {
				outputImage(x, y) = inputImage(x, y);
			}
		}*/
}

	


