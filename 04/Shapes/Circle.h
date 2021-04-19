#pragma once

#include "Shape.h"

class Circle: public Shape{ //inheritance of shape

    public:

        Circle(int cx,int cy,int radius,const Pixel& colour);
        Circle(const Circle& cir);
        ~Circle();

        Circle& operator=(const Circle& cir);
        void draw(Image& image) const;

    private:
        int cx_, cy_, radius_;
};