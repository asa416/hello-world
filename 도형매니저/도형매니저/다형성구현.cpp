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
	// 이 프로그램은 프로젝트를 확인하기 위한 것이다.
	// 실습 순서대로 문제를 해결해 보자.
	//--------------------------------------------

	ShapeManager sm(100);

	while (true) {
		int n = menu();
		switch (n)
		{
		case 1:
			sm.insert(new Triangle);
			std::cout << "삼각형 생성" << std::endl << std::endl;
			break;
		case 2:
			sm.insert(new Rectangle);
			std::cout << "사각형 생성" << std::endl << std::endl;
			break;
		case 3:
			sm.insert(new Circle);
			std::cout << "원 생성" << std::endl << std::endl;
			break;
		case 4:
			sm.draw();
			break;
		case 5:
		{
			int num = 0;
			std::cout << "몇 번째 도형을 제거할까요? ";
			std::cin >> num;
			sm.deleteShape(num);
			std::cout << std::endl;
			break;
		}
		case 6:
		{
			int num;
			std::cout << "어떤 도형을 제거할까요? 삼각형1 사각형2 원3 : ";
			std::cin >> num;
			sm.deleteAllShape(num);
			std::cout << std::endl;
			break;
		}
		case 7:
		{
			std::ofstream out("도형관리");
			out << sm;
			std::cout << "파일에 저장 완료" << std::endl;
			break;
		}
		case 8:
		{
			std::ifstream in("도형관리");
			in >> sm;
			std::cout << "파일 읽어오기 완료\n";
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
	std::cout << "- 원하는 도형 추가\n";
	std::cout << "	- 삼각형 (1)\n";
	std::cout << "	- 사각형 (2)\n";
	std::cout << "	- 원 (3)\n";
	std::cout << "- 전체 도형을 그리기 (4)\n";
	std::cout << "- 선택한 번호 도형 삭제 (5)\n";
	std::cout << "- 선택 도형 전부 삭제 (6)\n";
	std::cout << "- 파일에 저장하기 (7)\n";
	std::cout << "- 파일에서 읽어오기 (8)\n";
	std::cout << "- 프로그램 끝내기(9)\n";
	int n;
	std::cout << "원하시는 행동을 입력해주세요 ";
	std::cin >> n;
	return n;
}

	
