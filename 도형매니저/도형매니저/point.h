#ifndef _Point		// 한 번만 include 할 수 있도록 함
#define _Point		// 조건부 컴파일 - 구글링 할 것

struct Point {							// struct - 모든 멤버를 public으로 할때 사용
	double x, y;

	Point();							// 문법 연습을 위해 적음
	Point(double, double);				
	Point(const Point&) = default;		// 복사생성자 - 사용자가 만들 필요 없다는 의미
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::istream& operator>>(std::istream&, Point&);
};
#endif