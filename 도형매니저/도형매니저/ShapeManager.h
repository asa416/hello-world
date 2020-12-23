// Shape*(조상의 *)로 전체 도형을 관리하는 것이 핵심
#include "shape.h"

class ShapeManager {

	int nShape;				// 현재 보유한 도형의 갯수
	int capacity;			// 담을 수 있는 최대 도형의 갯수
	Shape** shapes;			// 도형의 포인터들을 담을 수 있는 메모리

public:

	explicit ShapeManager(int n);	// 담을 수 있는 도형의 갯수를 생성자에 전달
									// explicit 사용법을 구글링하여 익혀두자
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;
	ShapeManager& operator=(const ShapeManager&);

	void insert(Shape*);			// 도형을 추가하는 함수
	void deleteShape(int);
	void deleteAllShape(int);
	void draw() const;				// 전체 도형을 그리는 함수

	friend std::ostream& operator<<(std::ostream&, const ShapeManager&);
	friend std::istream& operator>>(std::istream&, ShapeManager&);
};