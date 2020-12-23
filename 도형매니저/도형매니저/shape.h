#ifndef _Shape							// _Shape이 앞에서 정의되지 않았다면
#define _Shape							// _Shape을 정의한다
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