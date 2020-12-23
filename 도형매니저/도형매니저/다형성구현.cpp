#include <iostream>
#include <fstream>
#include "point.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "ShapeManager.h"

int menu();

//--------
int main()
//--------
{
	//--------------------------------------------
	// �� ���α׷��� ������Ʈ�� Ȯ���ϱ� ���� ���̴�.
	// �ǽ� ������� ������ �ذ��� ����.
	//--------------------------------------------

	ShapeManager sm(100);

	while (true) {
		int n = menu();
		switch (n)
		{
		case 1:
			sm.insert(new Triangle);
			std::cout << "�ﰢ�� ����" << std::endl << std::endl;
			break;
		case 2:
			sm.insert(new Rectangle);
			std::cout << "�簢�� ����" << std::endl << std::endl;
			break;
		case 3:
			sm.insert(new Circle);
			std::cout << "�� ����" << std::endl << std::endl;
			break;
		case 4:
			sm.draw();
			break;
		case 5:
		{
			int num = 0;
			std::cout << "�� ��° ������ �����ұ��? ";
			std::cin >> num;
			sm.deleteShape(num);
			std::cout << std::endl;
			break;
		}
		case 6:
		{
			int num;
			std::cout << "� ������ �����ұ��? �ﰢ��1 �簢��2 ��3 : ";
			std::cin >> num;
			sm.deleteAllShape(num);
			std::cout << std::endl;
			break;
		}
		case 7:
		{
			std::ofstream out("��������");
			out << sm;
			std::cout << "���Ͽ� ���� �Ϸ�" << std::endl;
			break;
		}
		case 8:
		{
			std::ifstream in("��������");
			in >> sm;
			std::cout << "���� �о���� �Ϸ�\n";
			break;
		}
		case 9:
			return 0;
		default:
			break;
		}
	}

}

int menu()
{
	std::cout << "	Menu	\n";
	std::cout << "- ���ϴ� ���� �߰�\n";
	std::cout << "	- �ﰢ�� (1)\n";
	std::cout << "	- �簢�� (2)\n";
	std::cout << "	- �� (3)\n";
	std::cout << "- ��ü ������ �׸��� (4)\n";
	std::cout << "- ������ ��ȣ ���� ���� (5)\n";
	std::cout << "- ���� ���� ���� ���� (6)\n";
	std::cout << "- ���Ͽ� �����ϱ� (7)\n";
	std::cout << "- ���Ͽ��� �о���� (8)\n";
	std::cout << "- ���α׷� ������(9)\n";
	int n;
	std::cout << "���Ͻô� �ൿ�� �Է����ּ��� ";
	std::cin >> n;
	return n;
}

	
