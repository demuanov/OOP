#include "Base.h"
#include"sstream"
#include "Container.h"
#include <vector>

const double PI = 3.1;

template <typename T>
std::string ToString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

class Point : public Shape, public Named
{
public:
	Point() :Shape(), Named("") {};

	Point(std::string const name, double x, double y) : Shape(), Named(name) {
		cord_x = x;
		cord_y = y;
		options= "Point " + this->getname() + " coordinates:(" + ToString(cord_x) + "," + ToString(cord_y) + ")\n";
	};

	Point(const Point & point) : Shape(), Named(point.name) {
		cord_x = point.cord_x;
		cord_y = point.cord_y;
		options = "Point " + point.name + " coordinates:(" + ToString(cord_x) + "," + ToString(cord_y) + ")\n";
	};

	double getx() { return cord_x; };

	double gety() { return cord_y; };

	static double distance(const Point & x, const Point & y) {
		return fabs(pow((pow(x.cord_x - y.cord_x, 2) + pow((x.cord_y - y.cord_y), 2)), 0.5));
	}

	~Point() {};

private:
	double cord_x;
	double cord_y;
};

class Circle : public Shape, public Named {
public:
	Circle() :Shape(), Named("") {};

	Circle(std::string const name, Point point, double r) :Shape(), Named(name) 
	{
		center = new Point(point);
		radius = abs(r);
		options = "Circle " + this->getname() + " center:" + point.getoptions() + "radius: " + ToString(radius) + " \nand area = " + ToString(radius*radius*PI) + "\n";
	}

	~Circle()
	{
		delete center;
	}

private:
	Point* center;
	double radius;
};

class Rectangle : public Shape, Named 
{
public:
	Rectangle() :Shape(), Named("") {};

	Rectangle(std::string const name, std::string type, Point x1, Point x2, Point x3, Point x4) :Shape(), Named(name) 
	{
		
		cord_x1 = new Point(x1);
		cord_x2 = new Point(x2);
		cord_x3 = new Point(x3);
		cord_x4 = new Point(x4);
		options = type + " named " + this->getname() + "with points: \n" + cord_x1->getoptions() + cord_x2->getoptions() + cord_x3->getoptions() + cord_x4->getoptions() + "and area: " + ToString(this->arearect()) + "\n";
	}

	~Rectangle()
	{
		delete cord_x1;
		delete cord_x2;
		delete cord_x3;
		delete cord_x4;
	}

	virtual double  arearect() 
	{
		return Point::distance(*cord_x1, *cord_x2) * Point::distance(*cord_x2, *cord_x3);
	}

protected:
	Point* cord_x1;
	Point* cord_x2;
	Point* cord_x3;
	Point* cord_x4;
};

class Square : public Rectangle
{
public:
	Square() : Rectangle() {};

	Square(std::string const name, Point x1, Point x2, Point x3, Point x4) : Rectangle(name, "Square", x1, x2, x3, x4) 
	{ 
		if (round(abs(x1.getx() - x3.getx()) * 10000) / 10000 != round(abs(x1.gety() - x3.gety()) * 10000) / 10000) throw "Doesn't square!";
	};

};

class Rect : public Rectangle
{
public:
	Rect() : Rectangle() {};

	Rect(std::string const name, Point x1, Point x2)
	{
		
			if (x1.getx() == x2.getx() || x1.gety() == x2.gety()) throw "Similarity points!! Unable to create Rectangle";
			cord_x1 = new Point(x1);
			cord_x2 = new Point(cord_x1->getname(), cord_x1->getx(), x2.gety());
			cord_x3 = new Point(x2);
			cord_x4 = new Point(cord_x2->getname(), cord_x2->getx(), cord_x1->gety());
			options = name + "with points: \n" + cord_x1->getoptions() + cord_x2->getoptions() + cord_x3->getoptions() + cord_x4->getoptions() + "and area: " + ToString(this->arearect()) + "\n";
		
	};
	};


class Polyline : public Shape, public Named 
{
public:
	Polyline() : Shape(), Named("") {};

	Polyline(std::string name) : Shape(), Named(name) {};

	void AddPoint(const Point &point) 
	{
		if (points.getsize() >= 1) {
			length += Point::distance(point, points.get_last());
		}
		options = this->name + " length: " + ToString(length) + "\n";
		points.add_last(point);
	};

	double getlength() 
	{
		return length;
	}

	~Polyline() { }

private:
	Container< Point > points;
	double length = 0;
};

class Polygon : public Shape, public Named
{
public:
	Polygon() : Shape(), Named("") {};

	Polygon(std::string name) :Shape(), Named(name) {};

	void AddPoint(const Point & point)
	{
		if (points.getsize() >= 1) 
		{
			length += point.distance(point, points.get_last());
			points.del_first();
			points.add_first(point);
			points.add_last(point);
		}
		else
		{
			points.add_last(point);
		}
		options = this->name + " with length: " + ToString(length) + "\n";
	}

	double getlength() 
	{
		return length;
	}
private:
	Container< Point > points;
	double length = 0;

};