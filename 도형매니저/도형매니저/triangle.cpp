#include <iostream>
#include "triangle.h"

Triangle::Triangle() : p1(), p2(), p3(), shapeType(ShapeType::TRIANGLE)
{
	std::cout << "Triangle »ý¼ºÀÚ È£Ãâ" << std::endl;
};

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : p1(a), p2(b), p3(c), shapeType(ShapeType::TRIANGLE)
{
};

Triangle::Triangle(const Triangle& other) : p1(other.p1), p2(other.p2), p3(other.p3)
{
}

Triangle::~Triangle()
{
	std::cout << "Triangle ¼Ò¸ê" << std::endl;
}

void Triangle::draw() const
{
	std::cout << "»ï°¢Çü- (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << "), (" << p3.x << "," << p3.y << ")" << std::endl;
};

ShapeType Triangle::getShapeType() const
{
	return shapeType;
}

std::ostream& operator<<(std::ostream& os, const Triangle& t)
{
	os << t.p1 << ' ' << t.p2 << ' ' << t.p3;
	return os;
}

std::istream& operator>>(std::istream& is, Triangle& t)
{
	Point p1, p2, p3;
	is >> p1 >> p2 >> p3;
	t.p1 = p1;
	t.p2 = p2;
	t.p3 = p3;
	return is;
}