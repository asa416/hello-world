#include "point.h"
#include "shape.h"

// ���� �� include ��ſ� ������ ���� ���漱��(forward declaration)�� �� ���� �ִ�
// struct Point;
// class Shape;

class Circle : public Shape {
	Point center;	// �߽����� ��ǥ
	double rad;		// ������
	ShapeType shapeType;

public:
	Circle();
	Circle(const Point&, double);
	Circle(const Circle&);		// ���� ���縦 �� ���� ���ٸ� ���� ��������ڸ� ���α׷��� �ʿ�� ����.
								// ���� ���α׷��Ѵٸ� �޸𸮰� �״�� ����ǵ��� �ؾ��Ѵ�.

	// �� ������ ���� �ٰ� ���� �����Ͽ� ��ġ�� �� �ִ�
	// Circle( const Circle& ) = default;

	~Circle();					// �Ҹ��ڵ� ���α׷��� �ʿ䰡 ���ٴ� ���� ������ ����

	virtual void draw() const override;
	friend std::ostream& operator<<(std::ostream&, const Circle&);
	friend std::istream& operator>>(std::istream&, Circle&);
	virtual ShapeType getShapeType() const override;
};
