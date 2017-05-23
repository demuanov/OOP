#pragma once
#include <iostream>
#include <string>
class Printable {
public:
	Printable() {};

	friend std::ostream & operator << (std::ostream & out, Printable & printable) 
	{
		out << printable.options;
		return out;
	}
	std::string getoptions() 
	{
		return options;
	}

	virtual ~Printable() {};
protected:
	std::string options;
};

class Named : virtual public Printable 
{
public:
	Named(std::string const in) : Printable() 
	{
		this->name = in;
	};

	void print(std::ostream & out) 
	{
		out << this->getname();
	}

	std::string const & getname() const 
	{
		return name;
	}

protected:
	std::string name;

};

class Shape : virtual public Printable 
{
public:
	Shape() 
	{
		count++;
	}
	
	Shape(const Shape &shape) 
	{
		options = shape.options;
		count++;
	};

	virtual ~Shape() 
	{
		count--;
	}

	static int getcount() 
	{
		std::cout << "getcount->" << count << std::endl;
		return count;
	}

	
protected:
	static int count;

};

int Shape::count = 0;