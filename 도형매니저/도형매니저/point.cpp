/* CPP의 내용은 컴파일된 형태(obj)로 사용할 수 있다.
   - 다른 사용자에게 구현 소스를 감출 수 있다.      */
#include <iostream>
#include "point.h"

// 클래스 밖에서 멤버를 정의하는 문법을 살펴보자

// 디폴트 생성자
Point::Point() : x(0.0), y(0.0) {};

// 인자 두 개를 받는 생성자
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