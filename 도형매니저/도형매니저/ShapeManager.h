// Shape*(������ *)�� ��ü ������ �����ϴ� ���� �ٽ�
#include "shape.h"

class ShapeManager {

	int nShape;				// ���� ������ ������ ����
	int capacity;			// ���� �� �ִ� �ִ� ������ ����
	Shape** shapes;			// ������ �����͵��� ���� �� �ִ� �޸�

public:

	explicit ShapeManager(int n);	// ���� �� �ִ� ������ ������ �����ڿ� ����
									// explicit ������ ���۸��Ͽ� ��������
	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;
	ShapeManager& operator=(const ShapeManager&);

	void insert(Shape*);			// ������ �߰��ϴ� �Լ�
	void deleteShape(int);
	void deleteAllShape(int);
	void draw() const;				// ��ü ������ �׸��� �Լ�

	friend std::ostream& operator<<(std::ostream&, const ShapeManager&);
	friend std::istream& operator>>(std::istream&, ShapeManager&);
};