#ifndef _Point		// �� ���� include �� �� �ֵ��� ��
#define _Point		// ���Ǻ� ������ - ���۸� �� ��

struct Point {							// struct - ��� ����� public���� �Ҷ� ���
	double x, y;

	Point();							// ���� ������ ���� ����
	Point(double, double);				
	Point(const Point&) = default;		// ��������� - ����ڰ� ���� �ʿ� ���ٴ� �ǹ�
	friend std::ostream& operator<<(std::ostream&, const Point&);
	friend std::istream& operator>>(std::istream&, Point&);
};
#endif