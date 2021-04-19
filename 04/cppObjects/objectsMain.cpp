#include <iostream>
#include <memory>
#include <vector>

#include "Object.h"
#include "Derived.h"

int main(int argc, char *argv[]) {

    std::cout << "running objectsMain.cpp" << std::endl;
	
    // Object obj1; //default constructor
    // Object obj2(5);
    // Object obj3(obj1); //copy constructor
    // Object obj4 = 2; //constructor equivalant to obj4(2)
    // Object ref = obj3; //copy constructor equivalant to ref(obj3)
    
    // Object* ptr = new Object(); 
    // //^default constructor
    // std::unique_ptr<Object> ptr2 (new Object); //using smart pointer
    // obj3 = obj2;


    // Derived testing   
    // Derived d1;
    // Derived d2(d1);
    
    // std::cout<<"---"<<std::endl;
    // d2.setValue(5);
    // d1 = d2;
    // // d1 = 0 but d2 = 5 because 
    // std::cout << "Derived d1 has value: " << d1.getValue()<<std::endl;
    // std::cout << "Derived d2 has value: " << d2.getValue()<<std::endl;

    Object obj;
    Derived der;
    
    std::cout<<"---"<<std::endl;
    Object& ref = der;
    Object* ptr = new Derived();
    
    std::cout<<"---"<<std::endl;
    obj.whatAmI();
    der.whatAmI();
    ref.whatAmI();
    ptr->whatAmI();
    delete ptr;
    
    return 0;
}

