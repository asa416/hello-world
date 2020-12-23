#include <iostream>
#include "circle.h"

Circle::Circle() : center(), rad(0.0), shapeType(ShapeType::CIRCLE)
{
	std::cout << "circle ������ ȣ��" << std::endl;
}

Circle::Circle(const Point& c, double r) : center(c), rad(r), shapeType(ShapeType::CIRCLE)
{
}

// ��������ڸ� ���α׷��� ������ �ִٸ� ��������� ���� �����ؾ��Ѵ�.
// ��������ڸ� ���α׷��ϸ鼭 �ƹ��͵� ���� ������ ��������� ������� �ʴ´�.

Circle::Circle(const Circle& other) : center(other.center), rad(other.rad)
{
}

Circle::~Circle() 
{
	std::cout << "Circle �Ҹ�" << std::endl;
}

void Circle::draw() const
{
	// �׸��� �׸��� ��� ������ ���ڷ� ����Ѵ�
	std::cout << "�� - �߽���(" << center.x << "," << center.y << ") ������ " << rad << std::endl;
}

ShapeType Circle::getShapeType() const
{
	return shapeType;
}

std::ostream& operator<<(std::ostream& os, const Circle& c)
{
	os << c.center << ' ' << c.rad;
	return os;
}

std::istream& operator>>(std::istream& is, Circle& c)
{
	Point p;
	double r;
	is >> p >> r;
	c.center = p;
	c.rad = r;
	return is;
}
