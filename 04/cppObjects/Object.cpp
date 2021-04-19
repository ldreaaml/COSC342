#include "Object.h"

#include <iostream>

int Object::objectCount_ = 0; //static variable

//id and value are protected variable
Object::Object() : id_(++objectCount_), value_(0) {
	std::cout << "Object " << id_ << " created with Default Constructor" << std::endl;
}

Object::Object(int value) : id_(++objectCount_), value_(value) {
	std::cout << "Object " << id_ << " created with Constructor initialising its value to " << value_ << std::endl;
}

Object::Object(const Object& obj) : id_(++objectCount_), value_(obj.value_) {
	std::cout << "Object " << id_ << " created with Copy Constructor from Object " << obj.id_ << " with value " << value_ << std::endl;
}

Object::~Object() {
	std::cout << "Object " << id_ << " Destroyed" << std::endl;
}

//assignment operator
Object& Object::operator=(const Object& obj) {
	if (this != &obj) { //this refer to current object (is a pointer so have to use -> if need to access member)
		std::cout << "Assigning Object " << obj.id_ << " to Object " << id_ << ", giving it a new value of " << obj.value_ << std::endl;
		value_ = obj.value_;
	} else {
		std::cout << "Assigning Object " << id_ << " to itself doesn't do anything" << std::endl;
	}
	return *this;
}

int Object::getValue() const {
	return value_;
}

void Object::whatAmI() const {
	std::cout << "I am an Object" << std::endl;
}

void Object::setValue(int newValue) {
	value_ = newValue;
}
