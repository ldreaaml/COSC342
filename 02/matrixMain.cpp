/* 
   MacOS / Linux shell command for compilation that worked for us:
   c++ Vector.cpp Matrix.cpp matrixMain.cpp -o matrixMain

   Then you can run the resulting executable:
   ./matrixMain
 */


#include "Matrix.h"
#include "Vector.h"

#include <iostream>

Vector vect(int a,int b, int c){
	Vector v(3);
	v(0) = a; v(1) = b; v(2) = c;
	return v;
}

void exercise1(){
    Vector u(3), v(3);
    u(0) =1;
	u(1) =-3;
	u(2) =2;
	v(0) =3;
	v(1) =2;
	v(2) =0;
	
	std::cout << "Vector u :" <<std::endl;
	std::cout << u <<std::endl; 
	std::cout << "Vector v :" <<std::endl;
	std::cout << v <<std::endl; 

	std::cout << "2u\n" << 2*u <<std::endl;
	std::cout << "u+v\n" << u+v << std::endl;
	std::cout << "u-v\n" << u-v << std:: endl;
	std::cout << "2u-3v\n" << (2*u)-(3*v) << std:: endl;
}

void exercise2(){
	Vector v = vect(1,2,-2);
	
	std::cout <<"(1,2,-2) dot (1,2,-2) = " << v.dot(v) << std::endl;
	std::cout <<"(1,2,-2) dot (-2,2,1) =" << v.dot(vect(-2,2,1)) << std::endl;
	std::cout <<"(1,2,-2) dot (2,3,1) =" << v.dot(vect(2,3,1)) << std::endl;

	std::cout <<"\n(1,2,-2) x (-2,2,1) =\n" << v.cross(vect(-2,2,1)) << std::endl;
	std::cout <<"(1,2,-2) x (-2,-4,4) =\n" << v.cross(vect(-2,-4,4)) << std::endl;
	std::cout <<"(1,2,-2) dot((1,2,-2) x (-2,2,1)) = " << v.dot(v.cross(vect(-2,2,1))) << std::endl;

}


void exercise3(){
	Matrix m(2,2);
	

}

int main () {

	Matrix A(3,3);
	Vector v(3);

	A(0,0) = 1;
	A(0,1) = 0;
	A(0,2) = 0;
	A(1,0) = 0;
	A(1,1) = 0.5;
	A(1,2) = -1;
	A(2,0) = 2;
	A(2,1) = 2;
	A(2,2) = 0;

	std::cout << "The Matrix A is:" << std::endl;
	std::cout << A << std::endl;

	v(0) = 1;
	v(1) = 2;
	v(2) = 3;

	std::cout << "The Vector v is:" << std::endl;
	std::cout << v << std::endl;

	Vector u(3);
	u = A*v;
	std::cout << "u = A*v is:" << std::endl;
	std::cout << u << std::endl;


	std::cout << " ?????????? " << std::endl;
	
	exercise1();
	exercise2();

	return 0;
}



