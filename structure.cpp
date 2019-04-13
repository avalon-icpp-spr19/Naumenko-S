#include <iostream>
#include <cmath>
#include "Extention.hpp"

using namespace std;
using namespace ext;

enum Color
{
	red,
	orange,
	yellow,
	green,
	lightblue,
	blue,
	violet
};
struct Date
{
	int day; 
	int month; 
	int year;
};
struct Point
{
	float x;
	float y;
};
struct Triangle
{
	int st[3];
	Color col;
};

int main()
{
	setlocale(LC_ALL, "rus");
	/*	������� �1
	������� ��������� Point, ���������� ��� ���� x, y ���� float.
	������� � ������������������� ���������� ���� Point.
	������� ���������� ���� Point � ������������������� �� ������� � ����������.
	������� �� ����� �������� x, y ��������������� ����������.
	�������� ���������, ������� ����������� ����������� �� �������� ����� ����� ��������� �������.
	���������� ����� � ������ ������������ ������ � ����������.
	��� �������� ��������� ����� ������������ ��������� Point.*/	
	Point koor;
	float rad;
	cout << "������� ����������: ";
	cin >> koor.x >> koor.y;
	cout << "A (" << koor.x << "; " << koor.y << ")" << endl;
	cout << "������� ������ �����: "; cin >> rad;
	if (koor.x*koor.x + koor.y*koor.y <+ rad*rad)
	{
		cout << "����� ����������� �����" << endl;
	}
	else
	{
		cout << "����� �� ����������� �����" << endl;
	}
	/*�������� ���������, ������� �� ���� �������� ������ - ������ ������� ������� ����� �������� �������.
	���������� ����� ������������ ������ � ����������.
	��� �������� ��������� ����� ������������ ��������� Point.
	������������ ����� �������� ������� ����� ������� ��� ��������� Point.
	������� ���������� ���������� ����� � �������.*/
	Point A, B, C;
	cout << "������� ���������� ����� A: ";
	cin >> A.x >> A.y;
	cout << "������� ���������� ����� B: ";
	cin >> B.x >> B.y;
	C.x = (B.x + A.x) / 2;
	C.y = (B.y + A.y) / 2;
	cout << "�������� �������: C (" << C.x << "; " << C.y << ")" << endl;

	/*������� �2
	������� ��������� Circle, ���������� ���� ���� ���� int - ������ � ������ ���� ���� Point - ����� ����������.
	������� � ������������������� ���������� ���� Circle.
	������� ���������� ���� Circle � ������������������� �� ������� ���������� � ����������.
	������� �� ����� ������, ����������� � ��������������� ����������.
	���� ��� ���������� ���� Circle.
	�������� ���������, ������� ���������� ������������ �� ����������,
	��������� ������� �����������.*/



	/*������� �3
	������� ������������ (enum) Color, ��� �������� 7 ������ ������.
	������� ��������� Triangle, ���������� ���� ���� Color
	� ������ ��� �������� ���� ��������� ���� int (����� ������).
	������� � ������������������� ���������� ���� Triangle ����������� �������.
	������� �� ����� ������, ����������� � ��������������� ����������.
	�������� ���� Color ������� � ��������� ����. (������������ ����������� switch).
	���������� � ������� �� ����� �������� ���������������� ������������.*/

	/*������� �4
	������� ������ �� 20 ��������� ���� Point.
	������������������� ��� ������� �� ���������� ���������� ��������� � �������� �� 0 �� 100.
	�������� �� ����� ����������:
	- ����� � ���������� x �����������
	- ���� �����, ���������� ����� �������� ����������.*/


	/*������� �5
	������� ������ �� 100 ��������� ���� Triangle.
	������������������� ��� ���������� ���������� (����� ������� �� 1 �� 10).
	��� ������������� ���������, ��� ����������� � ������ ������� ������ ����� ������������.
	(����� ������ ������� ������ ���� ������ ������ ���� ����� ���� ������ ������).*/
	Triangle arr[100];
	bool tr = false;
	for (int i = 0; i < 100; i++)
	{		
		while (!tr)
		{		
			arr[i].st[0] = GetRandomValue(1, 10);
			arr[i].st[1] = GetRandomValue(1, 10);
			arr[i].st[2] = GetRandomValue(1, 10);
			tr = (arr[i].st[0] + arr[i].st[1] > arr[i].st[2]) && (arr[i].st[1] + arr[i].st[2] > arr[i].st[0]) && 
				(arr[i].st[0] + arr[i].st[2] > arr[i].st[1]);
		}
	}	
	/*���������� ���������� ������ ������������� � ������� �� ����� ��������� ����������:
	- ������� �� ����� ��� ������������, �������� ������� ��������� ��������, ��������� � ����������.
	���� ���������� ������������� ���, ������� ��������������� ���������.
	- ���������� ������������� ������� �����*/	

	/*������� �6
	�������� ���������, ������� ��������� ������������ �������� �������� ����.
	���� ������� � �������������� ���������.
	�������� ������				��������� ���������
	1 1 1992					���� ���������
	30 6 1992					���� ���������
	31 7 1992					���� ���������
	31 9 1994					���� �����������
	32 1 1992					���� �����������
	1 13 1992					���� �����������
	29 2 1993					���� �����������
	29 2 2004					���� ���������
	29 2 1900					���� �����������
	29 2 2000					���� ���������*/
	Date date;
	bool hight_year;
	cin >> date.day >> date.month >> date.year;
	hight_year = ((date.year % 400 == 0) || (date.year % 100 != 0 && date.year % 4 == 0));
	if (date.day < 32 && date.day > 0 && date.year > 0)
	{
		switch (date.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << "���� ��������" << endl;
			break;
		case 2:
			if ((date.day < 30 && hight_year) || (date.day < 29 && !hight_year)) 
			{
				cout << "���� ��������" << endl;
			}
			else
			{
				cout << "���� ����������" << endl;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date.day < 31)
			{
				cout << "���� ��������" << endl;
			}
			else
			{
				cout << "���� ����������" << endl;
			}
			break;
		default:
			cout << "���� ����������" << endl;
			break;
		}
	}
	else
	{
		cout << "���� ����������" << endl;
	}	
}