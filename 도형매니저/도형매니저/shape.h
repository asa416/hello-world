#ifndef _Shape							// _Shape�� �տ��� ���ǵ��� �ʾҴٸ�
#define _Shape							// _Shape�� �����Ѵ�
#include "point.h"

enum class ShapeType
{
	TRIANGLE,
	RECTANGLE,
	CIRCLE
};

class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};
	

	virtual void draw() const = 0;		// pure virtual function
	virtual ShapeType getShapeType() const = 0;
};
#endif