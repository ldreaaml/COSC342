#pragma once


class Object {
public:
	
	Object();
	Object(int value);
	Object(const Object& obj);
	virtual ~Object(); 
	// use virtual so it knows which methods should be
	// referred to derived class

	Object& operator=(const Object& obj);

	int getValue() const;
	void setValue(int newValue);

	virtual void whatAmI() const;


protected:
	int id_;
	int value_;

private:
	static int objectCount_;

};
