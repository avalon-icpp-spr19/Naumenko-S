#include <iostream>
#include "Date.hpp"

using namespace std;
using namespace ext;

const float PI = 3.14;

/*
Задание №1
Написать функцию, которая выводит в консоль кубы первых 10 натуральных чисел.
Довавьте в написанную функию параметр n, чтобы она выводила кубы n первых первых натуральных чисел.*/
int cubes(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		cout << i * i * i << endl;
	}
	return 0;
}


/*Задание №2
Напишите функцию, которая вычисляет объем цилиндра.
Ее параметрами должны быть радус и высота, которые вводятся с клавиатуры.*/
int V_cyllinder(int hight, int rad)
{
	float V = (PI*rad*rad)*hight;
	return V;
}


/*Задание №3
Напишите функцию min(a, b), вычисляющую минимум двух чисел.
Затем напишите функцию min4(a, b, c, d), вычисляющую минимум 4 чисел с помощью функции min.
Считайте четыре целых числа из консоли и выведите их минимум.
Тестовые данные				Ожидаемый результат
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


/*Задание №4
Добавить в проект файл Date.hpp
Реализовать функции которые объявлены в файле Date.hpp
При выполнении задания можно использовать свои вспомогательные функции.
Продемонстрировать работы всех написанных функций в main().*/


int main()
{
	setlocale(LC_ALL, "");
	int N;
	cout << "Введите N: ";
	cin >> N;
	cubes(N);
	int h, r;
	float V;
	cout << endl;
	cout << "Введите радиус: "; cin >> r;
	cout << "Введите высоту: "; cin >> h;
	V = V_cyllinder(h, r);
	cout << V << endl;
	cout << min4(5, 1, 4, 2);


}