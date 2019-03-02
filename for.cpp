﻿#include <iostream>
#include <limits>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	/*
	Задание 1
	Дано N (1 ≤ N ≤ 27).
	Найти количество трехзначных натуральных чисел, сумма цифр которых равна N.
	Тестовые данные				Ожидаемый результат
	1							1
	27							1
	5							15
	10							54
	20							36
	Задание 2
	Вы решили помочь Васе с разработкой его игры и взяли на себя красивый вывод сообщений в игре.
	Напишите программу, которая принимает на вход строку текста
	и затем печатает введенную строку на экран в рамочке из символов +, - и |.
	Для красоты текст должен отделяться от рамки слева и справа пробелом.
	Например, текст Hello world должен выводиться так:
	+-------------+
	| Hello world |
	+-------------+
	#include <string>
	int main()
	{
	std::string line;
	std::getline(std::cin, line); 	// считывает из консоли сразу целую строку и записываем ее в переменную line
	int size = line.size();		// функция возвращает длину строки
	}
	Задание 3
	Стали известны подробности про новую игру Васи.
	Оказывается ее действия разворачиваются на шахматных досках нестандартного размера.
	У Васи уже написан код, генерирующий стандартную шахматную доску размера 8х8.
	Помогите Васе переделать этот код так, чтобы он умел выводить доску любого заданного размера.
	Например, доска размера 5x5 должна выводиться так:
	#.#.#
	.#.#.
	#.#.#
	.#.#.
	#.#.#


	/*Задание 4
	Напишите программу, которая принимает у пользователя натуральное число N
	и выводит в консоль ромб со стороной N.
	Примеры:
	N = 1
	#
	N = 2
	#
	###
	#
	N = 4
	#
	###
	#####
	#######
	#####
	###
	#*/
	
	int N;
	cout << "введите N: "; cin >> N;
	for (int i = 1, j = 0; i < N; ++i)
	{
		
	}
	
	/*Задание 5 (дополнительно)
	Определите симметрично ли введенное пользователем число N
	Тестовые данные			Ожидаемый результат
	1				Да
	12				Нет
	565				Да
	1235321				Да
	12344321			Да
	456123				Нет
	*/


}



	



