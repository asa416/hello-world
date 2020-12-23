#include <iostream>
#include "Line.h"

Line::Line() : p1(), p2()
{
	std::cout << "Line ����" << std::endl;
}

Line::Line(const Point& a, const Point& b) : p1(a), p2(b)
{
	std::cout << "Line ����" << std::endl;
}

Line::Line(const Line& other) : p1(other.p1), p2(other.p2)
{
}

Line::~Line()
{
	std::cout << "Line �Ҹ�" << std::endl;
}

void Line::draw() const
{
	std::cout << "�� - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << ")" << std::endl;
}
