#include "point.h"							// point를 Triangle에서 사용
#include "shape.h"							// Shape를 상속 받음

class Triangle : public Shape
{
	ShapeType shapeType = ShapeType::TRIANGLE;
	Point p1, p2, p3;

public:

	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	virtual void draw() const override;		// 가상함수 overriding
	friend std::ostream& operator<<(std::ostream&, const Triangle&);
	friend std::istream& operator>>(std::istream&, Triangle&);
	virtual ShapeType getShapeType() const override;
};
