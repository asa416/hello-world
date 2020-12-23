#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle() : p1(), p2(), shapeType(ShapeType::RECTANGLE)
{
	std::cout << "Rectangle 생성자 호출" << std::endl;
}

Rectangle::Rectangle(const Point& a, const Point& b) : p1(a), p2(b), shapeType(ShapeType::RECTANGLE)
{
};

Rectangle::Rectangle(const Rectangle& other) : p1(other.p1), p2(other.p2)
{
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle 소멸" << std::endl;
}

void Rectangle::draw() const
{
	std::cout << "사각형 - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << ")" << std::endl;
}

ShapeType Rectangle::getShapeType() const
{
	return shapeType;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
	os << r.p1 << ' ' << r.p2;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& r)
{
	Point p1, p2;
	is >> p1 >> p2;
	r.p1 = p1;
	r.p2 = p2;
	return is;
}
