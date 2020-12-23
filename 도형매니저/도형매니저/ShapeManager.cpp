#include <iostream>
#include "ShapeManager.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
using namespace std;

//-------------------------
ShapeManager::ShapeManager(int n)
//-------------------------
{
	nShape = 0;							// 처음 만들어질 때는 관리하는 도형 갯수가 0임
	capacity = n;						// 최대 n개의 도형을 담을 수 있음
	shapes = new Shape * [capacity];
}

//-------------------------
ShapeManager::~ShapeManager()
//-------------------------
{
	// 모든 객체가 정확하게 삭제되는지 반드시 확인하여야 한다.
	for (int i = 0; i < nShape; ++i)
		delete shapes[i];
	delete[] shapes;					// 도형관리자가 관리하는 도형의 소멸자를 호출함
};

ShapeManager& ShapeManager::operator=(const ShapeManager& other)
{
	nShape = other.nShape;
	for (int i = 0; i < nShape; ++i)
		shapes[i] = other.shapes[i];
	return *this;
}

//-------------------------
void ShapeManager::insert(Shape* a)
//-------------------------
{
	if (nShape >= capacity) {
		capacity *= 2;
		std::cout << capacity << std::endl;
		ShapeManager s(capacity);
		for (int i = 0; i < nShape; ++i)
			s.shapes[i] = shapes[i];
		delete[] shapes;
		shapes = new Shape * [capacity];
		for (int i = 0; i < nShape; ++i)
			shapes[i] = s.shapes[i];
	}
	shapes[nShape] = a;
	nShape++;
};

void ShapeManager::deleteShape(int n)
{
	if (n == nShape - 1) {
		shapes[n]->~Shape();
		--nShape;
		return;
	}
	shapes[n]->~Shape();
	for (int i = n; i < nShape - 1; ++i)
		shapes[i] = shapes[i + 1];
	shapes[--nShape] = nullptr;
}

void ShapeManager::deleteAllShape(int n)
{
	switch (n)
	{
		case 1:
		{
			int i = 0;
			while (i < nShape) {
				if (dynamic_cast<Triangle*>(shapes[i]) != nullptr) {
					shapes[i]->~Shape();
					nShape -= 1;
					for (int j = i; j < nShape; ++j) {
						shapes[j] = shapes[j + 1];
					}
					if (dynamic_cast<Triangle*>(shapes[i]) != nullptr)
						i--;
				}
				++i;
			}
			break;
		}
		case 2:
		{
			int i = 0;
			while (i < nShape) {
				if (dynamic_cast<Rectangle*>(shapes[i]) != nullptr) {
					shapes[i]->~Shape();
					nShape -= 1;
					for (int j = i; j < nShape; ++j) {
						shapes[j] = shapes[j + 1];
					}
					if (dynamic_cast<Rectangle*>(shapes[i]) != nullptr)
						i--;
				}
				++i;
			}
			break;
		}
		case 3:
		{
			int i = 0;
			while (i < nShape) {
				if (dynamic_cast<Circle*>(shapes[i]) != nullptr) {
					shapes[i]->~Shape();
					nShape -= 1;
					for (int j = i; j < nShape; ++j) {
						shapes[j] = shapes[j + 1];
					}
					if (dynamic_cast<Circle*>(shapes[i]) != nullptr)
						i--;
				}
				++i;
			}
			break;
		}
		default:
			std::cout << "error" << std::endl;
			break;
	}
}

//-------------------------
void ShapeManager::draw() const
//-------------------------
{
	cout << "------------------------------------------" << endl;
	cout << "관리하는 모든 도형을 그립니다" << endl;
	cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << endl;
	cout << "모두 " << nShape << "개의 도형이 있습니다" << endl;
	cout << "------------------------------------------" << endl;

	for (int i = 0; i < nShape; ++i) {
		cout << "[" << i << "] ";
		shapes[i]->draw();				// 여기에서 다형성이 구현된다.
	}
	cout << endl;

	cout << "------------------------------------------" << endl;
	cout << "그리기를 마칩니다" << endl;
	cout << "------------------------------------------" << endl << endl;
};

ostream& operator<<(ostream& os, const ShapeManager& sm)
{
	os << sm.nShape << std::endl;
	for (int i = 0; i < sm.nShape; ++i) {
		if(sm.shapes[i]->getShapeType() == ShapeType::TRIANGLE) {
			Triangle* p = dynamic_cast<Triangle*>(sm.shapes[i]);
			os << 0 << ' ' << *p << endl;
		}
		else if (sm.shapes[i]->getShapeType() == ShapeType::RECTANGLE) {
			Rectangle* p = dynamic_cast<Rectangle*>(sm.shapes[i]);
			os << 1 << ' ' << *p << endl;
		}
		else {
			Circle* p = dynamic_cast<Circle*>(sm.shapes[i]);
			os << 2 << ' ' << *p << endl;
		}
	}
	return os;
}

istream& operator>>(istream& is, ShapeManager& sm)
{
	int num;
	is >> num;
	int t;
	if (sm.nShape + num >= sm.capacity) {
		sm.capacity *= 2;
		ShapeManager s(sm.capacity);
		for (int i = 0; i < sm.nShape; ++i)
			s.shapes[i] = sm.shapes[i];
		delete[] sm.shapes;
		sm.shapes = new Shape * [sm.capacity];
		for (int i = 0; i < sm.nShape; ++i)
			sm.shapes[i] = s.shapes[i];
	}
	for (int i = 0; i < num; ++i) {
		is >> t;
		if (t == 0) {
			sm.shapes[sm.nShape + i] = new Triangle;
			Triangle* p = dynamic_cast<Triangle*>(sm.shapes[sm.nShape + i]);
			is >> *p;
		}
		else if (t == 1) {
			sm.shapes[sm.nShape + i] = new Rectangle;
			Rectangle* p = dynamic_cast<Rectangle*>(sm.shapes[sm.nShape + i]);
			is >> *p;
		}
		else {
			sm.shapes[sm.nShape + i] = new Circle;
			Circle* p = dynamic_cast<Circle*>(sm.shapes[sm.nShape + i]);
			is >> *p;
		}
	}
	sm.nShape += num;
	return is;
}




//for (int i = 0; i < nShape; ++i) {
//	if (dynamic_cast<Triangle*>(shapes[i]) != nullptr)
//		shapes[i]->~Shape();
//	++cnt;
