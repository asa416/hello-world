#include "point.h"
#include "shape.h"

class Rectangle : public Shape
{
	ShapeType shapeType;
	Point p1, p2;

public:

	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();

	virtual void draw() const override;
	friend std::ostream& operator<<(std::ostream&, const Rectangle&);
	friend std::istream& operator>>(std::istream&, Rectangle&);
	virtual ShapeType getShapeType() const override;

};