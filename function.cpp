#include <iostream>
#include "Date.hpp"

using namespace std;
using namespace ext;

const float PI = 3.14;

/*
������� �1
�������� �������, ������� ������� � ������� ���� ������ 10 ����������� �����.
�������� � ���������� ������ �������� n, ����� ��� �������� ���� n ������ ������ ����������� �����.*/
int cubes(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		cout << i * i * i << endl;
	}
	return 0;
}


/*������� �2
�������� �������, ������� ��������� ����� ��������.
�� ����������� ������ ���� ����� � ������, ������� �������� � ����������.*/
int V_cyllinder(int hight, int rad)
{
	float V = (PI*rad*rad)*hight;
	return V;
}


/*������� �3
�������� ������� min(a, b), ����������� ������� ���� �����.
����� �������� ������� min4(a, b, c, d), ����������� ������� 4 ����� � ������� ������� min.
�������� ������ ����� ����� �� ������� � �������� �� �������.
�������� ������				��������� ���������
1 2 3 4						1
4 3 2 1						1
9 5 1 7						1
7 3 5 9						3*/

int min(int a, int b)
{
	int minn = a > b ? b : a;
	return minn;
}

int min4(int a, int b, int c, int d)
{
	int minn;
	minn = min(min(a, b), min(c, d));
	return minn;
}


/*������� �4
�������� � ������ ���� Date.hpp
����������� ������� ������� ��������� � ����� Date.hpp
��� ���������� ������� ����� ������������ ���� ��������������� �������.
������������������ ������ ���� ���������� ������� � main().*/


int main()
{
	setlocale(LC_ALL, "");
	int N;
	cout << "������� N: ";
	cin >> N;
	cubes(N);
	int h, r;
	float V;
	cout << endl;
	cout << "������� ������: "; cin >> r;
	cout << "������� ������: "; cin >> h;
	V = V_cyllinder(h, r);
	cout << V << endl;
	cout << min4(5, 1, 4, 2);


}