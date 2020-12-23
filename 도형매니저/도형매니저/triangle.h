#include "point.h"							// point�� Triangle���� ���
#include "shape.h"							// Shape�� ��� ����

class Triangle : public Shape
{
	ShapeType shapeType = ShapeType::TRIANGLE;
	Point p1, p2, p3;

public:

	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	virtual void draw() const override;		// �����Լ� overriding
	friend std::ostream& operator<<(std::ostream&, const Triangle&);
	friend std::istream& operator>>(std::istream&, Triangle&);
	virtual ShapeType getShapeType() const override;
};
