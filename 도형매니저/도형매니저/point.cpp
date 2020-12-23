/* CPP�� ������ �����ϵ� ����(obj)�� ����� �� �ִ�.
   - �ٸ� ����ڿ��� ���� �ҽ��� ���� �� �ִ�.      */
#include <iostream>
#include "point.h"

// Ŭ���� �ۿ��� ����� �����ϴ� ������ ���캸��

// ����Ʈ ������
Point::Point() : x(0.0), y(0.0) {};

// ���� �� ���� �޴� ������
Point::Point(double a, double b) : x(a), y(b) {};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << p.x << ' ' << p.y;
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    double x, y;
    is >> x >> y;
    p.x = x;
    p.y = y;
    return is;
}