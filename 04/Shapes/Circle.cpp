#include "Circle.h"
#include <algorithm>
#include <iostream>
#include <math.h>

Circle::Circle(int cx,int cy,int radius,const Pixel& colour):
Shape(colour),cx_(cx), cy_(cy),radius_(radius){

}

Circle::Circle(const Circle& cir):
Shape(cir), cx_(cir.cx_), cy_(cir.cy_), radius_(cir.radius_){
}

Circle::~Circle() {

}

Circle& Circle::operator=(const Circle& cir){
    if(this != &cir){ // not the same object?
        Circle::operator=(cir);
        cx_ = cir.cx_;
        cy_ = cir.cy_;
        radius_ = cir.radius_;
    }
    return *this;
}

void Circle::draw(Image& image) const{
    //centre is at (cx, cy), radius is r, colour is c
    // for dy = -r to r:
    //     xrange = sqrt(r*r - dy*dy)
    //     for dx = -xrange to xrange:
    //     image(cx+dx,cy+dy) = 
    int r = radius_;
    int cx = cx_;
    int cy = cy_;
    
    for (int dy = -r; dy<r; ++dy){
        int xrange = sqrt(r*r - dy*dy);
        for (int dx = -xrange; dx<xrange; ++dx){
            image(cx+dx,cy+dy) = colour_;
        }
    }
}